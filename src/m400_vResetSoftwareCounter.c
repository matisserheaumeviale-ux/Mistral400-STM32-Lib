/*
 * File: m400_vResetSoftwareCounter.c
 * Author: Matisse Rhéaume Viale
 * Description: Resets a caller-owned software counter to zero.
 * License: MIT
 */
#include "m400_vResetSoftwareCounter.h"

#include <stddef.h>

void M400_vResetSoftwareCounter(uint32_t *puiCounter)
{
  if (puiCounter != NULL)
  {
    *puiCounter = 0UL;
  }
}
