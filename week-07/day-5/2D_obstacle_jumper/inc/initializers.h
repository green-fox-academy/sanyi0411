/*
 * initializers.h
 *
 *  Created on: 2019. máj. 31.
 *      Author: sando
 */

#ifndef INITIALIZERS_H_
#define INITIALIZERS_H_

#include "stm32f7xx.h"
#include "stm32746g_discovery.h"
#include "stm32746g_discovery_lcd.h"
#include "stm32746g_discovery_ts.h"
#include "../inc/SystemClockConfig.h"

RNG_HandleTypeDef randomNumber;

TIM_HandleTypeDef timer_handle;

void PB_init();

void TS_init();

void EXTI15_10_IRQHandler();

void LCD_Init();

void random_init();

#endif /* INITIALIZERS_H_ */
