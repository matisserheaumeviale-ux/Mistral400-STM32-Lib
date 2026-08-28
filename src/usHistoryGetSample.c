/* =============================================================================================
 * Function      : usHistoryGetSample
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements usHistoryGetSample.
 * RELATED FILE  : src/usHistoryGetSample.c
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
#include "usHistoryGetSample.h"

#include <stddef.h>

uint16_t usHistoryGetSample(const uint16_t *pusBuffer,
                                 uint32_t uiBufferSize,
                                 uint32_t uiIndex)
{
  if ((pusBuffer == NULL) || (uiIndex >= uiBufferSize))
  {
    return 0U;
  }

  return pusBuffer[uiIndex];
}
