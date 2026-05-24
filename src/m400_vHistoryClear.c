/*
 * File: m400_vHistoryClear.c
 * Author: Matisse Rhéaume Viale
 * Description: Clears a caller-owned history buffer and resets its write index.
 * License: MIT
 */
#include "m400_vHistoryClear.h"

#include <stddef.h>

void M400_vHistoryClear(uint16_t *pusBuffer,
                        uint32_t uiBufferSize,
                        uint32_t *puiWriteIndex)
{
  uint32_t uiIndex = 0UL;

  if (pusBuffer != NULL)
  {
    for (uiIndex = 0UL; uiIndex < uiBufferSize; uiIndex++)
    {
      pusBuffer[uiIndex] = 0U;
    }
  }

  if (puiWriteIndex != NULL)
  {
    *puiWriteIndex = 0UL;
  }
}
