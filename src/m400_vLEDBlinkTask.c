/* =============================================================================================
 * Function      : M400_vLEDBlinkTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vLEDBlinkTask.
 * RELATED FILE  : src/m400_vLEDBlinkTask.c
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
#include "m400_vLEDBlinkTask.h"

#include "m400_vLEDSet.h"
#include "m400_vLEDToggle.h"

#include <stddef.h>

void M400_vLEDBlinkTask(M400_LED_t *pxLED,
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
    M400_vLEDSet(pxLED, M400_OFF);
    pxLED->uiLastToggleMs = uiNowMs;
    return;
  }

  if ((uint32_t)(uiNowMs - pxLED->uiLastToggleMs) >= uiPeriodMs)
  {
    pxLED->uiLastToggleMs = uiNowMs;
    M400_vLEDToggle(pxLED);
  }
}
