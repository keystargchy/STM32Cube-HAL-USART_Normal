#ifndef __MY_USART_H_
#define __MY_USART_H_


#include "usart.h"

#define MY_USART_TX_PORT    huart1
#define MY_USART_RX_PORT    huart1

#define TX_USART1_BUFF_SIZE    256
#define RX_USART1_BUFF_SIZE    256

#define RX_USART_MAX           255


typedef enum {
	rxInit = 0,
	rxStart,
	rxFinish
}RX_STATE;




extern uint8_t txBuff[TX_USART1_BUFF_SIZE];
extern uint8_t rxBuff[RX_USART1_BUFF_SIZE];
extern uint8_t rxBuffByte;
extern uint8_t rxLenBytes;
extern uint8_t rxFlag;


void MY_USART1_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);


#endif

