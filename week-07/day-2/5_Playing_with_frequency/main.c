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

	int freq = 0;
	int counter = 0;

	while (1) {
		if (freq % 4 == 0) {
			BSP_LED_Toggle(LED1);
			HAL_Delay(1000);
			counter++;
			if (counter % 6 == 0) {
				counter = 0;
				freq++;
			}
		}
		if (freq % 4 == 1) {
			BSP_LED_Toggle(LED1);
			HAL_Delay(500);
			counter++;
			if (counter % 6 == 0) {
				counter = 0;
				freq++;
			}
		}
		if (freq % 4 == 2) {
			BSP_LED_Toggle(LED1);
			HAL_Delay(250);
			counter++;
			if (counter % 6 == 0) {
				counter = 0;
				freq++;
			}
		}
		if (freq % 4 == 3) {
			BSP_LED_Toggle(LED1);
			HAL_Delay(125);
			counter++;
			if (counter % 6 == 0) {
				counter = 0;
				freq++;
			}
		}
	}
}
