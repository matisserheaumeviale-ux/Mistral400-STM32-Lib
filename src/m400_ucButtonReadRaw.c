/*
 * File: m400_ucButtonReadRaw.c
 * Author: Matisse Rhéaume Viale
 * Description: Reads the current unfiltered GPIO button state.
 * License: MIT
 */
#include "m400_ucButtonReadRaw.h"

#include <stddef.h>

uint8_t M400_ucButtonReadRaw(const M400_Button_t *pxButton)
{
  if ((pxButton == NULL) || (pxButton->xPort == NULL))
  {
    return M400_OFF;
  }

  return (HAL_GPIO_ReadPin(pxButton->xPort, pxButton->usPin) == pxButton->xActiveState) ? M400_ON : M400_OFF;
}
