/*
 * player.h
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"

typedef struct player{
	int x;
	int y;
	int last_jump;
	int is_jumping;
	int last_position_change_time;
	int running_position;
	int running_timer;
} player_t;

void draw_player(int x, int y);

extern player_t player1;

void change_position();

void jump();

#endif /* PLAYER_H_ */
