#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile uint8_t *string;

void init_uart()
{
    /* enable the clock of the used peripherial instance */
    __HAL_RCC_USART1_CLK_ENABLE();

    /* defining the UART configuration structure */
    uart_handle.Instance = USART1;
    uart_handle.Init.BaudRate = 115200;
    uart_handle.Init.WordLength = UART_WORDLENGTH_8B;
    uart_handle.Init.StopBits = UART_STOPBITS_1;
    uart_handle.Init.Parity = UART_PARITY_NONE;
    uart_handle.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    uart_handle.Init.Mode = UART_MODE_TX_RX;

    BSP_COM_Init(COM1, &uart_handle);

    HAL_NVIC_EnableIRQ(USART1_IRQn);
    HAL_NVIC_SetPriority(USART1_IRQn, 8, 0);
}

int main(void)
{
    HAL_Init();
    init_uart();

    string = calloc(1, 1);

    HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

    while (1) {
        HAL_UART_Transmit(&uart_handle, (uint8_t*) string, strlen(string), 0xFFFF);
        HAL_Delay(1000);

        /* or using printf(): */
        //printf("%s", string);
    }

    free(string);
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint32_t length = strlen(string);
	string = realloc(string, length + 2);
	string[length] = buffer;
	string[length + 1] = '\0';

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
}

UART_PUTCHAR
{
    HAL_UART_Transmit(&uart_handle, (uint8_t*)&ch, 1, 0xFFFF);
    return ch;
}
