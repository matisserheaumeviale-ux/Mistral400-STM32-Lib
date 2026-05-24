/*
 * File: m400_vLEDInit.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for initializing a GPIO LED context.
 * License: MIT
 */
#ifndef M400_VLEDINIT_H
#define M400_VLEDINIT_H

#include "m400_types.h"
#include <stdint.h>

void M400_vLEDInit(M400_LED_t *pxLED,
                   GPIO_TypeDef *xPort,
                   uint16_t usPin,
                   GPIO_PinState xActiveState);

#endif
