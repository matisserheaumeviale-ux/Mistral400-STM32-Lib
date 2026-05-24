/*
 * File: m400_bIsUARTDataAvailable.c
 * Author: Matisse Rhéaume Viale
 * Description: Checks for one received UART byte without blocking.
 * License: MIT
 */
#include "m400_bIsUARTDataAvailable.h"

#include <stddef.h>

bool M400_bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData)
{
  uint8_t ucByte = 0U;

  if (xUart == NULL)
  {
    return false;
  }

  if (HAL_UART_Receive(xUart, &ucByte, 1U, 0U) != HAL_OK)
  {
    return false;
  }

  if (pucData != NULL)
  {
    *pucData = ucByte;
  }

  return true;
}
