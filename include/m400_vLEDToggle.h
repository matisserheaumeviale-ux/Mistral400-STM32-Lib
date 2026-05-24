/* =============================================================================================
 * Function      : M400_vLEDToggle
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vLEDToggle.
 * RELATED FILE  : include/m400_vLEDToggle.h
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
#ifndef M400_VLEDTOGGLE_H
#define M400_VLEDTOGGLE_H

#include "m400_types.h"

void M400_vLEDToggle(M400_LED_t *pxLED);

#endif
