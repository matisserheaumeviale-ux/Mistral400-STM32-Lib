/* =============================================================================================
 * Function      : vFanSetDutyPermille
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vFanSetDutyPermille.
 * RELATED FILE  : include/vFanSetDutyPermille.h
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
#ifndef VFANSETDUTYPERMILLE_H
#define VFANSETDUTYPERMILLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
                              uint32_t uiChannel,
                              uint32_t uiTimerPeriod,
                              uint16_t usDutyPermille,
                              bool bActiveLow);

#endif
