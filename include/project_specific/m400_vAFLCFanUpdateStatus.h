/* =============================================================================================
 * Function      : M400_vAFLCFanUpdateStatus
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the AFLC fan status update helper.
 * RELATED FILE  : include/project_specific/m400_vAFLCFanUpdateStatus.h
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
#ifndef M400_VAFLCFANUPDATESTATUS_H
#define M400_VAFLCFANUPDATESTATUS_H

#include "project_specific/m400_aflc_types.h"
#include <stdint.h>

void M400_vAFLCFanUpdateStatus(M400_AFLCFanStatus_t *pxStatus,
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
                               uint32_t uiStartupTimeoutMs);

#endif
