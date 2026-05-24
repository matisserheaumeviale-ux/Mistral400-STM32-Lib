/* =============================================================================================
 * Function      : M400_vUARTCommandInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vUARTCommandInit.
 * RELATED FILE  : include/m400_vUARTCommandInit.h
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
#ifndef M400_VUARTCOMMANDINIT_H
#define M400_VUARTCOMMANDINIT_H

#include "m400_types.h"

void M400_vUARTCommandInit(M400_UARTCommand_t *pxCommand, UART_HandleTypeDef *xUart);

#endif
