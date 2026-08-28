/* =============================================================================================
 * Function      : vLEDSet
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vLEDSet.
 * RELATED FILE  : src/vLEDSet.c
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
#include "vLEDSet.h"

#include <stddef.h>

void vLEDSet(LED_t *pxLED, uint8_t ucState)
{
  GPIO_PinState xInactiveState = GPIO_PIN_RESET;
  GPIO_PinState xOutputState = GPIO_PIN_RESET;

  if ((pxLED == NULL) || (pxLED->xPort == NULL))
  {
    return;
  }

  xInactiveState = (pxLED->xActiveState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
  xOutputState = (ucState != OFF) ? pxLED->xActiveState : xInactiveState;
  HAL_GPIO_WritePin(pxLED->xPort, pxLED->usPin, xOutputState);
  pxLED->ucState = (ucState != OFF) ? ON : OFF;
}
