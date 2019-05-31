#include "../inc/player.h"
#include "../inc/obstacle.h"
#include "../inc/initializers.h"

void draw_track();
void check_collision();

int game_ended = 0;

int main(void)
{
	HAL_Init();
	SystemClock_Config();
	LCD_Init();
	random_init();
	TS_init();
	PB_init();
	init_timer_interrupt();
	HAL_TIM_Base_Start_IT(&timer_handle);

	while (1) {
	}
}

void draw_track()
{
	BSP_LCD_DrawHLine(0, 200, 480);

	BSP_LCD_SetTextColor(LCD_COLOR_YELLOW);
	BSP_LCD_FillCircle(450, 30, 30);

	//vertical line
	BSP_LCD_DrawLine(449, 65, 449, 100);
	BSP_LCD_DrawLine(450, 65, 450, 100);
	BSP_LCD_DrawLine(451, 65, 451, 100);

	//45° line
	BSP_LCD_DrawLine(424, 54, 404, 74);
	BSP_LCD_DrawLine(425, 55, 405, 75);
	BSP_LCD_DrawLine(426, 56, 406, 76);

	//horizontal line
	BSP_LCD_DrawLine(415, 29, 380, 29);
	BSP_LCD_DrawLine(415, 30, 380, 30);
	BSP_LCD_DrawLine(415, 31, 380, 31);

	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
}

void check_collision()
{
	if (player1.y + 45 >= obstacle1.y && player1.x >= obstacle1.x && player1.x <= obstacle1.x + 15) {
		game_ended = 1;
		BSP_LCD_DisplayStringAt(180, 120, (uint8_t *) "GAME OVER", LEFT_MODE);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
		player1.is_jumping = 1;
}

void TIM3_IRQHandler(void)
{
	HAL_TIM_IRQHandler(&timer_handle);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (!game_ended) {
		BSP_LCD_Clear(LCD_COLOR_WHITE);

		if (player1.is_jumping)
			jump();
		else
			draw_player(player1.x, player1.y);

		draw_track();
		draw_obstacle();
		move_obstacle();

		check_collision();
	}
}
