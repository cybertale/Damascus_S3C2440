#include "Damascus_IIC.h"
#include "Damascus_UART.h"
#include "Damascus_GPIO.h"

/* A typical write sequence would be WriteStart(Device address)->WriteByte(Register address)->WriteStop() 
 * Read process is pretty much the same. */

#define WaitBusy()   	while(!(IIC->CON & (0x1 << 4)))
#define ClearBusy() 	IIC->CON &=~ (0x1 << 4)
#define ClearLastBusy() IIC->CON &=~ ((0x1 << 4) | (0x1 << 7))

void Damascus_IIC_Init()
{
	GPE->CON &=~ ((0x1 << 30) | (0x1 << 28));
	GPE->CON |=  ((0x2 << 30) | (0x2 << 28));

	IIC->CON = (1 << 7) | (1 << 6) | (1 << 5) | (0xf << 0);
	IIC->STAT = 0x10;
	Damascus_UART_SendString(UART0, "IIC Initialized. \r\n");
}

void Damascus_IIC_WriteStart(uint8_t addr)
{
	IIC->DS = addr;
	IIC->STAT = 0xf0;
	WaitBusy();
}

void Damascus_IIC_WriteStop()
{
	uint8_t i, j;
	IIC->STAT = 0xd0;
	ClearBusy();
}

void Damascus_IIC_WriteByte(uint8_t data)
{
	IIC->DS = data;
	ClearBusy();
	WaitBusy();
}

void Damascus_IIC_ReadStart(uint8_t addr)
{
	uint8_t i;
	IIC->CON |= (1 << 7);
	IIC->DS = addr;
	IIC->STAT = 0xb0;
	ClearBusy();
}

void Damascus_IIC_ReadStop()
{
	IIC->STAT = 0x90;
	ClearBusy();
}

uint8_t Damascus_IIC_ReadByte(uint8_t stopAck)
{
	uint8_t data;
	if(stopAck)
		IIC->CON &=~ (0x1 << 7);
	WaitBusy();
	data = IIC->DS;
	ClearBusy();

	return data;
}
