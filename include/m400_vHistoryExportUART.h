/*
 * File: m400_vHistoryExportUART.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for exporting a uint16_t history buffer over UART.
 * License: MIT
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
