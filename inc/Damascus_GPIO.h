#ifndef __DAMASCUS_GPIO_H
#define __DAMASCUS_GPIO_H

#include <stdint.h>
#include <stdbool.h>
#include "s3c2440.h"

typedef enum{
	GPIO_MODE_INPUT,
	GPIO_MODE_OUTPUT,
	GPIO_MODE_SPECIAL0,
	GPIO_MODE_SPECIAL1
}GPIO_MODE;

extern void Damascus_GPIO_Init(GPIO_TypeDef *GPx, uint8_t pin, uint8_t mode);
extern void Damascus_GPIO_Set(GPIO_TypeDef *GPx, uint8_t pin, bool state);

#endif

