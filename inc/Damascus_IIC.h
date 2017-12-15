#ifndef __DAMASCUS_IIC_H
#define __DAMASCUS_IIC_H

#include "s3c2440.h"

extern void Damascus_IIC_Init(void);
extern void Damascus_IIC_WriteStart(uint8_t addr);
extern void Damascus_IIC_WriteStop(void);
extern void Damascus_IIC_WriteByte(uint8_t data);
extern void Damascus_IIC_ReadStart(uint8_t addr);
extern void Damascus_IIC_ReadStop(void);
extern uint8_t Damascus_IIC_ReadByte(uint8_t stopAck);

#endif
