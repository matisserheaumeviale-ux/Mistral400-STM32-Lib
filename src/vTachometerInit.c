/* =============================================================================================
 * Function      : vTachometerInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vTachometerInit.
 * RELATED FILE  : src/vTachometerInit.c
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
#include "vTachometerInit.h"

#include <stddef.h>

void vTachometerInit(Tachometer_t *pxTachometer)
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
