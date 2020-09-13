#include <stdio.h>
#include "TM4C123GH6PM_Q.h"
#include "bsp.h"




int main(){
		
		volatile uint8_t state_sw1, state_sw2;
	
		gpiox_clock_ahb_enable(GPIOF_CLOCK_AHB);
	 
		GPIOF_AHB->LOCK =0x4C4F434B;                                /* Disable lock on PF4 */
		GPIOF_AHB->CR |= 1;                                         /* commit the change to enable RW on PF0 */
		GPIOF_AHB->PUR|=SW1;					                              /* Enable pull up for SW1 */
		GPIOF_AHB->PDR | SW2;
		GPIOF_AHB->DEN |=(SW1 | RED_LED | SW2|GREEN_LED|BLUE_LED);  /*This enable GPIOF pin 0 for digital I/O */
		GPIOF_AHB->DIR &=(~SW1 & ~SW2);                             /*This enable GPIOF pin 0 and 4 for input*/
		GPIOF_AHB->DIR|=RED_LED|GREEN_LED|BLUE_LED;
	
		
		while(1){
				state_sw1 = GPIOF_AHB->DATA_Bits[SW1] & SW1;
			  state_sw2 = GPIOF_AHB->DATA_Bits[SW2] & SW2;
			
				if(state_sw1 == 0){
					  GPIOF_AHB->DATA_Bits[RED_LED] |= RED_LED;
						delay();
						GPIOF_AHB->DATA_Bits[GREEN_LED] |= GREEN_LED;
						delay(); 
						
				}
				if(state_sw2==0){
					  GPIOF_AHB->DATA_Bits[GREEN_LED] |= GREEN_LED;
				}
				else{
					  GPIOF_AHB->DATA_Bits[RED_LED] &= ~RED_LED;
					  GPIOF_AHB->DATA_Bits[GREEN_LED] &= ~GREEN_LED;
				}
			}
	
		return 0;
}
