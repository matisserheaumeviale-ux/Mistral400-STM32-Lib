/* =============================================================================================
 * Function      : vLEDSet
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLEDSet.
 * RELATED FILE  : include/vLEDSet.h
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
#ifndef VLEDSET_H
#define VLEDSET_H

#include "types.h"
#include <stdint.h>

void vLEDSet(LED_t *pxLED, uint8_t ucState);

#endif
