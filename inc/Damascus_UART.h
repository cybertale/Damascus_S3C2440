#ifndef __DAMASCUS_UART_H
#define __DAMASCUS_UART_H

#include "s3c2440.h"
#include <stdint.h>

extern void Damascus_UART_Init_Polling(UART_TypeDef *UARTx, uint32_t Baudrate); 
void Damascus_UART_SendString(UART_TypeDef *UARTx, const char *fmt, ...);
extern void Damascus_UART_SendBuff(UART_TypeDef *UARTx, uint8_t *buff, uint16_t count);
extern void assertFailed(char *str, char *file, int line);
#endif
