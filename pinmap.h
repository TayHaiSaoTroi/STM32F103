#ifndef PINMAP_H
#define PINMAP_H


#include "stm32f4xx_hal.h"
typedef struct {
GPIO_TypeDef * port;
uint16_t pin;
}pinStruct_t ;



#endif /*PINMAP_H*/