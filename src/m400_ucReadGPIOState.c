/*
 * File: m400_ucReadGPIOState.c
 * Author: Matisse Rhéaume Viale
 * Description: Reads a GPIO pin and converts it to an M400 on/off state.
 * License: MIT
 */
#include "m400_ucReadGPIOState.h"

#include <stddef.h>

uint8_t M400_ucReadGPIOState(GPIO_TypeDef *xPort,
                             uint16_t usPin,
                             GPIO_PinState xActiveState,
                             uint8_t ucDefaultState,
                             uint8_t ucUseRealFeedback)
{
  if (ucUseRealFeedback == 0U)
  {
    return ucDefaultState;
  }

  if (xPort == NULL)
  {
    return ucDefaultState;
  }

  return (HAL_GPIO_ReadPin(xPort, usPin) == xActiveState) ? M400_ON : M400_OFF;
}
