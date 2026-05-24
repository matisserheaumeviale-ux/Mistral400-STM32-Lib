/*
 * File: m400_vLEDBlinkTask.c
 * Author: Matisse Rhéaume Viale
 * Description: Runs a non-blocking LED blink task.
 * License: MIT
 */
#include "m400_vLEDBlinkTask.h"

#include "m400_vLEDSet.h"
#include "m400_vLEDToggle.h"

#include <stddef.h>

void M400_vLEDBlinkTask(M400_LED_t *pxLED,
                        uint32_t uiNowMs,
                        uint32_t uiPeriodMs,
                        uint8_t ucEnabled)
{
  if (pxLED == NULL)
  {
    return;
  }

  if (ucEnabled == 0U)
  {
    M400_vLEDSet(pxLED, M400_OFF);
    pxLED->uiLastToggleMs = uiNowMs;
    return;
  }

  if ((uint32_t)(uiNowMs - pxLED->uiLastToggleMs) >= uiPeriodMs)
  {
    pxLED->uiLastToggleMs = uiNowMs;
    M400_vLEDToggle(pxLED);
  }
}
