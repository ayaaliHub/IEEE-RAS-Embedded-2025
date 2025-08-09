#include "motor.h"
#include "gpio.h"

#define M1_IN1 PA0
#define M1_IN2 PA1
#define M2_IN3 PA2
#define M2_IN4 PA3

void Motor_Init(void) {
	GPIO_InitPin(&DDRA, M1_IN1, OUTPUT);
	GPIO_InitPin(&DDRA, M1_IN2, OUTPUT);
	GPIO_InitPin(&DDRA, M2_IN3, OUTPUT);
	GPIO_InitPin(&DDRA, M2_IN4, OUTPUT);
	Motor_Stop();
}

void Motor_Stop(void) {
	GPIO_WritePin(&PORTA, M1_IN1, LOW);
	GPIO_WritePin(&PORTA, M1_IN2, LOW);
	GPIO_WritePin(&PORTA, M2_IN3, LOW);
	GPIO_WritePin(&PORTA, M2_IN4, LOW);
}

void Motor_Forward(void) {
	GPIO_WritePin(&PORTA, M1_IN1, HIGH);
	GPIO_WritePin(&PORTA, M1_IN2, LOW);
	GPIO_WritePin(&PORTA, M2_IN3, HIGH);
	GPIO_WritePin(&PORTA, M2_IN4, LOW);
}

void Motor_Backward(void) {
	GPIO_WritePin(&PORTA, M1_IN1, LOW);
	GPIO_WritePin(&PORTA, M1_IN2, HIGH);
	GPIO_WritePin(&PORTA, M2_IN3, LOW);
	GPIO_WritePin(&PORTA, M2_IN4, HIGH);
}

void Motor_Left(void) {
	GPIO_WritePin(&PORTA, M1_IN1, LOW);
	GPIO_WritePin(&PORTA, M1_IN2, HIGH);
	GPIO_WritePin(&PORTA, M2_IN3, HIGH);
	GPIO_WritePin(&PORTA, M2_IN4, LOW);
}

void Motor_Right(void) {
	GPIO_WritePin(&PORTA, M1_IN1, HIGH);
	GPIO_WritePin(&PORTA, M1_IN2, LOW);
	GPIO_WritePin(&PORTA, M2_IN3, LOW);
	GPIO_WritePin(&PORTA, M2_IN4, HIGH);
}
