/* =============================================================================================
 * Function      : M400_bHasTickElapsed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_bHasTickElapsed.
 * RELATED FILE  : include/m400_bHasTickElapsed.h
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
#ifndef M400_BHASTICKELAPSED_H
#define M400_BHASTICKELAPSED_H

#include <stdbool.h>
#include <stdint.h>

bool M400_bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks);

#endif
