/* =============================================================================================
 * Function      : M400_vAFLCFanRampTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the AFLC non-blocking fan ramp helper.
 * RELATED FILE  : src/project_specific/m400_vAFLCFanRampTask.c
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
#include "project_specific/m400_vAFLCFanRampTask.h"

#include <stddef.h>

void M400_vAFLCFanRampTask(M400_AFLCRamp_t *pxRamp, uint32_t uiNowMs)
{
  if ((pxRamp == NULL) || (pxRamp->bActive == false))
  {
    return;
  }

  if ((uint32_t)(uiNowMs - pxRamp->uiNextStepMs) > 0x7FFFFFFFUL)
  {
    return;
  }

  if (pxRamp->vSetAllDuty != NULL)
  {
    pxRamp->vSetAllDuty(pxRamp->usCurrentPermille, pxRamp->pvUserData);
  }

  if (pxRamp->usCurrentPermille >= pxRamp->usMaxPermille)
  {
    pxRamp->bActive = false;
    return;
  }

  pxRamp->usCurrentPermille = (uint16_t)(pxRamp->usCurrentPermille + pxRamp->usStepPermille);
  if (pxRamp->usCurrentPermille > pxRamp->usMaxPermille)
  {
    pxRamp->usCurrentPermille = pxRamp->usMaxPermille;
  }

  pxRamp->uiNextStepMs = uiNowMs + pxRamp->uiStepMs;
}
