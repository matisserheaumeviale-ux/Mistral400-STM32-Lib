/* =============================================================================================
 * Function      : M400_vFanSetDutyPermille
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vFanSetDutyPermille.
 * RELATED FILE  : src/m400_vFanSetDutyPermille.c
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
#include "m400_vFanSetDutyPermille.h"

#include <stddef.h>

#define M400_FAN_DUTY_MAX_PERMILLE 1000U

void M400_vFanSetDutyPermille(TIM_HandleTypeDef *xTimer,
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

  if (uiEffectiveDuty > M400_FAN_DUTY_MAX_PERMILLE)
  {
    uiEffectiveDuty = M400_FAN_DUTY_MAX_PERMILLE;
  }

  if (bActiveLow)
  {
    uiEffectiveDuty = M400_FAN_DUTY_MAX_PERMILLE - uiEffectiveDuty;
  }

  uiCompare = ((uiTimerPeriod + 1UL) * uiEffectiveDuty) / M400_FAN_DUTY_MAX_PERMILLE;
  if (uiCompare > uiTimerPeriod)
  {
    uiCompare = uiTimerPeriod;
  }

  __HAL_TIM_SET_COMPARE(xTimer, uiChannel, uiCompare);
}
