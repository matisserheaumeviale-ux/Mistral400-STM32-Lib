/*
 * File: m400_usReadADC.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading an averaged STM32 HAL ADC value.
 * License: MIT
 */
#ifndef M400_USREADADC_H
#define M400_USREADADC_H

#include "main.h"
#include <stdint.h>

uint16_t M400_usReadADC(ADC_HandleTypeDef *xAdc,
                        uint32_t uiChannel,
                        uint32_t uiRank,
                        uint32_t uiSamplingTime,
                        uint8_t ucSampleCount,
                        uint32_t uiPollTimeoutMs);

#endif
