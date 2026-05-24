/*
 * File: m400_vUARTPrintString.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for transmitting a string over UART.
 * License: MIT
 */
#ifndef M400_VUARTPRINTSTRING_H
#define M400_VUARTPRINTSTRING_H

#include "main.h"
#include <stdint.h>

void M400_vUARTPrintString(UART_HandleTypeDef *xUart,
                           const char *pcText,
                           uint32_t uiTimeoutMs);

#endif
