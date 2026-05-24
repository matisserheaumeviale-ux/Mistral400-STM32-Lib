/* =============================================================================================
 * Function      : M400_vTachometerRegisterPulse
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vTachometerRegisterPulse.
 * RELATED FILE  : src/m400_vTachometerRegisterPulse.c
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * The function performs its task without affecting other parts of the program.
 * =============================================================================================
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
