/* =============================================================================================
 * Function      : vUARTCommandInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vUARTCommandInit.
 * RELATED FILE  : include/vUARTCommandInit.h
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
#ifndef VUARTCOMMANDINIT_H
#define VUARTCOMMANDINIT_H

#include "types.h"

void vUARTCommandInit(UARTCommand_t *pxCommand, UART_HandleTypeDef *xUart);

#endif
