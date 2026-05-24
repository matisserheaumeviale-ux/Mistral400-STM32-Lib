/*
 * File: m400_vFanSetDutyPermille.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for applying fan PWM duty in permille.
 * License: MIT
 */
#ifndef M400_VFANSETDUTYPERMILLE_H
#define M400_VFANSETDUTYPERMILLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void M400_vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
                              uint32_t uiChannel,
                              uint32_t uiTimerPeriod,
                              uint16_t usDutyPermille,
                              bool bActiveLow);

#endif
