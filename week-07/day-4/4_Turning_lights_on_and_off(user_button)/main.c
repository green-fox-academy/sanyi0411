#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

GPIO_InitTypeDef user_button_handle;

void init_led_pins();
void init_user_button();

void EXTI15_10_IRQHandler();
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

int main() {
	HAL_Init();
	init_led_pins();
	init_user_button();

	while (1) {
	}
}

void init_led_pins()
{
	__HAL_RCC_GPIOF_CLK_ENABLE();

	GPIO_InitTypeDef gpio_config;

	gpio_config.Pin = GPIO_PIN_10;
	gpio_config.Mode = GPIO_MODE_OUTPUT_PP;
	gpio_config.Pull = GPIO_NOPULL;
	gpio_config.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOF, &gpio_config);
}

void init_user_button()
{
    __HAL_RCC_GPIOI_CLK_ENABLE();

    user_button_handle.Pin = GPIO_PIN_11;
    user_button_handle.Pull = GPIO_NOPULL;
    user_button_handle.Speed = GPIO_SPEED_FAST;
    user_button_handle.Mode = GPIO_MODE_IT_RISING;

    HAL_GPIO_Init(GPIOI, &user_button_handle);

    HAL_NVIC_SetPriority(EXTI15_10_IRQn, 2, 0);
    HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void EXTI15_10_IRQHandler()
{
    HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	HAL_GPIO_TogglePin(GPIOF, GPIO_PIN_10);
}
