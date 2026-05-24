/*
 * File: m400_ucUARTCommandAvailable.c
 * Author: Matisse Rhéaume Viale
 * Description: Polls UART and latches one available command byte.
 * License: MIT
 */
#include "m400_ucUARTCommandAvailable.h"

#include "m400_bIsUARTDataAvailable.h"

#include <stddef.h>

uint8_t M400_ucUARTCommandAvailable(M400_UARTCommand_t *pxCommand)
{
  uint8_t ucByte = 0U;

  if ((pxCommand == NULL) || (pxCommand->xUart == NULL))
  {
    return M400_OFF;
  }

  if (pxCommand->ucAvailable != 0U)
  {
    return M400_ON;
  }

  if (M400_bIsUARTDataAvailable(pxCommand->xUart, &ucByte))
  {
    pxCommand->ucCommand = ucByte;
    pxCommand->ucAvailable = M400_ON;
  }

  return pxCommand->ucAvailable;
}
