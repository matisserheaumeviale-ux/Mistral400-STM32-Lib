/* =============================================================================================
 * Function      : ucButtonReadRaw
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucButtonReadRaw.
 * RELATED FILE  : src/ucButtonReadRaw.c
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
#include "ucButtonReadRaw.h"

#include <stddef.h>

uint8_t ucButtonReadRaw(const Button_t *pxButton)
{
  if ((pxButton == NULL) || (pxButton->xPort == NULL))
  {
    return OFF;
  }

  return (HAL_GPIO_ReadPin(pxButton->xPort, pxButton->usPin) == pxButton->xActiveState) ? ON : OFF;
}
