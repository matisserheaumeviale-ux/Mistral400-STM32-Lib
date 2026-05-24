/* =============================================================================================
 * Function      : M400_vFanStopAll
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vFanStopAll.
 * RELATED FILE  : include/m400_vFanStopAll.h
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * The function performs its task without affecting other parts of the program.
 * =============================================================================================
 */
#ifndef M400_VFANSTOPALL_H
#define M400_VFANSTOPALL_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void M400_vFanStopAll(TIM_HandleTypeDef *xTimer,
                      const uint32_t *puiChannels,
                      uint8_t ucChannelCount,
                      uint32_t uiTimerPeriod,
                      bool bActiveLow);

#endif
