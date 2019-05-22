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

void init_pins()
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;     /* GPIOI clock enable */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

    // Init user led (I 1)
    GPIOF->MODER |= (GPIO_MODER_MODER10_0);   /* configure PI1 in output mode */
    GPIOF->MODER |= (GPIO_MODER_MODER9_0);
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_10);    /* ensure push pull mode selected default */
    GPIOF->OTYPER &= ~(GPIO_OTYPER_OT_9);
    GPIOF->OSPEEDR |= (GPIO_OSPEEDER_OSPEEDR10); /* ensure maximum speed setting (even though it is unnecessary) */
    GPIOF->PUPDR &= ~(GPIO_PUPDR_PUPDR10);   /* ensure all pull up pull down resistors are disabled */

    // Init user button (I 11)
    GPIOI->MODER = 0;      /* configure PI11 in input mode */
}

int main(void)
{
    HAL_Init();
    init_pins();

    uint32_t red_led = (1 << 10);
    uint32_t red_led2 = (1 << 9);
    uint32_t user_button = (1 << 11);

    while (1) {
        /* when button is pushed LED turns on, when released, then LED turns off */
        if (GPIOI->IDR & (user_button)) {
            /* set PI1 */
            GPIOF->BSRR = red_led;
            GPIOF->BSRR = red_led2;

	    /* we could use the ODR register also
	    set PI1, leave the other bits as they are
	    GPIOI->ODR = GPIOI->ODR ^ green_led;
	    */
        } else {
            /* reset PI1 */
            GPIOF->BSRR = red_led << 16;
            GPIOF->BSRR = red_led2 << 16;

	    /* we could use the ODR register also
	    reset PI1, leave the other bits as they are
	    GPIOI->ODR ^= green_led;
	    */
        }
    }
}
