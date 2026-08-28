/* =============================================================================================
 * Function      : ucClampU8
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucClampU8.
 * RELATED FILE  : src/ucClampU8.c
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
#include "ucClampU8.h"

uint8_t ucClampU8(uint8_t ucValue, uint8_t ucMinimum, uint8_t ucMaximum)
{
  if (ucMinimum > ucMaximum)
  {
    uint8_t ucSwap = ucMinimum;
    ucMinimum = ucMaximum;
    ucMaximum = ucSwap;
  }

  if (ucValue < ucMinimum)
  {
    return ucMinimum;
  }

  if (ucValue > ucMaximum)
  {
    return ucMaximum;
  }

  return ucValue;
}
