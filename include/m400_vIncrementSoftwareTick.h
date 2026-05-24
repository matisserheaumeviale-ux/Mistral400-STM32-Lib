/*
 * File: m400_vIncrementSoftwareTick.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for incrementing a bounded software tick.
 * License: MIT
 */
#ifndef M400_VINCREMENTSOFTWARETICK_H
#define M400_VINCREMENTSOFTWARETICK_H

#include <stdint.h>

void M400_vIncrementSoftwareTick(uint32_t *puiTick, uint32_t uiMaxValue);

#endif
