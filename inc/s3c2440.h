#ifndef __s3c2440_H
#define __s3c2440_H

#include <stdint.h>

#define WTCON 		0x53000000
#define INTMSK 		0x4A000008
#define INTSUBMSK 	0x4A00001C

#define BWSCON 		0x48000000
#define BANKCON6 	0x4800001C
#define BANKCON7 	0x48000020
#define REFRESH 	0x48000024
#define BANKSIZE 	0x48000028
#define MRSRB6 		0x4800002C
#define MRSRB7 		0x48000030

#define ADDRESS_STACK_BASE 	0x33FF8000
#define ADDRESS_STACK_USER 	(ADDRESS_STACK_BASE - 0x3800)
#define ADDRESS_STACK_SVC 	(ADDRESS_STACK_BASE - 0x2800)
#define ADDRESS_STACK_UNDEF (ADDRESS_STACK_BASE - 0x2400)
#define ADDRESS_STACK_ABORT (ADDRESS_STACK_BASE - 0x2000)
#define ADDRESS_STACK_IRQ 	(ADDRESS_STACK_BASE - 0x1000)
#define ADDRESS_STACK_FIQ 	(ADDRESS_STACK_BASE - 0x0000)

#define MODE_USER 	0x10
#define MODE_FIQ 	0x11
#define MODE_IRQ 	0x12
#define MODE_SVC 	0x13
#define MODE_ABORT 	0x17
#define MODE_UNDEF 	0x1b
#define MODE_MASK 	0x1f
#define NOINT 		0xc0

/* GPIO Registers */

typedef struct {
	volatile uint32_t CON;
	volatile uint32_t DAT;
	volatile uint32_t UP;
}GPIO_TypeDef;

#define GPA 		((GPIO_TypeDef *)0x56000000)
#define GPB 		((GPIO_TypeDef *)0x56000010)
#define GPC 		((GPIO_TypeDef *)0x56000020)
#define GPD 		((GPIO_TypeDef *)0x56000030)
#define GPE 		((GPIO_TypeDef *)0x56000040)
#define GPF 		((GPIO_TypeDef *)0x56000050)
#define GPG 		((GPIO_TypeDef *)0x56000060)
#define GPH 		((GPIO_TypeDef *)0x56000070)
#define GPJ 		((GPIO_TypeDef *)0x560000d0)

/* UART Registers */

typedef struct {
	volatile uint32_t LCON;
	volatile uint32_t CON;
	volatile uint32_t FCON;
	volatile uint32_t MCON;
	volatile uint32_t TRSTAT;
	volatile uint32_t ERSTAT;
	volatile uint32_t FSTAT;
	volatile uint32_t MSTAT;
	volatile uint32_t TXH;
	volatile uint32_t RXH;
	volatile uint32_t BRDIV;
}UART_TypeDef;
#define UART0 		((UART_TypeDef *)0x50000000)
#define UART1 		((UART_TypeDef *)0x50004000)
#define UART2 		((UART_TypeDef *)0x50008000)

/* NAND Flash Controller Registers */
typedef struct {
	volatile uint32_t CONF;
	volatile uint32_t CONT;
	volatile uint32_t CMMD;
	volatile uint32_t ADDR;
	volatile uint32_t DATA;
	volatile uint32_t MECCD0;
	volatile uint32_t MECCD1;
	volatile uint32_t ECCD;
	volatile uint32_t STAT;
	volatile uint32_t ESTAT0;
	volatile uint32_t ESTAT1;
	volatile uint32_t MECC0;
	volatile uint32_t MECC1;
	volatile uint32_t SECC;
	volatile uint32_t SBLK;
	volatile uint32_t EBLK;
}NAND_TypeDef;

#define NAND 	((NAND_TypeDef *)0x4E000000)

/* IIC Registers */

typedef struct {
	volatile uint32_t CON;
	volatile uint32_t STAT;
	volatile uint32_t ADD;
	volatile uint32_t DS;
	volatile uint32_t CLC;
}IIC_TypeDef;

#define IIC 	((IIC_TypeDef *)0x54000000)

/* Clock and Power Management */

typedef struct {
	volatile uint32_t LOCKTIME;
	volatile uint32_t MPLL;
	volatile uint32_t UPLL;
	volatile uint32_t CLKCON;
	volatile uint32_t CLKSLOW;
	volatile uint32_t CLKDIVN;
}CLOCK_TypeDef;

#define CLOCK 	((CLOCK_TypeDef *)0x4C000014)

#define Damascus_Assert

#endif

