/*
 * File: m400_vTachometerRegisterPulse.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for registering one tachometer capture edge.
 * License: MIT
 */
#ifndef M400_VTACHOMETERREGISTERPULSE_H
#define M400_VTACHOMETERREGISTERPULSE_H

#include "m400_types.h"
#include <stdint.h>

void M400_vTachometerRegisterPulse(M400_Tachometer_t *pxTachometer,
                                   uint32_t uiCaptureTick,
                                   uint32_t uiNowMs,
                                   uint32_t uiTimerMaxTick);

#endif
