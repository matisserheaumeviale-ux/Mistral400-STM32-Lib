/* =============================================================================================
 * Function      : M400_vTachometerInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vTachometerInit.
 * RELATED FILE  : include/m400_vTachometerInit.h
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
#ifndef M400_VTACHOMETERINIT_H
#define M400_VTACHOMETERINIT_H

#include "m400_types.h"

void M400_vTachometerInit(M400_Tachometer_t *pxTachometer);

#endif
