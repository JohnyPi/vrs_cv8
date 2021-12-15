/*
 * display.c
 *
 *  Created on: Dec 14, 2021
 *      Author: Marek Pohancenik
 */

#include "display.h"

uint64_t disp_time = 0, disp_time_saved = 0;

void display_update(char c, uint8_t dgt);
void display_show(char znk[50]);
uint8_t shift = 0;
uint8_t len = 0;
uint8_t prerusenie = 0;
uint8_t start=1;

void setDigit(uint8_t pos);

/*Reset (turn-off) all the segments of display*/
void resetSegments(void) {
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_11);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_8);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

/*Set (turn-on) all the segments of display*/
void setSegments(void) {
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_11);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_8);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

/* Reset (turn-off) all digits*/
void resetDigits(void) {
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_2);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_6);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_7);
}

/* Reset (turn-on) all digits*/
void setDigits(void) {
	DIGIT_1_ON;
	DIGIT_2_ON;
	DIGIT_3_ON;
	DIGIT_4_ON;
	DIGIT_TIME_ON;
}

void setDecimalPoint(void) {
	LL_GPIO_ResetOutputPin(SEGMENTDP_PORT, SEGMENTDP_PIN);
}


void character_A(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_B(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_C(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_D(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_E(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_F(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_G(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_H(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_I(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_J(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_K(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_L(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_M(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_N(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_O(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_P(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_Q(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_R(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_S(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_T(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_U(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_V(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_W(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_X(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_Y(void) {

	//LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

void character_Z(void) {

	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	//LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
}

//Znaky cisla

void character_1(void) {
	// B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
}

void character_2(void) {
	// A,B,G,E,D
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
}

void character_3(void) {
	// A,B,G,C,D
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
}

void character_4(void) {
	// F,B,G,C
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
}

void character_5(void) {
	// A,F,G,C,D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
}

void character_6(void) {
	// A,F,G,E,C,D
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
}

void character_7(void) {
	// A,B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
}

void character_8(void) {
	// A,B,C,D,E,F,G
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
}

void character_9(void) {
	// A,B,C
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTG_PORT, SEGMENTG_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
}

void character_0(void) {
	// A,B,C,D,E,F
	LL_GPIO_ResetOutputPin(SEGMENTF_PORT, SEGMENTF_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTC_PORT, SEGMENTC_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTA_PORT, SEGMENTA_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTE_PORT, SEGMENTE_PIN);
	LL_GPIO_ResetOutputPin(SEGMENTB_PORT, SEGMENTB_PIN);
}

void character_podciar(void) {

	LL_GPIO_ResetOutputPin(SEGMENTD_PORT, SEGMENTD_PIN);

}
/**
 * Pre-process number before it is displayed. Extract digits of the number
 */

/*
 * Turns required digit ON
 */
void setDigit(uint8_t pos) {
	switch (pos) {
	case 0:
		DIGIT_1_ON;
		break;
	case 1:
		DIGIT_2_ON;
		break;
	case 2:
		DIGIT_3_ON;
		break;
	case 3:
		DIGIT_4_ON;
		break;
	}
}

void display_update(char c, uint8_t dgt) {

	switch (c) {
	case 'A':
	case 'a':
		setDigit(dgt);
		character_A();
		break;
	case 'B':
	case 'b':
		setDigit(dgt);
		character_B();
		break;
	case 'C':
	case 'c':
		setDigit(dgt);
		character_C();
		break;
	case 'D':
	case 'd':
		setDigit(dgt);
		character_D();
		break;
	case 'E':
	case 'e':
		setDigit(dgt);
		character_E();
		break;
	case 'F':
	case 'f':
		setDigit(dgt);
		character_F();
		break;
	case 'G':
	case 'g':
		setDigit(dgt);
		character_G();
		break;
	case 'H':
	case 'h':
		setDigit(dgt);
		character_H();
		break;
	case 'I':
	case 'i':
		setDigit(dgt);
		character_I();
		break;
	case 'J':
	case 'j':
		setDigit(dgt);
		character_J();
		break;
	case 'K':
	case 'k':
		setDigit(dgt);
		character_K();
		break;
	case 'L':
	case 'l':
		setDigit(dgt);
		character_L();
		break;
	case 'M':
	case 'm':
		setDigit(dgt);
		character_M();
		break;
	case 'N':
	case 'n':
		setDigit(dgt);
		character_N();
		break;
	case 'O':
	case 'o':
		setDigit(dgt);
		character_O();
		break;
	case 'P':
	case 'p':
		setDigit(dgt);
		character_P();
		break;
	case 'Q':
	case 'q':
		setDigit(dgt);
		character_Q();
		break;
	case 'R':
	case 'r':
		setDigit(dgt);
		character_R();
		break;
	case 'S':
	case 's':
		setDigit(dgt);
		character_S();
		break;
	case 'T':
	case 't':
		setDigit(dgt);
		character_T();
		break;
	case 'U':
	case 'u':
		setDigit(dgt);
		character_U();
		break;
	case 'V':
	case 'v':
		setDigit(dgt);
		character_V();
		break;
	case 'W':
	case 'w':
		setDigit(dgt);
		character_W();
		break;
	case 'X':
	case 'x':
		setDigit(dgt);
		character_X();
		break;
	case 'Y':
	case 'y':
		setDigit(dgt);
		character_Y();
		break;
	case 'Z':
	case 'z':
		setDigit(dgt);
		character_Z();
		break;
	case '1':
		setDigit(dgt);
		character_1();
		break;
	case '2':
		setDigit(dgt);
		character_2();
		break;
	case '3':
		setDigit(dgt);
		character_3();
		break;
	case '4':
		setDigit(dgt);
		character_4();
		break;
	case '5':
		setDigit(dgt);
		character_5();
		break;
	case '6':
		setDigit(dgt);
		character_6();
		break;
	case '7':
		setDigit(dgt);
		character_7();
		break;
	case '8':
		setDigit(dgt);
		character_8();
		break;
	case '9':
		setDigit(dgt);
		character_9();
		break;
	case '0':
		setDigit(dgt);
		character_0();
		break;
	case '_':
		setDigit(dgt);
		character_podciar();
		break;

	}

	disp_time_saved = disp_time;
	while ((disp_time_saved + 2) > disp_time) {
	};

	resetDigits();
	resetSegments();
}

void display_show(char znk[50]) {
	len = strlen(znk);
	start =0;
		for (uint8_t i = 0; i < 4; i++) {
			display_update(znk[(shift) + i], i);
		}

}

void TIM3_IRQHandler(void) {
	if (LL_TIM_IsActiveFlag_UPDATE(TIM3)) {
		if ((shift < len-4) && prerusenie == 0) {
			shift++;
		}
		else if((shift == len-4)&&prerusenie ==0 && start==0){
			prerusenie =1;
		}

		else if(((shift+len)>len) && prerusenie ==1){
			shift--;
		}
		else if(((shift+len) == len)&&prerusenie ==1 && start==0){
			prerusenie =0;
		}

	}

	LL_TIM_ClearFlag_UPDATE(TIM3);
}

