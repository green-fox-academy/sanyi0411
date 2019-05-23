#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

void init_led_pins();
void init_button();

void EXTI4_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

volatile int counter = 0;

volatile int last_button_press = 0;

int main() {
	HAL_Init();
	init_led_pins();
	init_button();

	while (1) {
	}
}

void init_led_pins() {
	__HAL_RCC_GPIOF_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_button() {
	__HAL_RCC_GPIOB_CLK_ENABLE()
	;

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_4;
	gpio_config.Mode = GPIO_MODE_IT_RISING;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOB, &gpio_config);

	HAL_NVIC_SetPriority(EXTI4_IRQn, 2, 0);
	HAL_NVIC_EnableIRQ(EXTI4_IRQn);
}

void EXTI4_IRQHandler() {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_4);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	int current_time = HAL_GetTick();
	if ((last_button_press + 200) > current_time)
		return;
	counter++;
	if(counter == 5)
		HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
	last_button_press = HAL_GetTick();
}
