/* =============================================================================================
 * Function      : M400_vAFLCLEDApplyMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the AFLC LED mode mapping helper.
 * RELATED FILE  : include/project_specific/m400_vAFLCLEDApplyMode.h
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
#ifndef M400_VAFLCLEDAPPLYMODE_H
#define M400_VAFLCLEDAPPLYMODE_H

#include "m400_types.h"
#include "project_specific/m400_aflc_types.h"
#include <stdint.h>

void M400_vAFLCLEDApplyMode(M400_LED_t *pxStatusLED,
                            M400_LED_t *pxUSBLED,
                            M400_LED_t *pxErrorLED,
                            M400_LED_t *pxExtraLED,
                            M400_AFLCLEDMode_t xMode,
                            uint32_t uiNowMs,
                            uint32_t uiCommActivityMs,
                            uint32_t uiHeartbeatPeriodMs,
                            uint32_t uiActivityHoldMs);

#endif
