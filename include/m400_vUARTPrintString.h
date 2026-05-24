/* =============================================================================================
 * Function      : M400_vUARTPrintString
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vUARTPrintString.
 * RELATED FILE  : include/m400_vUARTPrintString.h
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
#ifndef M400_VUARTPRINTSTRING_H
#define M400_VUARTPRINTSTRING_H

#include "main.h"
#include <stdint.h>

void M400_vUARTPrintString(UART_HandleTypeDef *xUart,
                           const char *pcText,
                           uint32_t uiTimeoutMs);

#endif
