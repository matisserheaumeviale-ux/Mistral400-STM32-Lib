/*
 * File: m400_vIncrementSoftwareTick.c
 * Author: Matisse Rhéaume Viale
 * Description: Increments a software tick without overflowing past a caller limit.
 * License: MIT
 */
#include "m400_vIncrementSoftwareTick.h"

#include <stddef.h>

void M400_vIncrementSoftwareTick(uint32_t *puiTick, uint32_t uiMaxValue)
{
  if (puiTick == NULL)
  {
    return;
  }

  if (*puiTick < uiMaxValue)
  {
    (*puiTick)++;
  }
}
