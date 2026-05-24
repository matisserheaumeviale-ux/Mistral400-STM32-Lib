/* =============================================================================================
 * Function      : M400_vHistoryAddSample
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vHistoryAddSample.
 * RELATED FILE  : src/m400_vHistoryAddSample.c
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * The function performs its task without affecting other parts of the program.
 * =============================================================================================
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
