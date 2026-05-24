/* =============================================================================================
 * Function      : M400_usFanGetDutyPermille
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_usFanGetDutyPermille.
 * RELATED FILE  : include/m400_usFanGetDutyPermille.h
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
#ifndef M400_USFANGETDUTYPERMILLE_H
#define M400_USFANGETDUTYPERMILLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

uint16_t M400_usFanGetDutyPermille(TIM_HandleTypeDef *xTimer,
                                   uint32_t uiChannel,
                                   uint32_t uiTimerPeriod,
                                   bool bActiveLow);

#endif
