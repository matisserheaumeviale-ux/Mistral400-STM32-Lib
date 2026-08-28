/* =============================================================================================
 * Function      : vHistoryExportUART
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vHistoryExportUART.
 * RELATED FILE  : include/vHistoryExportUART.h
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
#ifndef VHISTORYEXPORTUART_H
#define VHISTORYEXPORTUART_H

#include "main.h"
#include <stdint.h>

void vHistoryExportUART(UART_HandleTypeDef *xUart,
                             const uint16_t *pusBuffer,
                             uint32_t uiSampleCount,
                             uint32_t uiTimeoutMs);

#endif
