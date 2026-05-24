/*
 * File: m400_vReadUARTCommand.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading one UART command byte.
 * License: MIT
 */
#ifndef M400_VREADUARTCOMMAND_H
#define M400_VREADUARTCOMMAND_H

#include "main.h"
#include <stdint.h>

void M400_vReadUARTCommand(UART_HandleTypeDef *xUart,
                           uint8_t *pucCommand,
                           uint32_t uiTimeoutMs);

#endif
