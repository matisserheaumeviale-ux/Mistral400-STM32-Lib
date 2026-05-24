/*
 * File: m400_bHasTickElapsed.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for wrap-safe elapsed tick checks.
 * License: MIT
 */
#ifndef M400_BHASTICKELAPSED_H
#define M400_BHASTICKELAPSED_H

#include <stdbool.h>
#include <stdint.h>

bool M400_bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks);

#endif
