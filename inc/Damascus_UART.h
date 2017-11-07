#ifndef __DAMASCUS_UART_H
#define __DAMASCUS_UART_H

#include "s3c2440.h"
#include <stdint.h>

typedef enum{
	UART0,
	UART1,
	UART2
}UART_PORT;

extern void Damascus_UART_Init_Polling(UART_PORT port, uint32_t Baudrate); 
void Damascus_UART_SendString(UART_PORT port, const char *fmt, ...);
extern void Damascus_UART_SendBuff(UART_PORT port, uint8_t *buff, uint16_t count);
extern void assertFailed(char *str, char *file, int line);
#endif
