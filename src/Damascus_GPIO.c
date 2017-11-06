#include "Damascus_GPIO.h"

uint8_t __maxIndexOfPort[] = {
		24, //GPIOA
		10, //GPIOB
		15, //GPIOC
		15, //GPIOD
		15, //GPIOE
		7,  //GPIOF
		15, //GPIOG
		10, //GPIOH
		12  //GPIOJ
};

unsigned long __GPIOControlRegs[] = {
	GPACON,
	GPBCON,
	GPCCON,
	GPDCON,
	GPECON,
	GPFCON,
	GPGCON,
	GPHCON,
	GPJCON	
};

unsigned long  __GPIODataRegs[] = {
	GPADAT,
	GPBDAT,
	GPCDAT,
	GPDDAT,
	GPEDAT,
	GPFDAT,
	GPGDAT,
	GPHDAT,
	GPJDAT	
};

#ifdef Damascus_Assert
void Damascus_GPIO_AssertPinNumber(GPIO_PORT port, uint8_t pin)
{
/*	if(pin > __maxIndexOfPort[port])
		assertFailed()*/
}
#endif

void Damascus_GPIO_Init(GPIO_PORT port, uint8_t pin, uint8_t mode)
{

#ifdef Damascus_Assert
	Damscus_GPIO_AssertPinNumber(port, pin);
#endif
	if(port == GPIOA)
	{
		if(mode == GPIO_MODE_OUTPUT)
		{
			__IO GPACON &=~ (1 << pin);
		}
		else if(mode == GPIO_MODE_SPECIAL1)
		{
			__IO GPACON |= (1 << pin);
		}
#ifdef Damascus_Assert
		else
			assertFailed();
#endif
	}
	else
	{

		if(mode == GPIO_MODE_INPUT)
		{
			__IO __GPIOControlRegs[port] &=~ (0x3 << (pin << 1));
		}
		else if(mode == GPIO_MODE_OUTPUT)
		{
			__IO __GPIOControlRegs[port] &=~ (0x3 << (pin << 1));
			__IO __GPIOControlRegs[port] |=  (0x1 << (pin << 1));
		}
		else if(mode == GPIO_MODE_SPECIAL1)
		{
			__IO __GPIOControlRegs[port] &=~ (0x3 << (pin << 1));
			__IO __GPIOControlRegs[port] |=  (0x2 << (pin << 1));
		}
		else if(mode == GPIO_MODE_SPECIAL2)
		{
#ifdef Damascus_Assert
			/*Pin filter. */
#endif
			__IO __GPIOControlRegs[port] |= (0x3 << (pin << 1));
		}
#ifdef Damascus_Assert
		else
		{
			assertFailed();
		}
#endif
	}
#ifdef Damascus_Assert
	else
	{
		assertFailed();
	}
#endif
}

/* Task: some assert code for mode. */
void Damascus_GPIO_Set(GPIO_PORT port, uint8_t pin, bool state)
{
#ifdef Damascuc_Assert
	Damascus_GPIO_AssertPinNumber(port, pin);
#endif
	if(state)
	{
		__IO __GPIODataRegs[port] |=  (1 << pin);
	}
	else
	{
		__IO __GPIODataRegs[port] &=~ (1 << pin);
	}
}
