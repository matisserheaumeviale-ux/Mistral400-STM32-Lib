/* =============================================================================================
 * Function      : M400_vResetSoftwareCounter
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vResetSoftwareCounter.
 * RELATED FILE  : src/m400_vResetSoftwareCounter.c
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
#include "m400_vResetSoftwareCounter.h"

#include <stddef.h>

void M400_vResetSoftwareCounter(uint32_t *puiCounter)
{
  if (puiCounter != NULL)
  {
    *puiCounter = 0UL;
  }
}
