/* =============================================================================================
 * Function      : M400_usHistoryGetSample
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_usHistoryGetSample.
 * RELATED FILE  : include/m400_usHistoryGetSample.h
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
#ifndef M400_USHISTORYGETSAMPLE_H
#define M400_USHISTORYGETSAMPLE_H

#include <stdint.h>

uint16_t M400_usHistoryGetSample(const uint16_t *pusBuffer,
                                 uint32_t uiBufferSize,
                                 uint32_t uiIndex);

#endif
