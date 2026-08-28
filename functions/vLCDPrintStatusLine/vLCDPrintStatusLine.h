/* =============================================================================================
 * Function      : vLCDPrintStatusLine
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLCDPrintStatusLine.
 * RELATED FILE  : include/vLCDPrintStatusLine.h
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
#ifndef VLCDPRINTSTATUSLINE_H
#define VLCDPRINTSTATUSLINE_H

#include <stdint.h>

void vLCDPrintStatusLine(uint8_t ucRow,
                              const char *pcLabel,
                              uint16_t usValue,
                              const char *pcUnit,
                              uint8_t ucWidth);

#endif
