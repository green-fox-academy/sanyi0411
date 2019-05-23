#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

void init_led_pins();

int main() {
	HAL_Init();
	init_led_pins();

	int counter = 0;

	int matrix [16][4] = {
			{0,0,0,1},
			{0,0,1,0},
			{0,0,1,1},
			{0,1,0,0},
			{0,1,0,1},
			{0,1,1,0},
			{0,1,1,1},
			{1,0,0,0},
			{1,0,0,1},
			{1,0,1,0},
			{1,0,1,1},
			{1,1,0,0},
			{1,1,0,1},
			{1,1,1,0},
			{1,1,1,1}
	};

	while (1) {
		for (int i = 0; i < 16; ++i) {
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, matrix[i][3]);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, matrix[i][2]);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_8, matrix[i][1]);
			HAL_GPIO_WritePin(GPIOF, GPIO_PIN_7, matrix[i][0]);
			HAL_Delay(500);
		}
	}
}

void init_led_pins() {
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10 | GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

