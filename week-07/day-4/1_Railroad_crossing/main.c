#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_led_pins(void);

int main(void)
{
	HAL_Init();
	init_led_pins();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_10, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9, GPIO_PIN_RESET);

	while (1) {
			HAL_Delay(500);
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
			HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_9);
	}
}

void init_led_pins(void)
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10 | GPIO_PIN_9;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}
