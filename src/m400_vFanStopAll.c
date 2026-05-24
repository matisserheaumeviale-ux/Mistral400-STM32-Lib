/* =============================================================================================
 * Function      : M400_vFanStopAll
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vFanStopAll.
 * RELATED FILE  : src/m400_vFanStopAll.c
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
#include "m400_vFanStopAll.h"

#include "m400_vFanStop.h"

#include <stddef.h>

void M400_vFanStopAll(TIM_HandleTypeDef *xTimer,
                      const uint32_t *puiChannels,
                      uint8_t ucChannelCount,
                      uint32_t uiTimerPeriod,
                      bool bActiveLow)
{
  uint8_t ucIndex = 0U;

  if (puiChannels == NULL)
  {
    return;
  }

  for (ucIndex = 0U; ucIndex < ucChannelCount; ucIndex++)
  {
    M400_vFanStop(xTimer, puiChannels[ucIndex], uiTimerPeriod, bActiveLow);
  }
}
