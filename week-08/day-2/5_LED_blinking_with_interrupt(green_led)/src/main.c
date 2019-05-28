#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"

//Connect and initialize an LED or use the green user LED and initialize Timer 2 to generate an interrupt every 0.5 s.
//Toggle the LED with a frequency of 1 Hz!

/* the timer's config structure */
TIM_HandleTypeDef timer_handle;

void init_timer(void)
{
    __HAL_RCC_TIM2_CLK_ENABLE();

    timer_handle.Instance = TIM2;
    timer_handle.Init.Prescaler = 54000 - 1; // 108000000/54000=2000 -> speed of 1 count-up: 1/2000 sec = 0.5 ms
    timer_handle.Init.Period = 1000 - 1; // 1000 x 0.5 ms = 0.5 second period
    timer_handle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    timer_handle.Init.CounterMode = TIM_COUNTERMODE_UP;

    HAL_TIM_Base_Init(&timer_handle);

    /* assign the highest priority to our interrupt line */
    HAL_NVIC_SetPriority(TIM2_IRQn, 1, 0);

    /* tell the interrupt handling unit to process our interrupts */
    HAL_NVIC_EnableIRQ(TIM2_IRQn);
}

int main(void)
{
    HAL_Init();
    SystemClock_Config();

    BSP_LED_Init(LED_GREEN);
    init_timer();

    /* starting the timer in interrupt mode */
    HAL_TIM_Base_Start_IT(&timer_handle);

    while (1) {
        /* we can leave this empty or even block the CPU forever with HAL_Delay(1000)*/
    }
}

void TIM2_IRQHandler(void)
{
    HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2) {
        /* toggling the LED once in every second */
        BSP_LED_Toggle(LED_GREEN);
    }
}
