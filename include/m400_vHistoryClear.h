/*
 * File: m400_vHistoryClear.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for clearing a uint16_t history buffer.
 * License: MIT
 */
#ifndef M400_VHISTORYCLEAR_H
#define M400_VHISTORYCLEAR_H

#include <stdint.h>

void M400_vHistoryClear(uint16_t *pusBuffer,
                        uint32_t uiBufferSize,
                        uint32_t *puiWriteIndex);

#endif
