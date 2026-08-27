/* =============================================================================================
 * Function      : M400_bAFLCFanHasAnyFault
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements an AFLC fan status fault scan helper.
 * RELATED FILE  : src/project_specific/m400_bAFLCFanHasAnyFault.c
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
#include "project_specific/m400_bAFLCFanHasAnyFault.h"

#include <stddef.h>

bool M400_bAFLCFanHasAnyFault(const M400_AFLCFanStatus_t *pxStatuses, uint8_t ucCount)
{
  uint8_t ucIndex = 0U;

  if (pxStatuses == NULL)
  {
    return false;
  }

  for (ucIndex = 0U; ucIndex < ucCount; ucIndex++)
  {
    if (pxStatuses[ucIndex].xState == M400_AFLC_FAN_STATE_ERROR)
    {
      return true;
    }
  }

  return false;
}
