/* =============================================================================================
 * Function      : M400_vFanSetDutyPermille
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vFanSetDutyPermille.
 * RELATED FILE  : include/m400_vFanSetDutyPermille.h
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
#ifndef M400_VFANSETDUTYPERMILLE_H
#define M400_VFANSETDUTYPERMILLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

void M400_vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
                              uint32_t uiChannel,
                              uint32_t uiTimerPeriod,
                              uint16_t usDutyPermille,
                              bool bActiveLow);

#endif
