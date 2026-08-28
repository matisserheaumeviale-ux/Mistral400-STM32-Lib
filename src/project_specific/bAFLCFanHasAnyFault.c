/* =============================================================================================
 * Function      : bAFLCFanHasAnyFault
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements an AFLC fan status fault scan helper.
 * RELATED FILE  : src/project_specific/bAFLCFanHasAnyFault.c
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
#include "project_specific/bAFLCFanHasAnyFault.h"

#include <stddef.h>

bool bAFLCFanHasAnyFault(const AFLCFanStatus_t *pxStatuses, uint8_t ucCount)
{
  uint8_t ucIndex = 0U;

  if (pxStatuses == NULL)
  {
    return false;
  }

  for (ucIndex = 0U; ucIndex < ucCount; ucIndex++)
  {
    if (pxStatuses[ucIndex].xState == AFLC_FAN_STATE_ERROR)
    {
      return true;
    }
  }

  return false;
}
