#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

static void Error_Handler(void);
static void SystemClock_Config(void);
void draw_map();
void change_player();
void check_winner();

int game_state[3][3] = { { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } };
int player = 0;
int game_ended = 0;

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
	draw_map(game_state);

	TS_StateTypeDef ts_state;
	ts_state.touchX[0] = 0;
	ts_state.touchY[0] = 0;

	int last_step_x = -1;
	int last_step_y = -1;

	while (1) {
		if (!game_ended) {
			BSP_TS_GetState(&ts_state);
			if (ts_state.touchDetected) {
				if (ts_state.touchX[0] < 480 / 3 && ts_state.touchX[0] > 0)
					last_step_x = 0;
				if (ts_state.touchX[0] >= 480 / 3 && ts_state.touchX[0] < 2 * 480 / 3)
					last_step_x = 1;
				if (ts_state.touchX[0] >= 2 * 480 / 3)
					last_step_x = 2;

				if (ts_state.touchY[0] < 91 && ts_state.touchY[0] > 0)
					last_step_y = 0;
				if (ts_state.touchY[0] >= 91 && ts_state.touchY[0] < 182)
					last_step_y = 1;
				if (ts_state.touchY[0] >= 182)
					last_step_y = 2;

				if (game_state[last_step_x][last_step_y] == -1) {
					game_state[last_step_x][last_step_y] = player;
					change_player();
				}

			}
		}
		check_winner();
		draw_map();
	}
}

void draw_map()
{
	BSP_LCD_DrawHLine(0, 272 / 3, 480);
	BSP_LCD_DrawHLine(0, 2 * 272 / 3, 480);
	BSP_LCD_DrawVLine(480 / 3, 0, 272);
	BSP_LCD_DrawVLine(2 * 480 / 3, 0, 272);

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (game_state[i][j] == 0) {
				uint16_t x = 160 * i + 80;
				uint16_t y = 91 * j + 45;
				BSP_LCD_DisplayStringAt(x, y, "O", LEFT_MODE);
			} else if (game_state[i][j] == 1) {
				uint16_t x = 160 * i + 80;
				uint16_t y = 91 * j + 45;
				BSP_LCD_DisplayStringAt(x, y, "X", LEFT_MODE);
			}
		}
	}

}

void change_player()
{
	if (player == 0)
		player = 1;
	else
		player = 0;
}

void check_winner()
{
	for (int i = 0; i < 3; ++i) {
		if (game_state[i][0] == game_state[i][1] && game_state[i][1] == game_state[i][2] && game_state[i][0] != -1) {
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			uint16_t x = 160 * i + 90;
			BSP_LCD_DrawCircle(x, 55, 20);
			BSP_LCD_DrawCircle(x, 145, 20);
			BSP_LCD_DrawCircle(x, 235, 20);
			game_ended = 1;
		}
		if (game_state[0][i] == game_state[1][i] && game_state[1][i] == game_state[2][i] && game_state[0][i] != -1) {
			BSP_LCD_SetTextColor(LCD_COLOR_RED);
			uint16_t y = 91 * i + 55;
			BSP_LCD_DrawCircle(90, y, 20);
			BSP_LCD_DrawCircle(250, y, 20);
			BSP_LCD_DrawCircle(410, y, 20);
			game_ended = 1;
		}
	}
	if (game_state[0][0] == game_state[1][1] && game_state[1][1] == game_state[2][2] && game_state[0][0] != -1) {
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_DrawCircle(90, 55, 20);
		BSP_LCD_DrawCircle(250, 145, 20);
		BSP_LCD_DrawCircle(410, 235, 20);
		game_ended = 1;
	}

	if (game_state[2][0] == game_state[1][1] && game_state[1][1] == game_state[0][2] && game_state[1][1] != -1) {
		BSP_LCD_SetTextColor(LCD_COLOR_RED);
		BSP_LCD_DrawCircle(410, 55, 20);
		BSP_LCD_DrawCircle(250, 145, 20);
		BSP_LCD_DrawCircle(490, 235, 20);
		game_ended = 1;
	}
}

void EXTI15_10_IRQHandler()
{
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_11);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
}

static void Error_Handler(void)
{
}

static void SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
	RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

	/**Configure the main internal regulator output voltage */
	__HAL_RCC_PWR_CLK_ENABLE()
	;
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
	RCC_OscInitStruct.PLL.PLLM = 8;
	RCC_OscInitStruct.PLL.PLLN = 216;
	RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
	RCC_OscInitStruct.PLL.PLLQ = 2;

	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/**Activate the Over-Drive mode */
	if (HAL_PWREx_EnableOverDrive() != HAL_OK) {
		Error_Handler();
	}

	/**Initializes the CPU, AHB and APB busses clocks */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_7) != HAL_OK) {
		Error_Handler();
	}
}
