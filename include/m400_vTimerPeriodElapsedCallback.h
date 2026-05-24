/*
 * File: m400_vTimerPeriodElapsedCallback.h
 * Author: Matisse Rhéaume Viale
 * Description: Public helper for handling STM32 HAL timer period callbacks.
 * License: MIT
 */
#ifndef M400_VTIMERPERIODELAPSEDCALLBACK_H
#define M400_VTIMERPERIODELAPSEDCALLBACK_H

#include "main.h"
#include <stdint.h>

void M400_vTimerPeriodElapsedCallback(TIM_HandleTypeDef *xTimer,
                                      void *pxExpectedInstance,
                                      uint32_t *puiTick,
                                      uint32_t uiMaxValue);

#endif
