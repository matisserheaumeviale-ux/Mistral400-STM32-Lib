/* =============================================================================================
 * Function      : vLCDClearLine
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLCDClearLine.
 * RELATED FILE  : include/vLCDClearLine.h
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
#ifndef VLCDCLEARLINE_H
#define VLCDCLEARLINE_H

#include <stdint.h>

void vLCDClearLine(uint8_t ucRow, uint8_t ucWidth);

#endif
