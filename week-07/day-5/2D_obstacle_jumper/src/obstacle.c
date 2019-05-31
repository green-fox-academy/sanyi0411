/*
 * obstacle.c
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#include "../inc/obstacle.h"

obstacle_t obstacle1 = { 465, 185, 1, 0 };

void draw_obstacle()
{
	BSP_LCD_SetTextColor(LCD_COLOR_LIGHTGRAY);
	BSP_LCD_FillRect(obstacle1.x, obstacle1.y, 15, 15);
	BSP_LCD_SetTextColor(LCD_COLOR_BLACK);
}

void move_obstacle()
{
	if (obstacle1.x < 0) {
		obstacle1.x = 465;
	}
	obstacle1.x -= 5;
}
