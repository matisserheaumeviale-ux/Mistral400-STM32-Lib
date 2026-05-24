/*
 * File: m400_vUARTCommandInit.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for initializing a UART command context.
 * License: MIT
 */
#ifndef M400_VUARTCOMMANDINIT_H
#define M400_VUARTCOMMANDINIT_H

#include "m400_types.h"

void M400_vUARTCommandInit(M400_UARTCommand_t *pxCommand, UART_HandleTypeDef *xUart);

#endif
