/*
 * File: m400_bHasTickElapsed.c
 * Author: Matisse Rhéaume Viale
 * Description: Tests whether a tick interval has elapsed with unsigned wrap support.
 * License: MIT
 */
#include "m400_bHasTickElapsed.h"

bool M400_bHasTickElapsed(uint32_t uiNowTick,
                          uint32_t uiPreviousTick,
                          uint32_t uiIntervalTicks)
{
  return ((uint32_t)(uiNowTick - uiPreviousTick) >= uiIntervalTicks);
}
