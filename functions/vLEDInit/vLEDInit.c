/* =============================================================================================
 * Function      : vLEDInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vLEDInit.
 * RELATED FILE  : src/vLEDInit.c
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
#include "vLEDInit.h"

#include "vLEDSet.h"

#include <stddef.h>

void vLEDInit(LED_t *pxLED,
                   GPIO_TypeDef *xPort,
                   uint16_t usPin,
                   GPIO_PinState xActiveState)
{
  if (pxLED == NULL)
  {
    return;
  }

  pxLED->xPort = xPort;
  pxLED->usPin = usPin;
  pxLED->xActiveState = xActiveState;
  pxLED->uiLastToggleMs = 0UL;
  pxLED->ucState = OFF;

  vLEDSet(pxLED, OFF);
}
