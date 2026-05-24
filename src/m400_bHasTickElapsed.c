/* =============================================================================================
 * Function      : M400_bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_bHasTickElapsed.
 * RELATED FILE  : src/m400_bHasTickElapsed.c
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
#include "m400_bHasTickElapsed.h"

bool M400_bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks)
{
  return ((uint32_t)(uiNowTick - uiPreviousTick) >= uiIntervalTicks);
}
