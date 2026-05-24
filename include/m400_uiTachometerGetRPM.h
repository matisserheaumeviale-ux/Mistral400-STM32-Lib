/* =============================================================================================
 * Function      : M400_uiTachometerGetRPM
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_uiTachometerGetRPM.
 * RELATED FILE  : include/m400_uiTachometerGetRPM.h
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
#ifndef M400_UITACHOMETERGETRPM_H
#define M400_UITACHOMETERGETRPM_H

#include "m400_types.h"
#include <stdint.h>

uint32_t M400_uiTachometerGetRPM(const M400_Tachometer_t *pxTachometer);

#endif
