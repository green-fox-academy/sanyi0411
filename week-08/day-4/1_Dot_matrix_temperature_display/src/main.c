#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* 7 bit address of an I2C sensor shifted to left 1 bit, leaving place for W/R bit,
 * which is inserted by the HAL_I2C_Master_Transmit and HAL_I2C_Master_Receive */
#define TEMP_SENSOR_ADDRESS (0b1001000 << 1)
#define	HT16K33_ADDRESS	(0b1110000 << 1)

TIM_HandleTypeDef timer_handle;

I2C_HandleTypeDef I2C_handle;            // defining the I2C configuration structure

GPIO_InitTypeDef SCL_SDA_config;           // configure GPIOs for I2C data and clock lines

uint8_t system_setup_reg = 0x21;
uint8_t set_reg = 0xA0;
uint8_t display_set_reg = 0x81;

//Digits generated: 8px by 8px, row major, little endian.
uint8_t digits[11][8] = {
		{ 0x0e, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x0e },	//0
		{ 0x04, 0x06, 0x04, 0x04, 0x04, 0x04, 0x04, 0x0e },	//1
		{ 0x0e, 0x11, 0x10, 0x10, 0x08, 0x04, 0x02, 0x1f },	//2
		{ 0x0e, 0x11, 0x10, 0x0c, 0x10, 0x10, 0x11, 0x0e },	//3
		{ 0x10, 0x18, 0x14, 0x12, 0x11, 0x1f, 0x10, 0x10 },	//4
		{ 0x1f, 0x01, 0x01, 0x0f, 0x10, 0x10, 0x11, 0x0e },	//5
		{ 0x0e, 0x11, 0x01, 0x0f, 0x11, 0x11, 0x11, 0x0e },	//6
		{ 0x1f, 0x10, 0x10, 0x08, 0x04, 0x02, 0x02, 0x02 },	//7
		{ 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x11, 0x0e },	//8
		{ 0x0e, 0x11, 0x11, 0x11, 0x1e, 0x10, 0x11, 0x0e },	//9
		{ 0x03, 0x03, 0x38, 0x04, 0x04, 0x04, 0x04, 0x38 }  //C
};

uint8_t read_temp_reg = 0;
uint8_t read_temp_val;

int display_counter = 0;

void init_i2c()
{
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	SCL_SDA_config.Pin = GPIO_PIN_8 | GPIO_PIN_9;
	SCL_SDA_config.Pull = GPIO_NOPULL;
	SCL_SDA_config.Mode = GPIO_MODE_AF_OD;
	SCL_SDA_config.Alternate = GPIO_AF4_I2C1;

	HAL_GPIO_Init(GPIOB, &SCL_SDA_config);

	__HAL_RCC_I2C1_CLK_ENABLE()
	;

	I2C_handle.Instance = I2C1;
	I2C_handle.Init.Timing = 0x40912732;
	I2C_handle.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;

	HAL_I2C_Init(&I2C_handle);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;
	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 10800 - 1;  //108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
	timer_handle.Init.Period = 10000 - 1;  //10000*0.1ms = 1 second period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM2_IRQn, 4, 0);

	HAL_NVIC_EnableIRQ(TIM2_IRQn);

	HAL_TIM_Base_Start_IT(&timer_handle);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	init_i2c();
	init_timer();

	HAL_I2C_Master_Transmit(&I2C_handle, HT16K33_ADDRESS, &system_setup_reg, sizeof(system_setup_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, HT16K33_ADDRESS, &set_reg, sizeof(set_reg), 100);
	HAL_I2C_Master_Transmit(&I2C_handle, HT16K33_ADDRESS, &display_set_reg, sizeof(display_set_reg), 100);

	while (1) {

	}
}

void TIM2_IRQHandler()
{
	/* saving the current frame and executing the interrupt callback */
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{
	HAL_I2C_Master_Transmit(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_reg, sizeof(read_temp_reg), 100);
	HAL_I2C_Master_Receive(&I2C_handle, TEMP_SENSOR_ADDRESS, &read_temp_val, sizeof(read_temp_val), 100);

	if (display_counter == 2)
		display_counter = -1;
	display_counter++;

	if (display_counter == 0) {
		for (int i = 0; i < 8; i++) {
			HAL_I2C_Mem_Write(&I2C_handle, HT16K33_ADDRESS, i * 2, sizeof(uint8_t), &digits[read_temp_val / 10][i], 1, 100);
		}
	}
	if (display_counter == 1) {
		for (int i = 0; i < 8; i++) {
			HAL_I2C_Mem_Write(&I2C_handle, HT16K33_ADDRESS, i * 2, sizeof(uint8_t), &digits[read_temp_val % 10][i], 1, 100);
		}
	}
	if (display_counter == 2) {
		for (int i = 0; i < 8; i++) {
			HAL_I2C_Mem_Write(&I2C_handle, HT16K33_ADDRESS, i * 2, sizeof(uint8_t), &digits[10][i], 1, 100);
		}
	}
}
