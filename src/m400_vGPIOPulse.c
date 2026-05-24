/*
 * File: m400_vGPIOPulse.c
 * Author: Matisse Rhéaume Viale
 * Description: Sends a timed command pulse on a GPIO output.
 * License: MIT
 */
#include "m400_vGPIOPulse.h"

#include <stddef.h>

void M400_vGPIOPulse(GPIO_TypeDef *xCommandPort,
                     uint16_t usCommandPin,
                     GPIO_PinState xActiveState,
                     GPIO_PinState xRestState,
                     uint32_t uiPulseMs,
                     uint32_t uiStabilizationMs)
{
  if (xCommandPort == NULL)
  {
    return;
  }

  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xRestState);
  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xActiveState);
  HAL_Delay(uiPulseMs);
  HAL_GPIO_WritePin(xCommandPort, usCommandPin, xRestState);
  HAL_Delay(uiStabilizationMs);
}
