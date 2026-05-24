/*
 * File: m400_bIsUARTDataAvailable.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for non-blocking UART byte polling.
 * License: MIT
 */
#ifndef M400_BISUARTDATAAVAILABLE_H
#define M400_BISUARTDATAAVAILABLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

bool M400_bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData);

#endif
