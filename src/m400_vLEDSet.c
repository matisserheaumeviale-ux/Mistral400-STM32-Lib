/*
 * File: m400_vLEDSet.c
 * Author: Matisse Rhéaume Viale
 * Description: Writes a logical LED state to GPIO.
 * License: MIT
 */
#include "m400_vLEDSet.h"

#include <stddef.h>

void M400_vLEDSet(M400_LED_t *pxLED, uint8_t ucState)
{
  GPIO_PinState xInactiveState = GPIO_PIN_RESET;
  GPIO_PinState xOutputState = GPIO_PIN_RESET;

  if ((pxLED == NULL) || (pxLED->xPort == NULL))
  {
    return;
  }

  xInactiveState = (pxLED->xActiveState == GPIO_PIN_SET) ? GPIO_PIN_RESET : GPIO_PIN_SET;
  xOutputState = (ucState != M400_OFF) ? pxLED->xActiveState : xInactiveState;
  HAL_GPIO_WritePin(pxLED->xPort, pxLED->usPin, xOutputState);
  pxLED->ucState = (ucState != M400_OFF) ? M400_ON : M400_OFF;
}
