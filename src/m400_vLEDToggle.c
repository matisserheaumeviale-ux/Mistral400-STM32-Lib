/*
 * File: m400_vLEDToggle.c
 * Author: Matisse Rhéaume Viale
 * Description: Toggles a caller-owned LED context.
 * License: MIT
 */
#include "m400_vLEDToggle.h"

#include "m400_vLEDSet.h"

#include <stddef.h>

void M400_vLEDToggle(M400_LED_t *pxLED)
{
  if (pxLED == NULL)
  {
    return;
  }

  M400_vLEDSet(pxLED, (pxLED->ucState == M400_OFF) ? M400_ON : M400_OFF);
}
