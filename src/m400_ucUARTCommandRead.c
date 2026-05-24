/*
 * File: m400_ucUARTCommandRead.c
 * Author: Matisse Rhéaume Viale
 * Description: Returns and clears the latched UART command byte.
 * License: MIT
 */
#include "m400_ucUARTCommandRead.h"

#include <stddef.h>

uint8_t M400_ucUARTCommandRead(M400_UARTCommand_t *pxCommand)
{
  uint8_t ucCommand = 0U;

  if (pxCommand == NULL)
  {
    return 0U;
  }

  ucCommand = pxCommand->ucCommand;
  pxCommand->ucAvailable = 0U;
  pxCommand->ucCommand = 0U;

  return ucCommand;
}
