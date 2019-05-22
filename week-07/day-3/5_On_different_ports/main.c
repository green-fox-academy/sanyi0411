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
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

	// Init user led (I 1)
	GPIOG->MODER |= (GPIO_MODER_MODER6_0); /* configure PI1 in output mode */
	GPIOC->MODER |= (GPIO_MODER_MODER7_0);
	GPIOI->MODER |= (GPIO_MODER_MODER0_0);
	GPIOF->MODER |= (GPIO_MODER_MODER7_0);

	GPIOG->OTYPER &= ~(GPIO_OTYPER_OT_6); /* ensure push pull mode selected default */
	GPIOC->OTYPER &= ~(GPIO_OTYPER_OT_7);
	GPIOI->OTYPER &= ~(GPIO_OTYPER_OT_0);
	GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_7);

	GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
	GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10); /* ensure all pull up pull down resistors are disabled */
}

void light_led0();
void light_led1();
void light_led2();
void light_led3();

void (*light_led[4])() = {light_led0, light_led1, light_led2, light_led3};

	int main(void) {
		HAL_Init();
		init_pins();

		int counter = 0;
		int direction = -1;

		while (1) {
			if (counter == 3 || counter == 0)
				direction *= -1;
			(*light_led[counter])();
			counter += direction;
		}
	}

	void light_led0() {
		GPIOG->BSRR = (1 << 6);
		HAL_Delay(70);
		GPIOG->BSRR = (1 << 6) << 16;
		HAL_Delay(70);
	}
	void light_led1() {
		GPIOC->BSRR = (1 << 7);
		HAL_Delay(70);
		GPIOC->BSRR = (1 << 7) << 16;
		HAL_Delay(70);
	}
	void light_led2() {
		GPIOI->BSRR = (1 << 0);
		HAL_Delay(70);
		GPIOI->BSRR = (1 << 0) << 16;
		HAL_Delay(70);
	}
	void light_led3() {
		GPIOF->BSRR = (1 << 7);
		HAL_Delay(70);
		GPIOF->BSRR = (1 << 7) << 16;
		HAL_Delay(70);
	}

