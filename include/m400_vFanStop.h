/*
 * File: m400_vFanStop.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for stopping one fan PWM channel.
 * License: MIT
 */
#ifndef M400_VFANSTOP_H
#define M400_VFANSTOP_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void M400_vFanStop(TIM_HandleTypeDef *xTimer,
                   uint32_t uiChannel,
                   uint32_t uiTimerPeriod,
                   bool bActiveLow);

#endif
