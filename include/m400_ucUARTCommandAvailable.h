/*
 * File: m400_ucUARTCommandAvailable.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for polling a UART command context.
 * License: MIT
 */
#ifndef M400_UCUARTCOMMANDAVAILABLE_H
#define M400_UCUARTCOMMANDAVAILABLE_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucUARTCommandAvailable(M400_UARTCommand_t *pxCommand);

#endif
