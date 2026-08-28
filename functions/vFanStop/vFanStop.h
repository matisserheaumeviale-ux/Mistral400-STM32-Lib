/* =============================================================================================
 * Function      : vFanStop
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vFanStop.
 * RELATED FILE  : include/vFanStop.h
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
#ifndef VFANSTOP_H
#define VFANSTOP_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void vFanStop(TIM_HandleTypeDef *xTimer,
                   uint32_t uiChannel,
                   uint32_t uiTimerPeriod,
                   bool bActiveLow);

#endif
