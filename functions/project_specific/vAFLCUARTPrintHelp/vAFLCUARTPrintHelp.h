/* =============================================================================================
 * Function      : vAFLCUARTPrintHelp
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the AFLC UART help menu print helper.
 * RELATED FILE  : include/project_specific/vAFLCUARTPrintHelp.h
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
#ifndef VAFLCUARTPRINTHELP_H
#define VAFLCUARTPRINTHELP_H

#include "main.h"
#include <stdint.h>

void vAFLCUARTPrintHelp(UART_HandleTypeDef *xUart, uint32_t uiTimeoutMs);

#endif
