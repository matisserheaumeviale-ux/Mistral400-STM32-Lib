/*
 * File: m400_vLCDClearLine.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for clearing one character LCD line.
 * License: MIT
 */
#ifndef M400_VLCDCLEARLINE_H
#define M400_VLCDCLEARLINE_H

#include <stdint.h>

void M400_vLCDClearLine(uint8_t ucRow, uint8_t ucWidth);

#endif
