/* =============================================================================================
 * Function      : vAFLCFanRampTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the AFLC non-blocking fan ramp helper.
 * RELATED FILE  : include/project_specific/vAFLCFanRampTask.h
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
#ifndef VAFLCFANRAMPTASK_H
#define VAFLCFANRAMPTASK_H

#include "project_specific/aflc_types.h"
#include <stdint.h>

void vAFLCFanRampTask(AFLCRamp_t *pxRamp, uint32_t uiNowMs);

#endif
