#ifndef BSP_H
#define BSP_H
#include <stdint.h>
void delay(void);

void gpiox_clock_ahb_enable(uint8_t bit);

/* LED AND SWITCH SETTING */
#define RED_LED 	(1U << 1)
#define BLUE_LED 	(1U << 2)
#define GREEN_LED (1U << 3)
#define SW1       (1U << 4)
#define SW2       (1U << 0)

/* CLOCK GATING & AHB PIN ENABLE */
#define GPIOF_CLOCK_AHB (1U << 5)
#define GPIOE_CLOCK_AHB (1U << 4)
#define GPIOD_CLOCK_AHB (1U << 3)
#define GPIOC_CLOCK_AHB (1U << 2)
#define GPIOB_CLOCK_AHB (1U << 1)
#define GPIOA_CLOCK_AHB (1U << 0)




#endif