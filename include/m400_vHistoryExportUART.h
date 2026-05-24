/* =============================================================================================
 * Function      : M400_vHistoryExportUART
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vHistoryExportUART.
 * RELATED FILE  : include/m400_vHistoryExportUART.h
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
#ifndef M400_VHISTORYEXPORTUART_H
#define M400_VHISTORYEXPORTUART_H

#include "main.h"
#include <stdint.h>

void M400_vHistoryExportUART(UART_HandleTypeDef *xUart,
                             const uint16_t *pusBuffer,
                             uint32_t uiSampleCount,
                             uint32_t uiTimeoutMs);

#endif
