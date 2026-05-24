/*
 * File: m400_vLEDInit.c
 * Author: Matisse Rhéaume Viale
 * Description: Initializes a caller-owned LED context and turns it off.
 * License: MIT
 */
#include "m400_vLEDInit.h"

#include "m400_vLEDSet.h"

#include <stddef.h>

void M400_vLEDInit(M400_LED_t *pxLED,
                   GPIO_TypeDef *xPort,
                   uint16_t usPin,
                   GPIO_PinState xActiveState)
{
  if (pxLED == NULL)
  {
    return;
  }

  pxLED->xPort = xPort;
  pxLED->usPin = usPin;
  pxLED->xActiveState = xActiveState;
  pxLED->uiLastToggleMs = 0UL;
  pxLED->ucState = M400_OFF;

  M400_vLEDSet(pxLED, M400_OFF);
}
