/* =============================================================================================
 * Function      : bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for bHasTickElapsed.
 * RELATED FILE  : include/bHasTickElapsed.h
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
#ifndef BHASTICKELAPSED_H
#define BHASTICKELAPSED_H

#include <stdbool.h>
#include <stdint.h>

bool bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks);

#endif
