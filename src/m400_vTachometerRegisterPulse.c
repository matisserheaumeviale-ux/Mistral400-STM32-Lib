/*
 * File: m400_vTachometerRegisterPulse.c
 * Author: Matisse Rhéaume Viale
 * Description: Stores a tachometer capture period with timer wrap handling.
 * License: MIT
 */
#include "m400_vTachometerRegisterPulse.h"

#include <stddef.h>

void M400_vTachometerRegisterPulse(M400_Tachometer_t *pxTachometer,
                                   uint32_t uiCaptureTick,
                                   uint32_t uiNowMs,
                                   uint32_t uiTimerMaxTick)
{
  uint32_t uiPeriodTicks = 0UL;

  if (pxTachometer == NULL)
  {
    return;
  }

  if (pxTachometer->ucHasCapture == 0U)
  {
    pxTachometer->uiLastCaptureTick = uiCaptureTick;
    pxTachometer->uiLastPulseMs = uiNowMs;
    pxTachometer->ucHasCapture = 1U;
    pxTachometer->ucSignalPresent = 1U;
    return;
  }

  if (uiCaptureTick >= pxTachometer->uiLastCaptureTick)
  {
    uiPeriodTicks = uiCaptureTick - pxTachometer->uiLastCaptureTick;
  }
  else
  {
    uiPeriodTicks = (uiTimerMaxTick - pxTachometer->uiLastCaptureTick) + uiCaptureTick + 1UL;
  }

  pxTachometer->uiLastCaptureTick = uiCaptureTick;
  pxTachometer->uiLastPulseMs = uiNowMs;

  if (uiPeriodTicks > 0UL)
  {
    pxTachometer->uiPeriodTicks = uiPeriodTicks;
    pxTachometer->ucPendingPeriod = 1U;
    pxTachometer->ucSignalPresent = 1U;
  }
}
