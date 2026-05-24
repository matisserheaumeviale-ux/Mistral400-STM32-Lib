/* =============================================================================================
 * Function      : M400_vLEDSet
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vLEDSet.
 * RELATED FILE  : src/m400_vLEDSet.c
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
#include "m400_vLEDSet.h"

#include <stddef.h>

void M400_vLEDSet(M400_LED_t *pxLED, uint8_t ucState)
{
  GPIO_PinState xInactiveState = GPIO_PIN_RESET;
  GPIO_PinState xOutputState = GPIO_PIN_RESET;

  if ((pxLED == NULL) || (pxLED->xPort == NULL))
  {
    return;
  }

  xInactiveState = (pxLED->xActiveState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
  xOutputState = (ucState != M400_OFF) ? pxLED->xActiveState : xInactiveState;
  HAL_GPIO_WritePin(pxLED->xPort, pxLED->usPin, xOutputState);
  pxLED->ucState = (ucState != M400_OFF) ? M400_ON : M400_OFF;
}
