/* =============================================================================================
 * Function      : M400_ucButtonReadDebounced
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucButtonReadDebounced.
 * RELATED FILE  : src/m400_ucButtonReadDebounced.c
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
#include "m400_ucButtonReadDebounced.h"

#include <stddef.h>

uint8_t M400_ucButtonReadDebounced(const M400_Button_t *pxButton)
{
  if (pxButton == NULL)
  {
    return M400_OFF;
  }

  return pxButton->ucStableState;
}
