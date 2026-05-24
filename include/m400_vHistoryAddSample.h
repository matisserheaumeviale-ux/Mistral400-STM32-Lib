/*
 * File: m400_vHistoryAddSample.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for adding a sample to a uint16_t history buffer.
 * License: MIT
 */
#ifndef M400_VHISTORYADDSAMPLE_H
#define M400_VHISTORYADDSAMPLE_H

#include <stdint.h>

void M400_vHistoryAddSample(uint16_t *pusBuffer,
                            uint32_t uiBufferSize,
                            uint32_t *puiWriteIndex,
                            uint16_t usSample);

#endif
