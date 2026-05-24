/* =============================================================================================
 * Function      : M400_uiTachometerComputeRPM
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_uiTachometerComputeRPM.
 * RELATED FILE  : include/m400_uiTachometerComputeRPM.h
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
#ifndef M400_UITACHOMETERCOMPUTERPM_H
#define M400_UITACHOMETERCOMPUTERPM_H

#include <stdint.h>

uint32_t M400_uiTachometerComputeRPM(uint32_t uiPeriodTicks,
                                     uint32_t uiTimerFrequencyHz,
                                     uint32_t uiPulsesPerRevolution);

#endif
