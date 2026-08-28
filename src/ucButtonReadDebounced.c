/* =============================================================================================
 * Function      : ucButtonReadDebounced
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucButtonReadDebounced.
 * RELATED FILE  : src/ucButtonReadDebounced.c
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
#include "ucButtonReadDebounced.h"

#include <stddef.h>

uint8_t ucButtonReadDebounced(const Button_t *pxButton)
{
  if (pxButton == NULL)
  {
    return OFF;
  }

  return pxButton->ucStableState;
}
