/* =============================================================================================
 * Function      : ucClampU8
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucClampU8.
 * RELATED FILE  : include/ucClampU8.h
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
#ifndef UCCLAMPU8_H
#define UCCLAMPU8_H

#include <stdint.h>

uint8_t ucClampU8(uint8_t ucValue, uint8_t ucMinimum, uint8_t ucMaximum);

#endif
