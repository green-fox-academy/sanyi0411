#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"

//Connect and initialize an LED or use the green user LED and initialize Timer 2 to increment the CNT register every 0.5 ms.
//Read Timer 2 CNT register with __HAL_TIM_GET_COUNTER() and toggle the LED with a frequency of 1 Hz.

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;

void init_timer()
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 10800 - 1; // 108000000/10800=10000 -> speed of 1 count-up: 1/10000 sec = 0.1 ms
    timer_handle.Init.Period = 10000 - 1; // 10000 x 0.1 ms = 1 second period
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle);
}

int main(void)
{
    HAL_Init();

    /* this function call sets the timers input clock to 108 Mhz (=108000000 Hz) */
    SystemClock_Config();

    BSP_LED_Init(LED_GREEN);
    init_timer();

    /* starting the timer */
    HAL_TIM_Base_Start(&timer_handle);

    uint16_t timer_value = 0;
    while (1) {

        /* blinking the user LED with 0.1 Hz (1 on and 1 off per 100 ms) */
        timer_value = __HAL_TIM_GET_COUNTER(&timer_handle);
        if (timer_value == 0) {
            BSP_LED_On(LED_GREEN);
        }
        if (timer_value == 5000) {
            BSP_LED_Off(LED_GREEN);
        }
    }
}
