#include "Damascus_UART.h"
#include "Damascus_GPIO.h"
#include "vsprintf.h"
#include <stdarg.h>

/**
  * @brief  Assertion failed and waiting for DBG. 
  * @param  str: error message. 
  * @param  file: source file. 
  * @param  line: line number of code. 
  * @retval Index of the UARTx. 
  */
void assertFailed(char *str, char *file, int line)
{
	Damascus_UART_SendString(UART0, "%s, file: %s, line: %d", str, file, line); 
	while(1)
	{
	}
}

void Damascus_UART_Clock_IO_Init(UART_TypeDef *UARTx)
{
	if(UARTx == UART0)
	{
		Damascus_GPIO_Init(GPH, 2, GPIO_MODE_SPECIAL0);
		Damascus_GPIO_Init(GPH, 3, GPIO_MODE_SPECIAL0);
	}
	else if(UARTx == UART1)
	{
	}
	else if(UARTx == UART2)
	{
	}
#ifdef	Damascus_Assert
	else
	{
		assertFailed("UARTx error", __FILE__, __LINE__); 
	}
#endif
}

void Damascus_UART_Init_Polling(UART_TypeDef *UARTx, uint32_t Baudrate)
{
	Damascus_UART_Clock_IO_Init(UARTx);

	 UARTx->LCON |= (0x3 << 0); 
	 UARTx->CON |= ((0x1 << 0) | (0x1 << 2));
	 UARTx->BRDIV = (int)(50000000/(Baudrate << 4)) - 1;
	 UARTx->RXH = 0x00;
}

/**
  * @brief  Sending buffer using USARTx. 
  * @param  USARTx: where x can be (1..6) to select the peripheral.
  * @param  buff: pointing to the buffer to send. 
  * @param  count: the number of data we are going to send. 
  * @retval None
  */
void Damascus_UART_SendBuff(UART_TypeDef *UARTx, uint8_t *buff, uint16_t count)
{
	uint16_t i = 0;
#ifdef Damascus_Assert
//	if(!Damascus_UART_isInit[UARTx])
//		AssertFailed("Port not Initialized. ", __FILE__, __LINE__); 
#endif
	for(i = 0; i < count; i++)
	{
		while(!((UARTx->TRSTAT) & (0x1 << 2)));
		 UARTx->TXH = *buff;
		buff++;
	}
}

/**
  * @brief  Sending string using USARTx. 
  * @param  USARTx: where x can be (1..6) to select the peripheral.
  * @param  str: pointing to the str to send.
  * @retval None
  */
void Damascus_UART_SendString(UART_TypeDef *UARTx, const char *fmt, ...)
{
	char temp[50];   /* issue  */
	char *output = temp;
	va_list ap;

#ifdef Damascus_Assert
/*	if(!Damascus_UART_isInit[UARTx])
		AssertFailed("Port not Initialized. ", __FILE__, __LINE__);*/ 
#endif

	va_start(ap, fmt);
	vsprintf(temp, fmt, ap);
	va_end(ap);
	while(*output != '\0')
	{
		while(!((UARTx->TRSTAT) & (0x1 << 2)));
		 UARTx->TXH = *output;
		output++;
	}
}
