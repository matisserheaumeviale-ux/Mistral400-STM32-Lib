/*
 * File: m400_vLEDSet.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for setting a GPIO LED state.
 * License: MIT
 */
#ifndef M400_VLEDSET_H
#define M400_VLEDSET_H

#include "m400_types.h"
#include <stdint.h>

void M400_vLEDSet(M400_LED_t *pxLED, uint8_t ucState);

#endif
