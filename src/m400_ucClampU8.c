/*
 * File: m400_ucClampU8.c
 * Author: Matisse Rhéaume Viale
 * Description: Clamps an unsigned 8-bit value between two limits.
 * License: MIT
 */
#include "m400_ucClampU8.h"

uint8_t M400_ucClampU8(uint8_t ucValue, uint8_t ucMinimum, uint8_t ucMaximum)
{
  if (ucMinimum > ucMaximum)
  {
    uint8_t ucSwap = ucMinimum;
    ucMinimum = ucMaximum;
    ucMaximum = ucSwap;
  }

  if (ucValue < ucMinimum)
  {
    return ucMinimum;
  }

  if (ucValue > ucMaximum)
  {
    return ucMaximum;
  }

  return ucValue;
}
