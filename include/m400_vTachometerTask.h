/* =============================================================================================
 * Function      : M400_vTachometerTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vTachometerTask.
 * RELATED FILE  : include/m400_vTachometerTask.h
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
#ifndef M400_VTACHOMETERTASK_H
#define M400_VTACHOMETERTASK_H

#include "m400_types.h"
#include <stdint.h>

void M400_vTachometerTask(M400_Tachometer_t *pxTachometer,
                          uint32_t uiNowMs,
                          uint32_t uiTimeoutMs,
                          uint32_t uiTimerFrequencyHz,
                          uint32_t uiPulsesPerRevolution);

#endif
