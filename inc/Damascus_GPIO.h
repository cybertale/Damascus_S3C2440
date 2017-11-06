#ifndef __DAMASCUS_GPIO_H
#define __DAMASCUS_GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "s3c2440.h"

typedef enum{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	GPIOJ
}GPIO_PORT;

typedef enum{
	GPIO_MODE_INPUT,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_SPECIAL1,
	GPIO_MODE_SPECIAL2
}GPIO_MODE;

extern unsigned long  __GPIODataRegs[];
extern unsigned long  __GPIOControlRegs[];
extern void Damascus_GPIO_Init(GPIO_PORT port, uint8_t pin, uint8_t mode);
extern void Damascus_GPIO_Set(GPIO_PORT port, uint8_t pin, bool state);

#endif

