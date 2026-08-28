/* =============================================================================================
 * Function      : vIncrementSoftwareTick
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vIncrementSoftwareTick.
 * RELATED FILE  : include/vIncrementSoftwareTick.h
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
#ifndef VINCREMENTSOFTWARETICK_H
#define VINCREMENTSOFTWARETICK_H

#include <stdint.h>

void vIncrementSoftwareTick(uint32_t *puiTick, uint32_t uiMaxValue);

#endif
