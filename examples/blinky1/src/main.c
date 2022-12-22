#include "stm32f4xx.h"

void delay(int ms)
{
    while(ms-- > 0)
    {
        volatile int i = 500;
        while(i-- > 0)
        {
            __ASM("nop");
        }
    }
}
void gpioc_clock_reset(void)
{
    RCC->AHB1RSTR |= RCC_AHB1RSTR_GPIOCRST;
}

void gpioc_clock_init(void)
{
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}


int main()
{
    gpioc_clock_init();
    GPIOC->MODER |= GPIO_MODER_MODER13_0;
    while(1)
    {
        delay(1000);
        GPIOC->ODR ^= GPIO_ODR_OD13_Msk;
    }

}