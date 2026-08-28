/* =============================================================================================
 * Function      : vTachometerRegisterPulse
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vTachometerRegisterPulse.
 * RELATED FILE  : include/vTachometerRegisterPulse.h
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
#ifndef VTACHOMETERREGISTERPULSE_H
#define VTACHOMETERREGISTERPULSE_H

#include "types.h"
#include <stdint.h>

void vTachometerRegisterPulse(Tachometer_t *pxTachometer,
                                   uint32_t uiCaptureTick,
                                   uint32_t uiNowMs,
                                   uint32_t uiTimerMaxTick);

#endif
