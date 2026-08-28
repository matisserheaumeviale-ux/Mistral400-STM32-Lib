/* =============================================================================================
 * Function      : bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.1
 * =============================================================================================
 * DESCRIPTION :
 * Implements bHasTickElapsed.
 * RELATED FILE  : src/bHasTickElapsed.c
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * ???
 * =============================================================================================
 */
#include "bHasTickElapsed.h"

bool bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks)
{
  return ((uint32_t)(uiNowTick - uiPreviousTick) >= uiIntervalTicks);
}
