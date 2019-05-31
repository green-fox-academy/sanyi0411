/*
 * player.c
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#include "../inc/player.h"

player_t player1 = { 45, 150, 0, 0, 0, 5, 0 };

void draw_player(int x, int y)
{
	change_position();

	BSP_LCD_DrawCircle(x, y, 6);
	BSP_LCD_DrawVLine(x, y + 6, 22);

	if (player1.running_position == 1) {
		//right arm
		BSP_LCD_DrawLine(x, y + 10, x + 4, y + 22);
		BSP_LCD_DrawLine(x + 4, y + 22, x + 8, y + 12);

		//left arm
		BSP_LCD_DrawLine(x, y + 10, x - 7, y + 16);
		BSP_LCD_DrawLine(x - 7, y + 16, x - 7, y + 24);

		//right leg
		BSP_LCD_DrawLine(x, y + 28, x + 9, y + 30);
		BSP_LCD_DrawLine(x + 9, y + 30, x + 4, y + 40);

		//left leg
		BSP_LCD_DrawLine(x, y + 28, x - 2, y + 39);
		BSP_LCD_DrawLine(x - 2, y + 39, x - 7, y + 50);
	} else if (player1.running_position == 3) {
		BSP_LCD_DrawLine(x, y + 10, x + 2, y + 22);
		BSP_LCD_DrawLine(x + 2, y + 22, x + 10, y + 22);

		BSP_LCD_DrawLine(x, y + 10, x - 3, y + 16);
		BSP_LCD_DrawLine(x - 3, y + 16, x, y + 24);

		BSP_LCD_DrawLine(x, y + 28, x + 4, y + 39);
		BSP_LCD_DrawLine(x + 4, y + 39, x + 7, y + 50);

		BSP_LCD_DrawLine(x, y + 28, x, y + 39);
		BSP_LCD_DrawLine(x, y + 39, x - 10, y + 37);
	} else if (player1.running_position == 2) {
		BSP_LCD_DrawLine(x, y + 10, x + 1, y + 24);
		BSP_LCD_DrawLine(x + 1, y + 24, x + 8, y + 20);

		BSP_LCD_DrawLine(x, y + 10, x - 3, y + 16);
		BSP_LCD_DrawLine(x - 3, y + 16, x, y + 24);

		BSP_LCD_DrawLine(x, y + 28, x + 7, y + 35);
		BSP_LCD_DrawLine(x + 7, y + 35, x + 5, y + 45);

		BSP_LCD_DrawLine(x, y + 28, x - 3, y + 39);
		BSP_LCD_DrawLine(x - 3, y + 39, x - 9, y + 45);
	} else if (player1.running_position == 5) {
		BSP_LCD_DrawLine(x, y + 10, x + 2, y + 22);
		BSP_LCD_DrawLine(x + 2, y + 22, x + 10, y + 22);

		BSP_LCD_DrawLine(x, y + 10, x - 3, y + 20);
		BSP_LCD_DrawLine(x - 3, y + 20, x + 3, y + 21);

		BSP_LCD_DrawLine(x, y + 28, x + 6, y + 40);
		BSP_LCD_DrawLine(x + 6, y + 40, x - 2, y + 40);

		BSP_LCD_DrawLine(x, y + 28, x, y + 39);
		BSP_LCD_DrawLine(x, y + 39, x, y + 50);
	} else if (player1.running_position == 4) {
		BSP_LCD_DrawLine(x, y + 10, x + 2, y + 20);
		BSP_LCD_DrawLine(x + 2, y + 20, x + 10, y + 22);

		BSP_LCD_DrawLine(x, y + 10, x - 3, y + 20);
		BSP_LCD_DrawLine(x - 3, y + 20, x + 3, y + 23);

		BSP_LCD_DrawLine(x, y + 28, x + 2, y + 39);
		BSP_LCD_DrawLine(x + 2, y + 39, x + 4, y + 50);

		BSP_LCD_DrawLine(x, y + 28, x, y + 40);
		BSP_LCD_DrawLine(x, y + 40, x - 6, y + 32);
	}
}

void change_position()
{
	player1.running_position++;
	if (player1.running_position == 6)
		player1.running_position = 1;

}

void jump()
{
	if (player1.is_jumping) {
		draw_player(player1.x, player1.y);
		switch (player1.y) {
		case 150:
			player1.y = 138;
			break;
		case 138:
			player1.y = 130;
			break;
		case 130:
			player1.y = 125;
			break;
		case 125:
			player1.y = 122;
			break;
		case 122:
			player1.y = 120;
			break;
		case 120:
			player1.y = 123;
			break;
		case 123:
			player1.y = 126;
			break;
		case 126:
			player1.y = 131;
			break;
		case 131:
			player1.y = 139;
			break;
		case 139:
			player1.y = 150;
			player1.is_jumping = 0;
			break;
		}
	}
}
