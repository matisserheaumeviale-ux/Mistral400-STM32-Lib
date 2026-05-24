/*
 * File: m400_vGPIOPulse.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for sending a timed GPIO pulse.
 * License: MIT
 */
#ifndef M400_VGPIOPULSE_H
#define M400_VGPIOPULSE_H

#include "main.h"
#include <stdint.h>

void M400_vGPIOPulse(GPIO_TypeDef *xCommandPort,
                     uint16_t usCommandPin,
                     GPIO_PinState xActiveState,
                     GPIO_PinState xRestState,
                     uint32_t uiPulseMs,
                     uint32_t uiStabilizationMs);

#endif
