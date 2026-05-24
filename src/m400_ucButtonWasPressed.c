/*
 * File: m400_ucButtonWasPressed.c
 * Author: Matisse Rhéaume Viale
 * Description: Returns and clears the button pressed latch.
 * License: MIT
 */
#include "m400_ucButtonWasPressed.h"

#include <stddef.h>

uint8_t M400_ucButtonWasPressed(M400_Button_t *pxButton)
{
  uint8_t ucWasPressed = M400_OFF;

  if (pxButton == NULL)
  {
    return M400_OFF;
  }

  ucWasPressed = pxButton->ucPressedLatch;
  pxButton->ucPressedLatch = M400_OFF;

  return ucWasPressed;
}
