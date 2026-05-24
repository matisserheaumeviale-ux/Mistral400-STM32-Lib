/* =============================================================================================
 * Function      : M400_vTachometerRegisterPulse
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vTachometerRegisterPulse.
 * RELATED FILE  : include/m400_vTachometerRegisterPulse.h
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
#ifndef M400_VTACHOMETERREGISTERPULSE_H
#define M400_VTACHOMETERREGISTERPULSE_H

#include "m400_types.h"
#include <stdint.h>

void M400_vTachometerRegisterPulse(M400_Tachometer_t *pxTachometer,
                                   uint32_t uiCaptureTick,
                                   uint32_t uiNowMs,
                                   uint32_t uiTimerMaxTick);

#endif
