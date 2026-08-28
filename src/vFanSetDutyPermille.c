/* =============================================================================================
 * Function      : vFanSetDutyPermille
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vFanSetDutyPermille.
 * RELATED FILE  : src/vFanSetDutyPermille.c
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
#include "vFanSetDutyPermille.h"

#include <stddef.h>

#define FAN_DUTY_MAX_PERMILLE 1000U

void vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
                              uint32_t uiChannel,
                              uint32_t uiTimerPeriod,
                              uint16_t usDutyPermille,
                              bool bActiveLow)
{
  uint32_t uiCompare = 0UL;
  uint32_t uiEffectiveDuty = usDutyPermille;

  if (xTimer == NULL)
  {
    return;
  }

  if (uiEffectiveDuty > FAN_DUTY_MAX_PERMILLE)
  {
    uiEffectiveDuty = FAN_DUTY_MAX_PERMILLE;
  }

  if (bActiveLow)
  {
    uiEffectiveDuty = FAN_DUTY_MAX_PERMILLE - uiEffectiveDuty;
  }

  uiCompare = ((uiTimerPeriod + 1UL) * uiEffectiveDuty) / FAN_DUTY_MAX_PERMILLE;
  if (uiCompare > uiTimerPeriod)
  {
    uiCompare = uiTimerPeriod;
  }

  __HAL_TIM_SET_COMPARE(xTimer, uiChannel, uiCompare);
}
