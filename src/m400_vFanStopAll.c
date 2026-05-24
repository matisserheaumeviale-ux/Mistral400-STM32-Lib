/*
 * File: m400_vFanStopAll.c
 * Author: Matisse Rhéaume Viale
 * Description: Stops a caller-provided list of fan PWM channels.
 * License: MIT
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
