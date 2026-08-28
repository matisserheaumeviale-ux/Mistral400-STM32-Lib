/* =============================================================================================
 * Function      : vAFLCFanUpdateStatus
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the AFLC fan status update helper.
 * RELATED FILE  : src/project_specific/vAFLCFanUpdateStatus.c
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
#include "project_specific/vAFLCFanUpdateStatus.h"

#include <stddef.h>

static uint8_t DutyToPercent(uint16_t usDutyPermille);

void vAFLCFanUpdateStatus(AFLCFanStatus_t *pxStatus,
                               uint16_t usDutyPermille,
                               uint16_t usCurrentRPM,
                               uint16_t usTargetRPM,
                               uint8_t ucSignalPresent,
                               uint32_t uiNowMs,
                               uint32_t uiCommandMs,
                               uint8_t ucRampActive,
                               uint16_t *pusLastRPM,
                               uint8_t *pucEverDetected,
                               uint16_t usRunningMinRPM,
                               uint32_t uiStartupTimeoutMs)
{
  uint16_t usLastRPM = 0U;

  if (pxStatus == NULL)
  {
    return;
  }

  if (pusLastRPM != NULL)
  {
    usLastRPM = *pusLastRPM;
  }

  pxStatus->usRPM = usCurrentRPM;
  pxStatus->usTargetRPM = usTargetRPM;
  pxStatus->ucPercent = DutyToPercent(usDutyPermille);
  pxStatus->xAlert = AFLC_FAN_ALERT_NONE;
  pxStatus->xAction = AFLC_FAN_ACTION_IDLE;

  if (usDutyPermille == 0U)
  {
    pxStatus->xState = AFLC_FAN_STATE_OFF;
    pxStatus->xAction = AFLC_FAN_ACTION_NONE;
    pxStatus->usRPM = 0U;
    pxStatus->usTargetRPM = 0U;
    if (pusLastRPM != NULL)
    {
      *pusLastRPM = 0U;
    }
    return;
  }

  if ((ucSignalPresent != 0U) && (usCurrentRPM >= usRunningMinRPM))
  {
    pxStatus->xState = AFLC_FAN_STATE_RUNNING;
    if (pucEverDetected != NULL)
    {
      *pucEverDetected = 1U;
    }

    if (usCurrentRPM > (uint16_t)(usLastRPM + 50U))
    {
      pxStatus->xAction = (ucRampActive != 0U) ? AFLC_FAN_ACTION_RAMP : AFLC_FAN_ACTION_ACCEL;
    }
    else if ((usLastRPM > 50U) && ((uint16_t)(usCurrentRPM + 50U) < usLastRPM))
    {
      pxStatus->xAction = AFLC_FAN_ACTION_DECEL;
    }
    else
    {
      pxStatus->xAction = AFLC_FAN_ACTION_IDLE;
    }
  }
  else if ((uint32_t)(uiNowMs - uiCommandMs) <= uiStartupTimeoutMs)
  {
    pxStatus->xState = AFLC_FAN_STATE_STARTING;
    pxStatus->xAction = AFLC_FAN_ACTION_DETECT;
  }
  else
  {
    pxStatus->xState = AFLC_FAN_STATE_ERROR;
    pxStatus->xAction = AFLC_FAN_ACTION_DETECT;
    pxStatus->xAlert = ((pucEverDetected != NULL) && (*pucEverDetected != 0U)) ?
                       AFLC_FAN_ALERT_FAULT :
                       AFLC_FAN_ALERT_WARN;
  }

  if (pusLastRPM != NULL)
  {
    *pusLastRPM = usCurrentRPM;
  }
}

static uint8_t DutyToPercent(uint16_t usDutyPermille)
{
  uint16_t usPercent = (uint16_t)((usDutyPermille + 5U) / 10U);

  if (usPercent > 100U)
  {
    usPercent = 100U;
  }

  return (uint8_t)usPercent;
}
