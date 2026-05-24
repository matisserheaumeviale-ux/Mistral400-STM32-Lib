/*
 * File: m400_usFanGetDutyPermille.c
 * Author: Matisse Rhéaume Viale
 * Description: Converts a PWM compare value back to fan duty in permille.
 * License: MIT
 */
#include "m400_usFanGetDutyPermille.h"

#include <stddef.h>

#define M400_FAN_DUTY_MAX_PERMILLE 1000UL

uint16_t M400_usFanGetDutyPermille(TIM_HandleTypeDef *xTimer,
                                   uint32_t uiChannel,
                                   uint32_t uiTimerPeriod,
                                   bool bActiveLow)
{
  uint32_t uiCompare = 0UL;
  uint32_t uiDuty = 0UL;

  if ((xTimer == NULL) || (uiTimerPeriod == 0UL))
  {
    return 0U;
  }

  uiCompare = __HAL_TIM_GET_COMPARE(xTimer, uiChannel);
  if (uiCompare > uiTimerPeriod)
  {
    uiCompare = uiTimerPeriod;
  }

  uiDuty = (uiCompare * M400_FAN_DUTY_MAX_PERMILLE) / (uiTimerPeriod + 1UL);
  if (uiDuty > M400_FAN_DUTY_MAX_PERMILLE)
  {
    uiDuty = M400_FAN_DUTY_MAX_PERMILLE;
  }

  if (bActiveLow)
  {
    uiDuty = M400_FAN_DUTY_MAX_PERMILLE - uiDuty;
  }

  return (uint16_t)uiDuty;
}
