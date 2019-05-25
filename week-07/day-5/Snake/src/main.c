#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "SystemClockConfig.h"
#include "game_area.h"

RNG_HandleTypeDef randomNumber;

void LCD_Init()
{
	BSP_LCD_Init();
	BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS);
	BSP_LCD_SelectLayer(1);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetBackColor(LCD_COLOR_WHITE);
	BSP_LCD_Clear(LCD_COLOR_WHITE);
}

void random_init()
{
	__HAL_RCC_RNG_CLK_ENABLE()
	;
	randomNumber.Instance = RNG;

	HAL_RNG_Init(&randomNumber);
}
int main(void)
{
	HAL_Init();
	SystemClock_Config();
	LCD_Init();
	BSP_TS_Init(BSP_LCD_GetXSize(), BSP_LCD_GetYSize());
	random_init();

	while (1) {

		TS_StateTypeDef ts_state;

		draw_game_area();

		BSP_TS_GetState(&ts_state);
		if (ts_state.touchDetected) {

		}
	}
}


void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
}
