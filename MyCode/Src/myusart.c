#include "myusart.h"
#include "tim.h"
#include "mytim.h"
#include "myled.h"


uint8_t txBuff[TX_USART1_BUFF_SIZE];
uint8_t rxBuff[RX_USART1_BUFF_SIZE];

uint8_t rxBuffByte;
uint8_t rxLenBytes;

uint8_t rxFlag;



void MY_USART1_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  HAL_UART_Transmit(&MY_USART_TX_PORT, pData, Size, Timeout);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  if(rxLenBytes < RX_USART_MAX)
  {
	if(rxInit == rxFlag)
	{
	  rxFlag = rxStart;     //标记开始接收字节
	  rxBuff[rxLenBytes++] = rxBuffByte;
	  __HAL_TIM_SET_COUNTER(&MY_TIMx_INC_PORT, 0);
	  HAL_TIM_Base_Start_IT(&MY_TIMx_INC_PORT);
	}
	else if(rxStart == rxFlag)
	{
	  rxBuff[rxLenBytes++] = rxBuffByte;
	  HAL_TIM_Base_Stop_IT(&MY_TIMx_INC_PORT);
	  __HAL_TIM_SET_COUNTER(&MY_TIMx_INC_PORT, 0);  //清除定时器计数
	  HAL_TIM_Base_Start_IT(&MY_TIMx_INC_PORT);
	}
  }
  else
  {
	rxFlag = rxFinish;
	rxBuff[rxLenBytes] = '\0'; //最多接收255个字节，最后一个是'\0'
	HAL_TIM_Base_Stop(&MY_TIMx_INC_PORT);  //关闭定时器
  }
  HAL_UART_Receive_IT(&MY_USART_RX_PORT, &rxBuffByte, 1);
}
