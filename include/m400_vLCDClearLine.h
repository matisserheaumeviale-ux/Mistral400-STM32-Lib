/* =============================================================================================
 * Function      : M400_vLCDClearLine
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vLCDClearLine.
 * RELATED FILE  : include/m400_vLCDClearLine.h
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
#ifndef M400_VLCDCLEARLINE_H
#define M400_VLCDCLEARLINE_H

#include <stdint.h>

void M400_vLCDClearLine(uint8_t ucRow, uint8_t ucWidth);

#endif
