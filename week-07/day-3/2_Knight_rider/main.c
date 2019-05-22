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

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"

void init_pins() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN; /* GPIOI clock enable */

	// Init user led (I 1)
	GPIOF->MODER |= (GPIO_MODER_MODER10_0); /* configure PI1 in output mode */
	GPIOF->MODER |= (GPIO_MODER_MODER9_0);
	GPIOF->MODER |= (GPIO_MODER_MODER8_0);
	GPIOF->MODER |= (GPIO_MODER_MODER7_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10); /* ensure push pull mode selected default */
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_8);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);
	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10); /* ensure all pull up pull down resistors are disabled */
}

int main(void) {
	HAL_Init();
	init_pins();

	uint32_t red_led1 = (1 << 10);
	uint32_t red_led2 = (1 << 9);
	uint32_t red_led3 = (1 << 8);
	uint32_t red_led4 = (1 << 7);

	while (1) {

		GPIOF->BSRR = red_led1;
		HAL_Delay(70);
		GPIOF->BSRR = red_led1 << 16;
		HAL_Delay(70);
		GPIOF->BSRR = red_led2;
		HAL_Delay(70);
		GPIOF->BSRR = red_led2 << 16;
		HAL_Delay(70);
		GPIOF->BSRR = red_led3;
		HAL_Delay(70);
		GPIOF->BSRR = red_led3 << 16;
		HAL_Delay(70);
		GPIOF->BSRR = red_led4;
		HAL_Delay(70);
		GPIOF->BSRR = red_led4 << 16;
		HAL_Delay(70);
		GPIOF->BSRR = red_led3;
		HAL_Delay(70);
		GPIOF->BSRR = red_led3 << 16;
		HAL_Delay(70);
		GPIOF->BSRR = red_led2;
		HAL_Delay(70);
		GPIOF->BSRR = red_led2 << 16;
		HAL_Delay(70);

	}
}
