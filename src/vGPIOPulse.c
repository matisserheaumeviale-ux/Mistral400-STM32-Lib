/* =============================================================================================
 * Function      : vGPIOPulse
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vGPIOPulse.
 * RELATED FILE  : src/vGPIOPulse.c
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
#include "vGPIOPulse.h"

#include <stddef.h>

void vGPIOPulse(GPIO_TypeDef *xCommandPort,
                     uint16_t usCommandPin,
                     GPIO_PinState xActiveState,
                     GPIO_PinState xRestState,
                     uint32_t uiPulseMs,
                     uint32_t uiStabilizationMs)
{
  if (xCommandPort == NULL)
  {
    return;
  }

  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xRestState);
  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xActiveState);
  HAL_Delay(uiPulseMs);
  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xRestState);
  HAL_Delay(uiStabilizationMs);
}
