#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"

static void Error_Handler(void);
static void SystemClock_Config(void);

void draw_track();
void draw_player(int x, int y, uint32_t color);
void jump();
void draw_obstacle();
void moving_obstacle();

int player_x = 45;
int player_y = 150;
int last_jump = 0;
int is_jumping = 0;
int player_last_position_change_time = 0;

int obstacle_x = 465;
int obstacle_y = 185;
int obstacle_on_screen = 1;
int obstacle_last_position_change_time = 0;

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
		draw_track();
		draw_player(player_x, player_y, LCD_COLOR_BLACK);
		draw_obstacle(obstacle_x, obstacle_y);

		TS_StateTypeDef ts_state;

		BSP_TS_GetState(&ts_state);
		if (ts_state.touchDetected) {
			int current_time = HAL_GetTick();
			if ((last_jump + 100) < current_time) {
				is_jumping = 1;
				last_jump = HAL_GetTick();
			}
		}
		jump();
	}
}

void draw_track()
{
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
	BSP_LCD_DrawHLine(0, 200, 480);

	//BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	//BSP_LCD_FillCircle(450, 30, 30);

	//BSP_LCD_DrawLine(449, 65, 449, 100);
	//BSP_LCD_DrawLine(450, 65, 450, 100);
	//BSP_LCD_DrawLine(451, 65, 451, 100);

	//BSP_LCD_DrawLine(415, 29, 380, 29);
	//BSP_LCD_DrawLine(415, 30, 380, 30);
	//BSP_LCD_DrawLine(415, 31, 380, 31);

	//BSP_LCD_DrawLine(415, 29, 380, 29);
	//BSP_LCD_DrawLine(415, 30, 380, 30);
	//BSP_LCD_DrawLine(415, 31, 380, 31);

	//BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
}

void draw_player(int x, int y, uint32_t color)
{
	BSP_LCD_SetTextColor(color);
	BSP_LCD_DrawCircle(x, y, 6);
	BSP_LCD_DrawVLine(x, y + 6, 22);
	BSP_LCD_DrawLine(x, y + 28, x + 6, y + 50);
	BSP_LCD_DrawLine(x, y + 28, x - 6, y + 50);
	BSP_LCD_DrawLine(x, y + 10, x + 4, y + 22);
	BSP_LCD_DrawLine(x, y + 10, x - 4, y + 22);
}

void jump()
{
	if (is_jumping) {
		draw_player(player_x, player_y, LCD_COLOR_WHITE);
		int current_time = HAL_GetTick();
		if ((player_last_position_change_time + 100) > current_time)
			return;
		switch (player_y) {
		case 150:
			player_y = 138;
			break;
		case 138:
			player_y = 130;
			break;
		case 130:
			player_y = 125;
			break;
		case 125:
			player_y = 122;
			break;
		case 122:
			player_y = 120;
			break;
		case 120:
			player_y = 123;
			break;
		case 123:
			player_y = 126;
			break;
		case 126:
			player_y = 131;
			break;
		case 131:
			player_y = 139;
			break;
		case 139:
			player_y = 150;
			is_jumping = 0;
			break;
		}
		player_last_position_change_time = HAL_GetTick();
	}
}

void draw_obstacle(int x, int y)
{
	if (obstacle_x < 0) {
		obstacle_x = 465;
	}
	int current_time = HAL_GetTick();
	if ((obstacle_last_position_change_time + 100) > current_time)
		return;
	BSP_LCD_Clear(LCD_COLOR_WHITE);
	//BSP_LCD_SetTextColor(LCD_COLOR_GRAY);
	BSP_LCD_FillRect(x, y, 15, 15);
	obstacle_x -= 5;
	obstacle_last_position_change_time = HAL_GetTick();
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
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
