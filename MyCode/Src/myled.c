/*
 * myled.c
 *
 *  Created on: 2019Äê3ÔÂ20ÈÕ
 *      Author: DELL
 */

#include "main.h"
#include "myled.h"



GPIO_TypeDef* LED_PORT[LEDn] = {LED0_GPIO_PORT,
                                LED1_GPIO_PORT};

const uint16_t LED_PIN[LEDn] = {LED0_PIN,
                                LED1_PIN};




void MY_LED_On(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_RESET);
}


void MY_LED_Off(Led_TypeDef Led)
{
  HAL_GPIO_WritePin(LED_PORT[Led], LED_PIN[Led], GPIO_PIN_SET);
}


void MY_LED_Toggle(Led_TypeDef Led)
{
  HAL_GPIO_TogglePin(LED_PORT[Led], LED_PIN[Led]);
}


