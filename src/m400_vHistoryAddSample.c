/*
 * File: m400_vHistoryAddSample.c
 * Author: Matisse Rhéaume Viale
 * Description: Adds one sample to a caller-owned history buffer.
 * License: MIT
 */
#include "m400_vHistoryAddSample.h"

#include <stddef.h>

void M400_vHistoryAddSample(uint16_t *pusBuffer,
                            uint32_t uiBufferSize,
                            uint32_t *puiWriteIndex,
                            uint16_t usSample)
{
  if ((pusBuffer == NULL) || (puiWriteIndex == NULL))
  {
    return;
  }

  if (*puiWriteIndex < uiBufferSize)
  {
    pusBuffer[*puiWriteIndex] = usSample;
    (*puiWriteIndex)++;
  }
}
