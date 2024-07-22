#include "servo.h"

Servo :: Servo(pinStruct_t &servoPin,
								TIM_TypeDef* Timx ,
								uint8_t gpioAFselectTimx,
								uint8_t pwmChannel)
{
	_pwmChannel = pwmChannel;
	//GPIO config
	GPIO_InitTypeDef Gpio_InitStruct ={};
	Gpio_InitStruct.Pin = servoPin.pin;
	Gpio_InitStruct.Pull =GPIO_NOPULL;
	Gpio_InitStruct.Mode =GPIO_MODE_AF_PP;
	Gpio_InitStruct.Speed=GPIO_SPEED_FREQ_LOW;
  Gpio_InitStruct.Alternate =gpioAFselectTimx;
  HAL_GPIO_Init(servoPin.port,&Gpio_InitStruct);		
	//Timer config
		
	TIM_MasterConfigTypeDef sMasterConfig = {0};
	TIM_OC_InitTypeDef sConfigOC = {0};
  htim.Instance = Timx;
  htim.Init.Prescaler = 10 - 1;
	htim.Init.CounterMode =TIM_COUNTERMODE_UP;
	htim.Init.Period =32000 - 1 ;
	htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	htim.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  HAL_TIM_PWM_Init(&htim);
	sConfigOC.OCMode = TIM_OCMODE_PWM1;
	sConfigOC.Pulse =SERVO_MIDPOSITION;
	sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
	sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
	HAL_TIM_PWM_ConfigChannel(&htim, &sConfigOC ,pwmChannel);
	
	HAL_TIM_PWM_Start(&htim,pwmChannel);
	
}

void Servo :: turnShaft(uint32_t position)
{
	__HAL_TIM_SET_COMPARE(&htim,_pwmChannel, position);
 
}