/*
 * File: m400_vFanStop.c
 * Author: Matisse Rhéaume Viale
 * Description: Stops one fan by applying zero duty.
 * License: MIT
 */
#include "m400_vFanStop.h"

#include "m400_vFanSetDutyPermille.h"

void M400_vFanStop(TIM_HandleTypeDef *xTimer,
                   uint32_t uiChannel,
                   uint32_t uiTimerPeriod,
                   bool bActiveLow)
{
  M400_vFanSetDutyPermille(xTimer, uiChannel, uiTimerPeriod, 0U, bActiveLow);
}
