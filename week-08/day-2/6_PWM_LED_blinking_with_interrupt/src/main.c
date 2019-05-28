#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"

//Write a program which slowly and continuously rises and lowers the intensity of an LED's light using PWM
//Use a timer interrupt from another timer instance for timing!

/* the timer's config structure */
TIM_HandleTypeDef timer_handle_pwm;
TIM_HandleTypeDef timer_handle_interrupt;

TIM_OC_InitTypeDef pwm_config;

GPIO_InitTypeDef PA15_LED_config;

volatile int duty_cycle = 15;
volatile int direction = 1;

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

	HAL_TIM_PWM_ConfigChannel(&timer_handle_pwm, &pwm_config, TIM_CHANNEL_1);
}

void init_timer_pwm()
{
	__HAL_RCC_TIM2_CLK_ENABLE()
	;

	timer_handle_pwm.Instance = TIM2;
	timer_handle_pwm.Init.Prescaler = 108 - 1; // 108000000/108=1000000 -> speed of 1 count-up: 1/1000000 s = 0.001 ms
	timer_handle_pwm.Init.Period = 100 - 1; // 100 x 0.001 ms = 10 ms = 0.01 s period
	timer_handle_pwm.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_pwm.Init.CounterMode = TIM_COUNTERMODE_UP;

	/* configuring the timer in PWM mode instead of calling HAL_TIM_Base_Init(&timer_handle) */
	HAL_TIM_PWM_Init(&timer_handle_pwm);
}

void init_timer_interrupt(void)
{
	__HAL_RCC_TIM3_CLK_ENABLE()
	;

	timer_handle_interrupt.Instance = TIM3;
	timer_handle_interrupt.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.01 ms
	timer_handle_interrupt.Init.Period = 100 - 1; // 100 x 0.01 ms = 0.01 second period
	timer_handle_interrupt.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle_interrupt.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle_interrupt);

	/* assign the highest priority to our interrupt line */
	HAL_NVIC_SetPriority(TIM3_IRQn, 1, 0);

	/* tell the interrupt handling unit to process our interrupts */
	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}

int main(void)
{
	HAL_Init();
	SystemClock_Config();

	init_LED();
	init_timer_pwm();
	init_timer_interrupt();
	init_PWM();

	/* starting the timer in interrupt mode */
	HAL_TIM_PWM_Start(&timer_handle_pwm, TIM_CHANNEL_1);
	HAL_TIM_Base_Start_IT(&timer_handle_interrupt);

	while (1) {
		__HAL_TIM_SET_COMPARE(&timer_handle_pwm, TIM_CHANNEL_1, duty_cycle);
	}
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle_interrupt);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM3) {
		duty_cycle += direction;
		if (duty_cycle == 0 || duty_cycle == 100)
			direction *= -1;
	}
}
