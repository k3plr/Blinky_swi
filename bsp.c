#include "bsp.h"
#include "TM4C123GH6PM_Q.h"


void delay(void){
    int volatile counter =0;

		while(counter < 10000000){
				counter++;
		}
}

void gpiox_clock_ahb_enable(uint8_t bit){
	 SYSCTL->RCGCGPIO |=bit;
	 SYSCTL->GPIOHBCTL |=bit;
}
