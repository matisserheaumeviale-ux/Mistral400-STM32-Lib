/* =============================================================================================
 * Function      : M400_vFanStop
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vFanStop.
 * RELATED FILE  : src/m400_vFanStop.c
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
#include "m400_vFanStop.h"

#include "m400_vFanSetDutyPermille.h"

void M400_vFanStop(TIM_HandleTypeDef *xTimer,
                   uint32_t uiChannel,
                   uint32_t uiTimerPeriod,
                   bool bActiveLow)
{
  M400_vFanSetDutyPermille(xTimer, uiChannel, uiTimerPeriod, 0U, bActiveLow);
}
