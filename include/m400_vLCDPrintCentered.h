/* =============================================================================================
 * Function      : M400_vLCDPrintCentered
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vLCDPrintCentered.
 * RELATED FILE  : include/m400_vLCDPrintCentered.h
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
#ifndef M400_VLCDPRINTCENTERED_H
#define M400_VLCDPRINTCENTERED_H

#include <stdint.h>

void M400_vLCDPrintCentered(uint8_t ucRow, const char *pcText, uint8_t ucWidth);

#endif
