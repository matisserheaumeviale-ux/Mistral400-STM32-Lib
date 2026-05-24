/*
 * File: m400_vLEDBlinkTask.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for non-blocking LED blink updates.
 * License: MIT
 */
#ifndef M400_VLEDBLINKTASK_H
#define M400_VLEDBLINKTASK_H

#include "m400_types.h"
#include <stdint.h>

void M400_vLEDBlinkTask(M400_LED_t *pxLED,
                        uint32_t uiNowMs,
                        uint32_t uiPeriodMs,
                        uint8_t ucEnabled);

#endif
