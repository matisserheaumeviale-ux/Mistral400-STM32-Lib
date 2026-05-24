/*
 * File: m400_vTimerPeriodElapsedCallback.c
 * Author: Matisse Rhéaume Viale
 * Description: Increments a software tick when the expected timer elapsed.
 * License: MIT
 */
#include "m400_vTimerPeriodElapsedCallback.h"

#include "m400_vIncrementSoftwareTick.h"

#include <stddef.h>

void M400_vTimerPeriodElapsedCallback(TIM_HandleTypeDef *xTimer,
                                      void *pxExpectedInstance,
                                      uint32_t *puiTick,
                                      uint32_t uiMaxValue)
{
  if ((xTimer == NULL) || (pxExpectedInstance == NULL))
  {
    return;
  }

  if ((void *)xTimer->Instance == pxExpectedInstance)
  {
    M400_vIncrementSoftwareTick(puiTick, uiMaxValue);
  }
}
