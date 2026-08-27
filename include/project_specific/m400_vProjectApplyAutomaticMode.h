/* =============================================================================================
 * Function      : M400_vProjectApplyAutomaticMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares a project-specific automatic control helper with output callbacks.
 * RELATED FILE  : include/project_specific/m400_vProjectApplyAutomaticMode.h
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
#ifndef M400_VPROJECTAPPLYAUTOMATICMODE_H
#define M400_VPROJECTAPPLYAUTOMATICMODE_H

#include "project_specific/m400_project_types.h"
#include <stdint.h>

void M400_vProjectApplyAutomaticMode(uint8_t *pucStateTable,
                                     float fTemperatureC,
                                     uint8_t ucLowSetpoint,
                                     uint8_t ucHighSetpoint,
                                     uint8_t ucDayState,
                                     uint8_t ucNightState,
                                     const M400_ProjectControlledOutput_t *pxHeating,
                                     const M400_ProjectControlledOutput_t *pxFan,
                                     const M400_ProjectControlledOutput_t *pxLight);

#endif
