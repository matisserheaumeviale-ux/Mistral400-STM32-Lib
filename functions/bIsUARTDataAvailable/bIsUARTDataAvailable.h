/* =============================================================================================
 * Function      : bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for bIsUARTDataAvailable.
 * RELATED FILE  : include/bIsUARTDataAvailable.h
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
#ifndef BISUARTDATAAVAILABLE_H
#define BISUARTDATAAVAILABLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

bool bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData);

#endif
