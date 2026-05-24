/*
 * File: m400_uiTachometerGetRPM.c
 * Author: Matisse Rhéaume Viale
 * Description: Returns the last RPM value stored in a tachometer context.
 * License: MIT
 */
#include "m400_uiTachometerGetRPM.h"

#include <stddef.h>

uint32_t M400_uiTachometerGetRPM(const M400_Tachometer_t *pxTachometer)
{
  if (pxTachometer == NULL)
  {
    return 0UL;
  }

  return pxTachometer->uiRPM;
}
