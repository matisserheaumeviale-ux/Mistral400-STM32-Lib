/*
 * File: m400_vUARTPrintString.c
 * Author: Matisse Rhéaume Viale
 * Description: Sends a null-terminated string over STM32 HAL UART.
 * License: MIT
 */
#include "m400_vUARTPrintString.h"

#include <stddef.h>

void M400_vUARTPrintString(UART_HandleTypeDef *xUart,
                           const char *pcText,
                           uint32_t uiTimeoutMs)
{
  uint16_t usLength = 0U;

  if ((xUart == NULL) || (pcText == NULL))
  {
    return;
  }

  while (pcText[usLength] != '\0')
  {
    usLength++;
  }

  if (usLength > 0U)
  {
    (void)HAL_UART_Transmit(xUart, (uint8_t *)pcText, usLength, uiTimeoutMs);
  }
}
