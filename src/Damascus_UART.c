#include "Damascus_UART.h"
#include "Damascus_GPIO.h"
#include "vsprintf.h"
#include <stdarg.h>

unsigned long __UARTLineControlRegs[] = {
	ULCON0,
	ULCON1,
	ULCON2
};

unsigned long __UARTControlRegs[] = {
	UCON0,
	UCON1,
	UCON2
};

unsigned long __UARTBaudDivideRegs[] = {
	UBRDIV0,
	UBRDIV1,
	UBRDIV2
};

unsigned long __UARTReceiveBufferRegs[] = {
	URXH0,
	URXH1,
	URXH2
};

unsigned long __UARTTransmitBufferRegs[] = {
	UTXH0,
	UTXH1,
	UTXH2
};

unsigned long __UARTTRStatusRegs[] = {
	UTRSTAT0,
	UTRSTAT1,
	UTRSTAT2
};

/**
  * @brief  Assertion failed and waiting for DBG. 
  * @param  str: error message. 
  * @param  file: source file. 
  * @param  line: line number of code. 
  * @retval Index of the port. 
  */
void assertFailed(char *str, char *file, int line)
{
	Damascus_UART_SendString(UART0, "%s, file: %s, line: %d", str, file, line); 
	while(1)
	{
	}
}

void Damascus_UART_Clock_IO_Init(UART_PORT port)
{
	if(port == UART0)
	{
		Damascus_GPIO_Init(GPIOH, 2, GPIO_MODE_SPECIAL0);
		Damascus_GPIO_Init(GPIOH, 3, GPIO_MODE_SPECIAL0);
	}
	else if(port == UART1)
	{
	}
	else if(port == UART2)
	{
	}
#ifdef	Damascus_Assert
	else
	{
		assertFailed("port error", __FILE__, __LINE__); 
	}
#endif
}

void Damascus_UART_Init_Polling(UART_PORT port, uint32_t Baudrate)
{
	Damascus_UART_Clock_IO_Init(port);

	__IO __UARTLineControlRegs[port] |= (0x3 << 0); 
	__IO __UARTControlRegs[port] |= ((0x1 << 0) | (0x1 << 2));
	__IO __UARTBaudDivideRegs[port] = (int)(50000000/(Baudrate << 4)) - 1;
	__IO __UARTReceiveBufferRegs[port] = 0x00;
}

/**
  * @brief  Sending buffer using USARTx. 
  * @param  USARTx: where x can be (1..6) to select the peripheral.
  * @param  buff: pointing to the buffer to send. 
  * @param  count: the number of data we are going to send. 
  * @retval None
  */
void Damascus_UART_SendBuff(UART_PORT port, uint8_t *buff, uint16_t count)
{
	uint16_t i = 0;
#ifdef Damascus_Assert
//	if(!Damascus_UART_isInit[port])
//		AssertFailed("Port not Initialized. ", __FILE__, __LINE__); 
#endif
	for(i = 0; i < count; i++)
	{
		while(!((__IO __UARTTRStatusRegs[port]) & (0x1 << 2)));
		__IO __UARTTransmitBufferRegs[port] = *buff;
		buff++;
	}
}

/**
  * @brief  Sending string using USARTx. 
  * @param  USARTx: where x can be (1..6) to select the peripheral.
  * @param  str: pointing to the str to send.
  * @retval None
  */
void Damascus_UART_SendString(UART_PORT port, const char *fmt, ...)
{
	char temp[50];   /* issue  */
	char *output = temp;
	va_list ap;

#ifdef Damascus_Assert
/*	if(!Damascus_UART_isInit[port])
		AssertFailed("Port not Initialized. ", __FILE__, __LINE__);*/ 
#endif

	va_start(ap, fmt);
	vsprintf(temp, fmt, ap);
	va_end(ap);
	while(*output != '\0')
	{
		while(!((__IO __UARTTRStatusRegs[port]) & (0x1 << 2)));
		__IO __UARTTransmitBufferRegs[port] = *output;
		output++;
	}
}
