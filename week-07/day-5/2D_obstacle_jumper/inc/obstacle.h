/*
 * obstacle.h
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#ifndef OBSTACLE_H_
#define OBSTACLE_H_

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"

typedef struct obstacle{
	int x;
	int y;
	int obstacle_on_screen;
	int last_position_change_time;
} obstacle_t;

extern obstacle_t obstacle1;

void draw_obstacle();

void move_obstacle();

#endif /* OBSTACLE_H_ */
