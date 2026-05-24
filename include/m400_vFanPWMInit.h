/*
 * File: m400_vFanPWMInit.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for starting a fan PWM channel.
 * License: MIT
 */
#ifndef M400_VFANPWMINIT_H
#define M400_VFANPWMINIT_H

#include "main.h"
#include <stdint.h>

void M400_vFanPWMInit(TIM_HandleTypeDef *xTimer, uint32_t uiChannel);

#endif
