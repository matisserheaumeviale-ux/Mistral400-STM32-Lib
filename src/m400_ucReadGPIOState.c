/* =============================================================================================
 * Function      : M400_ucReadGPIOState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucReadGPIOState.
 * RELATED FILE  : src/m400_ucReadGPIOState.c
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
#include "m400_ucReadGPIOState.h"

#include <stddef.h>

uint8_t M400_ucReadGPIOState(GPIO_TypeDef *xPort,
                             uint16_t usPin,
                             GPIO_PinState xActiveState,
                             uint8_t ucDefaultState,
                             uint8_t ucUseRealFeedback)
{
  if (ucUseRealFeedback == 0U)
  {
    return ucDefaultState;
  }

  if (xPort == NULL)
  {
    return ucDefaultState;
  }

  return (HAL_GPIO_ReadPin(xPort, usPin) == xActiveState) ? M400_ON : M400_OFF;
}
