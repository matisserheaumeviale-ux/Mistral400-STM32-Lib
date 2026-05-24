/*
 * File: m400_usHistoryGetSample.c
 * Author: Matisse Rhéaume Viale
 * Description: Returns one sample from a caller-owned history buffer.
 * License: MIT
 */
#include "m400_usHistoryGetSample.h"

#include <stddef.h>

uint16_t M400_usHistoryGetSample(const uint16_t *pusBuffer,
                                 uint32_t uiBufferSize,
                                 uint32_t uiIndex)
{
  if ((pusBuffer == NULL) || (uiIndex >= uiBufferSize))
  {
    return 0U;
  }

  return pusBuffer[uiIndex];
}
