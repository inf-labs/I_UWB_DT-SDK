#ifndef __LED_H
#define __LED_H

#include "stm32f4xx.h"

#define LED_R(X)  (X==0)?GPIO_SetBits(GPIOB,GPIO_Pin_2):GPIO_ResetBits(GPIOB,GPIO_Pin_2)
#define LED_G(X)  (X==0)?GPIO_SetBits(GPIOB,GPIO_Pin_1):GPIO_ResetBits(GPIOB,GPIO_Pin_1)
#define LED_B(X)  (X==0)?GPIO_SetBits(GPIOB,GPIO_Pin_0):GPIO_ResetBits(GPIOB,GPIO_Pin_0)

#define LED_R_TOGGLE   GPIOB->ODR ^= GPIO_Pin_2;
#define LED_G_TOGGLE   GPIOB->ODR ^= GPIO_Pin_1;
#define LED_B_TOGGLE   GPIOB->ODR ^= GPIO_Pin_0;

#define LED_TOGGLE   GPIOC->ODR ^= GPIO_Pin_5;

#define  LED_TX_ON        GPIO_SetBits(GPIOC,GPIO_Pin_4)
#define  LED_TX_OFF       GPIO_ResetBits(GPIOC,GPIO_Pin_4)
#define  LED_TX_TOGGLE    GPIOC->ODR ^= GPIO_Pin_4

#define  LED_RX_ON        GPIO_SetBits(GPIOC,GPIO_Pin_5)
#define  LED_RX_OFF       GPIO_ResetBits(GPIOC,GPIO_Pin_5)
#define  LED_RX_TOGGLE    GPIOC->ODR ^= GPIO_Pin_5


//mc led
#define LED_LEFT(X)  (X==0)?GPIO_SetBits(GPIOC,GPIO_Pin_4):GPIO_ResetBits(GPIOC,GPIO_Pin_4)
#define LED_RIGHT(X)  (X==0)?GPIO_SetBits(GPIOC,GPIO_Pin_5):GPIO_ResetBits(GPIOC,GPIO_Pin_5)

#define LED_LEFT_TOGGLE   GPIOC->ODR ^= GPIO_Pin_4;
#define LED_RIGHT_TOGGLE   GPIOC->ODR ^= GPIO_Pin_5;

void LED_Init(void);

#endif



