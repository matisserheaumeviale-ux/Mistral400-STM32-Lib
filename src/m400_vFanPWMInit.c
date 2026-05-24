/*
 * File: m400_vFanPWMInit.c
 * Author: Matisse Rhéaume Viale
 * Description: Starts one STM32 HAL PWM channel for fan control.
 * License: MIT
 */
#include "m400_vFanPWMInit.h"

#include <stddef.h>

void M400_vFanPWMInit(TIM_HandleTypeDef *xTimer, uint32_t uiChannel)
{
  if (xTimer == NULL)
  {
    return;
  }

  (void)HAL_TIM_PWM_Start(xTimer, uiChannel);
}
