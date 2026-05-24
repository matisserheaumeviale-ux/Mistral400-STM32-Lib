/*
 * File: m400_ucClampU8.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for clamping an unsigned 8-bit value.
 * License: MIT
 */
#ifndef M400_UCCLAMPU8_H
#define M400_UCCLAMPU8_H

#include <stdint.h>

uint8_t M400_ucClampU8(uint8_t ucValue, uint8_t ucMinimum, uint8_t ucMaximum);

#endif
