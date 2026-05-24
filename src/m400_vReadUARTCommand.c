/*
 * File: m400_vReadUARTCommand.c
 * Author: Matisse Rhéaume Viale
 * Description: Reads one UART command byte using a caller-defined timeout.
 * License: MIT
 */
#include "m400_vReadUARTCommand.h"

#include <stddef.h>

void M400_vReadUARTCommand(UART_HandleTypeDef *xUart,
                           uint8_t *pucCommand,
                           uint32_t uiTimeoutMs)
{
  uint8_t ucByte = 0U;

  if ((xUart == NULL) || (pucCommand == NULL))
  {
    return;
  }

  if (HAL_UART_Receive(xUart, &ucByte, 1U, uiTimeoutMs) == HAL_OK)
  {
    *pucCommand = ucByte;
  }
}
