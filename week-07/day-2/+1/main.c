/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

int main(void) {
	HAL_Init();

	BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);

	BSP_LED_Init(LED1);

	float i = 1000;
	float change = 0.9;

	while (1) {
		BSP_LED_Toggle(LED1);
		HAL_Delay(i);
		i *= change;
		if (i < 2)
			change = 1.1;
		if (i > 700)
			change = 0.9;
	}
}
