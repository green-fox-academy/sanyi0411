#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "../inc/SystemClockConfig.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define UART_PUTCHAR int __io_putchar(int ch)

UART_HandleTypeDef uart_handle;

volatile uint8_t buffer = 0;
volatile char time_as_string[6];
int ind = 0;
int tickstart = 0;
int tickend = 0;

int minutes = 0;
int seconds = 0;

int flag = 0;

void init_uart()
{
	/* enable the clock of the used peripherial instance */
	__HAL_RCC_USART1_CLK_ENABLE()
	;

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

	uint8_t *first_text = "Set the timer in this format: mm.ss\r\n";

	HAL_UART_Transmit(&uart_handle, (uint8_t*) first_text, strlen(first_text), 0xFFFF);

	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);

	tickstart = HAL_GetTick();

	while (1) {
		if (flag) {
			tickend = HAL_GetTick();
			if (tickend - tickstart > 1000) {
				seconds -= 1;
				if (seconds == -1) {
					seconds = 59;
					minutes -= 1;
				}
				printf("%d : %d\r\n", minutes, seconds);
				tickstart = HAL_GetTick();
				if (minutes == 0 && seconds == 0) {
					flag = 0;
					HAL_NVIC_SystemReset();
				}
			}

		}
	}
}

void USART1_IRQHandler()
{
	HAL_UART_IRQHandler(&uart_handle);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	time_as_string[ind] = (char) buffer;
	ind++;

	if (ind == 5) {
		printf("\n");
		int minute1 = time_as_string[0] - '0';
		int minute2 = time_as_string[1] - '0';
		int second1 = time_as_string[3] - '0';
		int second2 = time_as_string[4] - '0';

		minutes = 10 * minute1 + minute2;
		seconds = 10 * second1 + second2;
		flag = 1;
	}
	HAL_UART_Receive_IT(&uart_handle, &buffer, 1);
}

UART_PUTCHAR
{
	HAL_UART_Transmit(&uart_handle, (uint8_t*) &ch, 1, 0xFFFF);
	return ch;
}
