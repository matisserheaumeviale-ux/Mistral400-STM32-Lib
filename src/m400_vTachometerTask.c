/* =============================================================================================
 * Function      : M400_vTachometerTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vTachometerTask.
 * RELATED FILE  : src/m400_vTachometerTask.c
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
#include "m400_vTachometerTask.h"

#include "m400_uiTachometerComputeRPM.h"

#include <stddef.h>

void M400_vTachometerTask(M400_Tachometer_t *pxTachometer,
                          uint32_t uiNowMs,
                          uint32_t uiTimeoutMs,
                          uint32_t uiTimerFrequencyHz,
                          uint32_t uiPulsesPerRevolution)
{
  if (pxTachometer == NULL)
  {
    return;
  }

  if ((pxTachometer->ucHasCapture != 0U) &&
      ((uint32_t)(uiNowMs - pxTachometer->uiLastPulseMs) > uiTimeoutMs))
  {
    pxTachometer->uiRPM = 0UL;
    pxTachometer->ucSignalPresent = 0U;
    pxTachometer->ucPendingPeriod = 0U;
    return;
  }

  if (pxTachometer->ucPendingPeriod != 0U)
  {
    pxTachometer->uiRPM = M400_uiTachometerComputeRPM(pxTachometer->uiPeriodTicks,
                                                      uiTimerFrequencyHz,
                                                      uiPulsesPerRevolution);
    pxTachometer->ucPendingPeriod = 0U;
    pxTachometer->ucSignalPresent = 1U;
  }
}
