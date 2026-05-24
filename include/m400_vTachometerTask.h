/*
 * File: m400_vTachometerTask.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for updating a tachometer context.
 * License: MIT
 */
#ifndef M400_VTACHOMETERTASK_H
#define M400_VTACHOMETERTASK_H

#include "m400_types.h"
#include <stdint.h>

void M400_vTachometerTask(M400_Tachometer_t *pxTachometer,
                          uint32_t uiNowMs,
                          uint32_t uiTimeoutMs,
                          uint32_t uiTimerFrequencyHz,
                          uint32_t uiPulsesPerRevolution);

#endif
