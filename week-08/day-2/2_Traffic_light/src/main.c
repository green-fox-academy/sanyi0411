#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"

//Write a program to simulate a traffic lamp with 3 LED-s (green, orange, red).
//Each light comes one by one and have different periods.
//First, initialize three timers (one for every LED)
//Then if it is working, solve it by using only 1 timer!
//If you want some challenge, make it 100% real: before the green light the red and yellow lights are on at the same time

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 54000 - 1; // 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms
	timer_handle.Init.Period = 24000 - 1; // 24000 x 0.5 ms = 12 second period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);
}

void init_LED()
{
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_7 | GPIO_PIN_8 | GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

int main(void)
{
	HAL_Init();

	/* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
	SystemClock_Config();

	init_timer();
	init_LED();

	/* starting the timer */
	HAL_TIM_Base_Start(&timer_handle);

	uint16_t timer_value = 0;

	while (1) {
		timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);
		if (timer_value == 0) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_SET);
		}
		if (timer_value == 6000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, GPIO_PIN_RESET);
		}
		if (timer_value == 12000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_RESET);
		}
		if (timer_value == 18000) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, GPIO_PIN_SET);
		}
	}
}
