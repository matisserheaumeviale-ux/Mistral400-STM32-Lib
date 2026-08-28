/* =============================================================================================
 * Function      : bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for bHasTickElapsed.
 * RELATED FILE  : include/bHasTickElapsed.h
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * à remplir
 * POINTER MANAGEMENT :
 * à remplir
 * =============================================================================================
 * Expected Result:
 * à remplir
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
