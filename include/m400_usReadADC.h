/* =============================================================================================
 * Function      : M400_usReadADC
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_usReadADC.
 * RELATED FILE  : include/m400_usReadADC.h
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
#ifndef M400_USREADADC_H
#define M400_USREADADC_H

#include "main.h"
#include <stdint.h>

uint16_t M400_usReadADC(ADC_HandleTypeDef *xAdc,
                        uint32_t uiChannel,
                        uint32_t uiRank,
                        uint32_t uiSamplingTime,
                        uint8_t ucSampleCount,
                        uint32_t uiPollTimeoutMs);

#endif
