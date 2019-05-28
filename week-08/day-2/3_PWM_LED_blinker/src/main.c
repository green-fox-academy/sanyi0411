#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"

//Write a program which slowly and continuously rises and lowers the intensity of an LED's light using PWM!
//For timing you can use HAL_Delay() but you can use a general purpose timer too, just to practice using timers.

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;

/* the output compare channel's config structure */
TIM_OC_InitTypeDef pwm_config;

/* pin config: we cannot use the green user LED because it's not connected to an output compare channel so we use PA15 */
GPIO_InitTypeDef PA15_LED_config;

int light_intensity = 15;
int direction = 1;

void init_LED()
{
	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

	PA15_LED_config.Pin = GPIO_PIN_15;
	PA15_LED_config.Mode = GPIO_MODE_AF_PP; /* configure as output, in PUSH-PULL mode */
	PA15_LED_config.Pull = GPIO_NOPULL;
	PA15_LED_config.Speed = GPIO_SPEED_HIGH;
	PA15_LED_config.Alternate = GPIO_AF1_TIM2; /* we need this alternate function to use TIM2 in OC mode */

	HAL_GPIO_Init(GPIOA, &PA15_LED_config);
}

void init_timer()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer_handle.Instance = TIM2;
	timer_handle.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
	timer_handle.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
	HAL_TIM_PWM_Init(&timer_handle);
}

void init_PWM()
{
	/*
	 * 50% * 0.01 s = 0.005 s: 0.005 low, then 0.005 s high;
	 * our eyes are not able to notice that it is a vibrating light
	 */
	pwm_config.Pulse = 50;
	pwm_config.OCMode = TIM_OCMODE_PWM1;
	pwm_config.OCPolarity = TIM_OCPOLARITY_HIGH;
	pwm_config.OCFastMode = TIM_OCFAST_ENABLE;

	HAL_TIM_PWM_ConfigChannel(&timer_handle, &pwm_config, TIM_CHANNEL_1);
}

void light()
{

	__HAL_TIM_SET_COMPARE(&timer_handle, TIM_CHANNEL_1, light_intensity);
	HAL_Delay(10);
	if (light_intensity == 0 || light_intensity == 100)
		direction *= -1;
	light_intensity += (1 * direction);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_LED();
	init_timer();
	init_PWM();

	// Start the timer for PWM
	HAL_TIM_PWM_Start(&timer_handle, TIM_CHANNEL_1);

	while (1) {
		light();
	}
}
