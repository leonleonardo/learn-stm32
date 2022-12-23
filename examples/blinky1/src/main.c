#include "stm32f4xx.h"

void delay(int ms)
{
    /* Software delay loop*/
    while(ms-- > 0)
    {
        volatile int i = 500;
        while(i-- > 0)
        {
            __ASM("nop");
        }
    }
}
void gpio_init(void)
{
    /* Initialize the peripheral clock to feed gpioc*/
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
    /* Initialize the PC13 as output*/
    GPIOC->MODER |= GPIO_MODER_MODER13_0;
}


int main()
{
    /*Initialize system peripherals */
    gpio_init();
    /*Super Loop */
    while(1)
    {
        delay(1000);
        GPIOC->ODR ^= GPIO_ODR_OD13_Msk;
    }

}