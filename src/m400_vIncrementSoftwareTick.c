/* =============================================================================================
 * Function      : M400_vIncrementSoftwareTick
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vIncrementSoftwareTick.
 * RELATED FILE  : src/m400_vIncrementSoftwareTick.c
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
#include "m400_vIncrementSoftwareTick.h"

#include <stddef.h>

void M400_vIncrementSoftwareTick(uint32_t *puiTick, uint32_t uiMaxValue)
{
  if (puiTick == NULL)
  {
    return;
  }

  if (*puiTick < uiMaxValue)
  {
    (*puiTick)++;
  }
}
