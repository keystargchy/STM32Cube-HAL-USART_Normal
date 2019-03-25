/*
 * mytim.c
 *
 *  Created on: 2019年3月20日
 *      Author: DELL
 */

#include "main.h"
#include "mytim.h"
#include "myled.h"
#include "myusart.h"



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  rxFlag = rxFinish;
  HAL_TIM_Base_Stop_IT(&MY_TIMx_INC_PORT);  //关闭定时器中断
}
