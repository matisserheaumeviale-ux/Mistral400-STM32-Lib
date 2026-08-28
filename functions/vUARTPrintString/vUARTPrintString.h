/* =============================================================================================
 * Function      : vUARTPrintString
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vUARTPrintString.
 * RELATED FILE  : include/vUARTPrintString.h
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
#ifndef VUARTPRINTSTRING_H
#define VUARTPRINTSTRING_H

#include "main.h"
#include <stdint.h>

void vUARTPrintString(UART_HandleTypeDef *xUart,
                           const char *pcText,
                           uint32_t uiTimeoutMs);

#endif
