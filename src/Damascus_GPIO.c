#include "Damascus_GPIO.h"

void Damascus_GPIO_Init(GPIO_TypeDef *GPx, uint8_t pin, uint8_t mode)
{
	if(GPx == GPA)
	{
		if(mode == GPIO_MODE_OUTPUT)
		{
			GPA->CON &=~ (1 << pin);
		}
		else if(mode == GPIO_MODE_SPECIAL0)
		{
			GPA->CON |= (1 << pin);
		}
	}
	else
	{

		if(mode == GPIO_MODE_INPUT)
		{
			GPx->CON &=~ (0x3 << (pin << 1));
		}
		else if(mode == GPIO_MODE_OUTPUT)
		{
			GPx->CON &=~ (0x3 << (pin << 1));
			GPx->CON |=  (0x1 << (pin << 1));
		}
		else if(mode == GPIO_MODE_SPECIAL0)
		{
			GPx->CON &=~ (0x3 << (pin << 1));
			GPx->CON |=  (0x2 << (pin << 1));
		}
		else if(mode == GPIO_MODE_SPECIAL1)
		{
#ifdef Damascus_Assert
			/*Pin filter. */
#endif
			GPx->CON |= (0x3 << (pin << 1));
		}
#ifdef Damascus_Assert
		else
		{
			assertFailed("mode error", __FILE__, __LINE__);
		}
#endif
	}
}

/* Task: some assert code for mode. */
void Damascus_GPIO_Set(GPIO_TypeDef *GPx, uint8_t pin, bool state)
{
	if(state)
	{
		GPx->DAT |=  (1 << pin);
	}
	else
	{
		GPx->DAT &=~ (1 << pin);
	}
}
