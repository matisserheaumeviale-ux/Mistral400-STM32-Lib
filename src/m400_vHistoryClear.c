/* =============================================================================================
 * Function      : M400_vHistoryClear
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vHistoryClear.
 * RELATED FILE  : src/m400_vHistoryClear.c
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
