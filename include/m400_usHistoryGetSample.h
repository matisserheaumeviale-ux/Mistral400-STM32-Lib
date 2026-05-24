/*
 * File: m400_usHistoryGetSample.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading a sample from a uint16_t history buffer.
 * License: MIT
 */
#ifndef M400_USHISTORYGETSAMPLE_H
#define M400_USHISTORYGETSAMPLE_H

#include <stdint.h>

uint16_t M400_usHistoryGetSample(const uint16_t *pusBuffer,
                                 uint32_t uiBufferSize,
                                 uint32_t uiIndex);

#endif
