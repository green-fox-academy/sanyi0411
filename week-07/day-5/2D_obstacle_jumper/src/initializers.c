/*
 * initializers.c
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#include "../inc/initializers.h"

void PB_init()
{
	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_EXTI);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 8, 0);
}

void TS_init()
{
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());

	TS_INT_GPIO_CLK_ENABLE();
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	BSP_TS_ITConfig();
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(TS_INT_PIN);
}

void LCD_Init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
}

void random_init()
{
	__HAL_RCC_RNG_CLK_ENABLE()
	;
	randomNumber.Instance = RNG;

	HAL_RNG_Init(&randomNumber);
}

void init_timer_interrupt()
{
	__HAL_RCC_TIM3_CLK_ENABLE();

	timer_handle.Instance = TIM3;
	timer_handle.Init.Prescaler = 10800 - 1; //108000000 / 10800 = 10000 -> 1/10000 = 0.1ms
	timer_handle.Init.Period = 800 - 1; //1000 * 0.1 = 80ms
	timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

	HAL_TIM_Base_Init(&timer_handle);

	HAL_NVIC_SetPriority(TIM3_IRQn, 3, 0);

	HAL_NVIC_EnableIRQ(TIM3_IRQn);
}
