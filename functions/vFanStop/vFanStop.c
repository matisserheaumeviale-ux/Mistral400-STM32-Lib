/* =============================================================================================
 * Function      : vFanStop
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vFanStop.
 * RELATED FILE  : src/vFanStop.c
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
#include "vFanStop.h"

#include "vFanSetDutyPermille.h"

void vFanStop(TIM_HandleTypeDef *xTimer,
                   uint32_t uiChannel,
                   uint32_t uiTimerPeriod,
                   bool bActiveLow)
{
  vFanSetDutyPermille(xTimer, uiChannel, uiTimerPeriod, 0U, bActiveLow);
}
