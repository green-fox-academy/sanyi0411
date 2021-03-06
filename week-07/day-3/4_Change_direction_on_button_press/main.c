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

void init_pins() {
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN; /* GPIOI clock enable */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;

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

	// Init user button (I 11)
	GPIOB->MODER |= (1 << 4); /* configure PI11 in input mode */
}

int main(void) {
	HAL_Init();
	init_pins();

	uint32_t user_button = (1 << 4);

	uint32_t red_led[] = { (1 << 10), (1 << 9), (1 << 8), (1 << 7) };

	int counter = 0;
	int direction = -1;

	while (1) {
		if (counter == 4 && direction == 1)
			counter = 0;
		if (counter == -1 && direction == -1)
			counter = 3;
		GPIOF->BSRR = red_led[counter];
		HAL_Delay(70);
		GPIOF->BSRR = red_led[counter] << 16;
		HAL_Delay(70);
		counter += direction;

		if (GPIOB->IDR & (user_button)) {
			direction *= -1;
		}
	}
}
