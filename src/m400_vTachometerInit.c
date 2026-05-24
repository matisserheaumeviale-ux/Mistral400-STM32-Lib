/*
 * File: m400_vTachometerInit.c
 * Author: Matisse Rhéaume Viale
 * Description: Clears all fields in a caller-owned tachometer context.
 * License: MIT
 */
#include "m400_vTachometerInit.h"

#include <stddef.h>

void M400_vTachometerInit(M400_Tachometer_t *pxTachometer)
{
  if (pxTachometer == NULL)
  {
    return;
  }

  pxTachometer->uiLastCaptureTick = 0UL;
  pxTachometer->uiPeriodTicks = 0UL;
  pxTachometer->uiLastPulseMs = 0UL;
  pxTachometer->uiRPM = 0UL;
  pxTachometer->ucHasCapture = 0U;
  pxTachometer->ucPendingPeriod = 0U;
  pxTachometer->ucSignalPresent = 0U;
}
