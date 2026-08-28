/* =============================================================================================
 * Function      : vAFLCLEDApplyMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the AFLC LED mode mapping helper.
 * RELATED FILE  : include/project_specific/vAFLCLEDApplyMode.h
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
#ifndef VAFLCLEDAPPLYMODE_H
#define VAFLCLEDAPPLYMODE_H

#include "types.h"
#include "project_specific/aflc_types.h"
#include <stdint.h>

void vAFLCLEDApplyMode(LED_t *pxStatusLED,
                            LED_t *pxUSBLED,
                            LED_t *pxErrorLED,
                            LED_t *pxExtraLED,
                            AFLCLEDMode_t xMode,
                            uint32_t uiNowMs,
                            uint32_t uiCommActivityMs,
                            uint32_t uiHeartbeatPeriodMs,
                            uint32_t uiActivityHoldMs);

#endif
