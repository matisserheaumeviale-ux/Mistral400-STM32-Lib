/* =============================================================================================
 * Function      : vReadUARTCommand
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vReadUARTCommand.
 * RELATED FILE  : include/vReadUARTCommand.h
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
#ifndef VREADUARTCOMMAND_H
#define VREADUARTCOMMAND_H

#include "main.h"
#include <stdint.h>

void vReadUARTCommand(UART_HandleTypeDef *xUart,
                           uint8_t *pucCommand,
                           uint32_t uiTimeoutMs);

#endif
