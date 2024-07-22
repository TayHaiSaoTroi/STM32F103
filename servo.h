#ifndef SERVO_H
#define SERVO_H

#include "pinmap.h"

enum{
SERVO_RIGHTPOSITION = 1200,
SERVO_MIDPOSITION = 2250,
SERVO_LEFTPOSITION = 3350
};


class Servo
{
	private:
		TIM_HandleTypeDef htim;
		uint8_t _pwmChannel;
	public:
		Servo(pinStruct_t &servoPin,
         	TIM_TypeDef* Timx ,
	        uint8_t gpioAFselectTimx,
					uint8_t pwmChannel);
	void turnShaft(uint32_t position);

};

#endif // SERVO_H