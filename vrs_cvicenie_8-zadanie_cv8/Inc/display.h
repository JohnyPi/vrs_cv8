/*
 * display.c
 *
 *  Created on: Dec 14, 2021
 *      Author: Marek Pohancenik
 */

#include "main.h"
#include <stdio.h>
#include <string.h>

#define SEGMENTA_PIN	LL_GPIO_PIN_1
#define SEGMENTA_PORT	GPIOA

#define SEGMENTB_PIN	LL_GPIO_PIN_0
#define SEGMENTB_PORT	GPIOA

#define SEGMENTC_PIN	LL_GPIO_PIN_8
#define SEGMENTC_PORT	GPIOA

#define SEGMENTD_PIN	LL_GPIO_PIN_5
#define SEGMENTD_PORT	GPIOB

#define SEGMENTE_PIN 	LL_GPIO_PIN_11
#define SEGMENTE_PORT	GPIOA

#define SEGMENTF_PIN 	LL_GPIO_PIN_3
#define SEGMENTF_PORT	GPIOA

#define SEGMENTG_PIN	LL_GPIO_PIN_4
#define SEGMENTG_PORT	GPIOB

#define SEGMENTDP_PIN	LL_GPIO_PIN_1
#define SEGMENTDP_PORT	GPIOB

#define DIGIT_1_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5)
#define DIGIT_2_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4)
#define DIGIT_3_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_6)
#define DIGIT_4_ON		LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_2)
#define DIGIT_TIME_ON	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_7)



void resetDigits(void);
void setDigits(void);
void resetSegments(void);
void setSegments(void);

void display_update(char c, uint8_t dgt);
void display_show(char znk[50]);

void setDecimalPoint(void);
void character_A(void);
void character_B(void);
void character_C(void);
void character_D(void);
void character_E(void);
void character_F(void);
void character_G(void);
void character_H(void);
void character_I(void);
void character_J(void);
void character_K(void);
void character_L(void);
void character_M(void);
void character_N(void);
void character_O(void);
void character_P(void);
void character_Q(void);
void character_R(void);
void character_S(void);
void character_T(void);
void character_U(void);
void character_V(void);
void character_W(void);
void character_X(void);
void character_Y(void);
void character_Z(void);
void character_1(void);
void character_2(void);
void character_3(void);
void character_4(void);
void character_5(void);
void character_6(void);
void character_7(void);
void character_8(void);
void character_9(void);
void character_0(void);
void character_podciar(void);
