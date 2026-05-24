/*
 * File: m400_usFanGetDutyPermille.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading fan PWM duty in permille.
 * License: MIT
 */
#ifndef M400_USFANGETDUTYPERMILLE_H
#define M400_USFANGETDUTYPERMILLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

uint16_t M400_usFanGetDutyPermille(TIM_HandleTypeDef *xTimer,
                                   uint32_t uiChannel,
                                   uint32_t uiTimerPeriod,
                                   bool bActiveLow);

#endif
