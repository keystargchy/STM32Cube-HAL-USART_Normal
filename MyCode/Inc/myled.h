/*
 * myled.h
 *
 *  Created on: 2019Äê3ÔÂ20ÈÕ
 *      Author: DELL
 */

#ifndef INC_MYLED_H_
#define INC_MYLED_H_

#define LEDn                             2

#define LED0_PIN                         GPIO_PIN_5             /* PB.05*/
#define LED0_GPIO_PORT                   GPIOB

#define LED1_PIN                         GPIO_PIN_5             /* PE.05*/
#define LED1_GPIO_PORT                   GPIOE

typedef enum
{
  LED0 = 0,
  LED1 = 1,
} Led_TypeDef;


void MY_LED_On(Led_TypeDef Led);
void MY_LED_Off(Led_TypeDef Led);
void MY_LED_Toggle(Led_TypeDef Led);



#endif /* INC_MYLED_H_ */
