/*
 * File: m400_vFanSetDutyPermille.c
 * Author: Matisse Rhéaume Viale
 * Description: Applies a clamped fan PWM duty cycle in permille.
 * License: MIT
 */
#include "m400_vFanSetDutyPermille.h"

#include <stddef.h>

#define M400_FAN_DUTY_MAX_PERMILLE 1000U

void M400_vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
                              uint32_t uiChannel,
                              uint32_t uiTimerPeriod,
                              uint16_t usDutyPermille,
                              bool bActiveLow)
{
  uint32_t uiCompare = 0UL;
  uint32_t uiEffectiveDuty = usDutyPermille;

  if (xTimer == NULL)
  {
    return;
  }

  if (uiEffectiveDuty > M400_FAN_DUTY_MAX_PERMILLE)
  {
    uiEffectiveDuty = M400_FAN_DUTY_MAX_PERMILLE;
  }

  if (bActiveLow)
  {
    uiEffectiveDuty = M400_FAN_DUTY_MAX_PERMILLE - uiEffectiveDuty;
  }

  uiCompare = ((uiTimerPeriod + 1UL) * uiEffectiveDuty) / M400_FAN_DUTY_MAX_PERMILLE;
  if (uiCompare > uiTimerPeriod)
  {
    uiCompare = uiTimerPeriod;
  }

  __HAL_TIM_SET_COMPARE(xTimer, uiChannel, uiCompare);
}
