/*
 * File: m400_vUARTCommandInit.c
 * Author: Matisse Rhéaume Viale
 * Description: Initializes a caller-owned UART command context.
 * License: MIT
 */
#include "m400_vUARTCommandInit.h"

#include <stddef.h>

void M400_vUARTCommandInit(M400_UARTCommand_t *pxCommand, UART_HandleTypeDef *xUart)
{
  if (pxCommand == NULL)
  {
    return;
  }

  pxCommand->xUart = xUart;
  pxCommand->ucCommand = 0U;
  pxCommand->ucAvailable = 0U;
}
