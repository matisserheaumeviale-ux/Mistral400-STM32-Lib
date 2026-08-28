/* =============================================================================================
 * Function      : vLEDBlinkTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vLEDBlinkTask.
 * RELATED FILE  : src/vLEDBlinkTask.c
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
#include "vLEDBlinkTask.h"

#include "vLEDSet.h"
#include "vLEDToggle.h"

#include <stddef.h>

void vLEDBlinkTask(LED_t *pxLED,
                        uint32_t uiNowMs,
                        uint32_t uiPeriodMs,
                        uint8_t ucEnabled)
{
  if (pxLED == NULL)
  {
    return;
  }

  if (ucEnabled == 0U)
  {
    vLEDSet(pxLED, OFF);
    pxLED->uiLastToggleMs = uiNowMs;
    return;
  }

  if ((uint32_t)(uiNowMs - pxLED->uiLastToggleMs) >= uiPeriodMs)
  {
    pxLED->uiLastToggleMs = uiNowMs;
    vLEDToggle(pxLED);
  }
}
