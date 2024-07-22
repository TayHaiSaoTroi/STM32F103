/*
Author : MinhTan
Date : 13/7/2024
Project : Servo RC Library
*/
#include "servo.h"
int main(void)
{
	HAL_Init();
	pinStruct_t servoPin = {GPIOB, GPIO_PIN_8};
	static Servo servo( servoPin, TIM4 , GPIO_AF2_TIM4 , TIM_CHANNEL_3);
	while(1)
	{
	servo.turnShaft(SERVO_MIDPOSITION);
	HAL_Delay(1000);
	servo.turnShaft(SERVO_LEFTPOSITION);
	HAL_Delay(1000);
	servo.turnShaft(SERVO_MIDPOSITION);
	HAL_Delay(1000);
	servo.turnShaft(SERVO_RIGHTPOSITION);
	HAL_Delay(1000);
	}
}
extern "C" void Systick_Handler(void)
{
 HAL_IncTick();
}
