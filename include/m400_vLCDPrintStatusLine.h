/* =============================================================================================
 * Function      : M400_vLCDPrintStatusLine
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vLCDPrintStatusLine.
 * RELATED FILE  : include/m400_vLCDPrintStatusLine.h
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
#ifndef M400_VLCDPRINTSTATUSLINE_H
#define M400_VLCDPRINTSTATUSLINE_H

#include <stdint.h>

void M400_vLCDPrintStatusLine(uint8_t ucRow,
                              const char *pcLabel,
                              uint16_t usValue,
                              const char *pcUnit,
                              uint8_t ucWidth);

#endif
