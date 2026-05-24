/* =============================================================================================
 * Function      : M400_vTimerPeriodElapsedCallback
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vTimerPeriodElapsedCallback.
 * RELATED FILE  : include/m400_vTimerPeriodElapsedCallback.h
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
#ifndef M400_VTIMERPERIODELAPSEDCALLBACK_H
#define M400_VTIMERPERIODELAPSEDCALLBACK_H

#include "main.h"
#include <stdint.h>

void M400_vTimerPeriodElapsedCallback(TIM_HandleTypeDef *xTimer,
                                      void *pxExpectedInstance,
                                      uint32_t *puiTick,
                                      uint32_t uiMaxValue);

#endif
