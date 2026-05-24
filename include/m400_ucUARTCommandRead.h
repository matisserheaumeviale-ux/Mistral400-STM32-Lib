/*
 * File: m400_ucUARTCommandRead.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for consuming a latched UART command byte.
 * License: MIT
 */
#ifndef M400_UCUARTCOMMANDREAD_H
#define M400_UCUARTCOMMANDREAD_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucUARTCommandRead(M400_UARTCommand_t *pxCommand);

#endif
