/* =============================================================================================
 * Function      : M400_ucButtonReadRaw
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucButtonReadRaw.
 * RELATED FILE  : src/m400_ucButtonReadRaw.c
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
#include "m400_ucButtonReadRaw.h"

#include <stddef.h>

uint8_t M400_ucButtonReadRaw(const M400_Button_t *pxButton)
{
  if ((pxButton == NULL) || (pxButton->xPort == NULL))
  {
    return M400_OFF;
  }

  return (HAL_GPIO_ReadPin(pxButton->xPort, pxButton->usPin) == pxButton->xActiveState) ? M400_ON : M400_OFF;
}
