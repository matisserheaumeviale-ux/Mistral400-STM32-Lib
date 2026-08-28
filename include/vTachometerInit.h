/* =============================================================================================
 * Function      : vTachometerInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vTachometerInit.
 * RELATED FILE  : include/vTachometerInit.h
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
#ifndef VTACHOMETERINIT_H
#define VTACHOMETERINIT_H

#include "types.h"

void vTachometerInit(Tachometer_t *pxTachometer);

#endif
