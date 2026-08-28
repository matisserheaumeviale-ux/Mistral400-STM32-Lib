/* =============================================================================================
 * Function      : ucButtonReadDebounced
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucButtonReadDebounced.
 * RELATED FILE  : include/ucButtonReadDebounced.h
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
#ifndef UCBUTTONREADDEBOUNCED_H
#define UCBUTTONREADDEBOUNCED_H

#include "types.h"
#include <stdint.h>

uint8_t ucButtonReadDebounced(const Button_t *pxButton);

#endif
