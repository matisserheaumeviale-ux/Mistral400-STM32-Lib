/* =============================================================================================
 * Function      : vLCDPrintCentered
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLCDPrintCentered.
 * RELATED FILE  : include/vLCDPrintCentered.h
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
#ifndef VLCDPRINTCENTERED_H
#define VLCDPRINTCENTERED_H

#include <stdint.h>

void vLCDPrintCentered(uint8_t ucRow, const char *pcText, uint8_t ucWidth);

#endif
