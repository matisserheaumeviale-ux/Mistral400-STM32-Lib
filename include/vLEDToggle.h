/* =============================================================================================
 * Function      : vLEDToggle
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLEDToggle.
 * RELATED FILE  : include/vLEDToggle.h
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
#ifndef VLEDTOGGLE_H
#define VLEDTOGGLE_H

#include "types.h"

void vLEDToggle(LED_t *pxLED);

#endif
