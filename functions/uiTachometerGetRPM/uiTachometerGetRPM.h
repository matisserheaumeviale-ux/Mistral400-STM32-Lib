/* =============================================================================================
 * Function      : uiTachometerGetRPM
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for uiTachometerGetRPM.
 * RELATED FILE  : include/uiTachometerGetRPM.h
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
#ifndef UITACHOMETERGETRPM_H
#define UITACHOMETERGETRPM_H

#include "types.h"
#include <stdint.h>

uint32_t uiTachometerGetRPM(const Tachometer_t *pxTachometer);

#endif
