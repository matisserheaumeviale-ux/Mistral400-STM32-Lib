/*
 * File: m400_vButtonInit.c
 * Author: Matisse Rhéaume Viale
 * Description: Initializes a caller-owned button context.
 * License: MIT
 */
#include "m400_vButtonInit.h"

#include <stddef.h>

void M400_vButtonInit(M400_Button_t *pxButton,
                      GPIO_TypeDef *xPort,
                      uint16_t usPin,
                      GPIO_PinState xActiveState,
                      uint32_t uiDebounceMs)
{
  if (pxButton == NULL)
  {
    return;
  }

  pxButton->xPort = xPort;
  pxButton->usPin = usPin;
  pxButton->xActiveState = xActiveState;
  pxButton->uiDebounceMs = uiDebounceMs;
  pxButton->uiLastChangeMs = 0UL;
  pxButton->ucLastRawState = M400_OFF;
  pxButton->ucStableState = M400_OFF;
  pxButton->ucPressedLatch = M400_OFF;
}
