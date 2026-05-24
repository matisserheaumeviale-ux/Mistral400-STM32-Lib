/*
 * File: m400_vFanStopAll.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for stopping multiple fan PWM channels.
 * License: MIT
 */
#ifndef M400_VFANSTOPALL_H
#define M400_VFANSTOPALL_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void M400_vFanStopAll(TIM_HandleTypeDef *xTimer,
                      const uint32_t *puiChannels,
                      uint8_t ucChannelCount,
                      uint32_t uiTimerPeriod,
                      bool bActiveLow);

#endif
