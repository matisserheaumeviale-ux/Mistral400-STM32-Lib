/* =============================================================================================
 * Function      : bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.1
 * =============================================================================================
 * DESCRIPTION :
 * Implements bHasTickElapsed.
 * RELATED FILE  : src/bHasTickElapsed.c
 * DEPENDENCIES  : none
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * none
 * POINTER MANAGEMENT :
 * none
 * =============================================================================================
 * Expected Result:
 * Returns true if the interval of ticks has elapsed, false otherwise.
 * =============================================================================================
 */
#include "bHasTickElapsed.h"

bool bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks)
{
  return ((uint32_t)(uiNowTick - uiPreviousTick) >= uiIntervalTicks);
}
