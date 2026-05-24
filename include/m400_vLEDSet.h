/* =============================================================================================
 * Function      : M400_vLEDSet
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vLEDSet.
 * RELATED FILE  : include/m400_vLEDSet.h
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
#ifndef M400_VLEDSET_H
#define M400_VLEDSET_H

#include "m400_types.h"
#include <stdint.h>

void M400_vLEDSet(M400_LED_t *pxLED, uint8_t ucState);

#endif
