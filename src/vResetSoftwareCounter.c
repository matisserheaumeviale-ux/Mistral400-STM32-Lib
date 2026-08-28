/* =============================================================================================
 * Function      : vResetSoftwareCounter
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vResetSoftwareCounter.
 * RELATED FILE  : src/vResetSoftwareCounter.c
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
#include "vResetSoftwareCounter.h"

#include <stddef.h>

void vResetSoftwareCounter(uint32_t *puiCounter)
{
  if (puiCounter != NULL)
  {
    *puiCounter = 0UL;
  }
}
