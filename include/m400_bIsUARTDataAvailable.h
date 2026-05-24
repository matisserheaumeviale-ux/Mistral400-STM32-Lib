/* =============================================================================================
 * Function      : M400_bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_bIsUARTDataAvailable.
 * RELATED FILE  : include/m400_bIsUARTDataAvailable.h
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
#ifndef M400_BISUARTDATAAVAILABLE_H
#define M400_BISUARTDATAAVAILABLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

bool M400_bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData);

#endif
