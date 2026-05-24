/*
 * File: m400_vButtonTask.c
 * Author: Matisse Rhéaume Viale
 * Description: Updates debounced state and press latch for one button.
 * License: MIT
 */
#include "m400_vButtonTask.h"

#include "m400_ucButtonReadRaw.h"

#include <stddef.h>

void M400_vButtonTask(M400_Button_t *pxButton, uint32_t uiNowMs)
{
  uint8_t ucRawState = M400_OFF;

  if (pxButton == NULL)
  {
    return;
  }

  ucRawState = M400_ucButtonReadRaw(pxButton);
  if (ucRawState != pxButton->ucLastRawState)
  {
    pxButton->ucLastRawState = ucRawState;
    pxButton->uiLastChangeMs = uiNowMs;
    return;
  }

  if (((uint32_t)(uiNowMs - pxButton->uiLastChangeMs) >= pxButton->uiDebounceMs) &&
      (ucRawState != pxButton->ucStableState))
  {
    pxButton->ucStableState = ucRawState;
    if (ucRawState == M400_ON)
    {
      pxButton->ucPressedLatch = M400_ON;
    }
  }
}
