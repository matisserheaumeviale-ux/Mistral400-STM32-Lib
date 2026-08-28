/* =============================================================================================
 * Function      : ucButtonReadRaw
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucButtonReadRaw.
 * RELATED FILE  : include/ucButtonReadRaw.h
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
#ifndef UCBUTTONREADRAW_H
#define UCBUTTONREADRAW_H

#include "types.h"
#include <stdint.h>

uint8_t ucButtonReadRaw(const Button_t *pxButton);

#endif
