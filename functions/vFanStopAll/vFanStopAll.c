/* =============================================================================================
 * Function      : vFanStopAll
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vFanStopAll.
 * RELATED FILE  : src/vFanStopAll.c
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
#include "vFanStopAll.h"

#include "vFanStop.h"

#include <stddef.h>

void vFanStopAll(TIM_HandleTypeDef *xTimer,
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
    vFanStop(xTimer, puiChannels[ucIndex], uiTimerPeriod, bActiveLow);
  }
}
