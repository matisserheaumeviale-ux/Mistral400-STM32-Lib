/* =============================================================================================
 * Function      : M400_vHistoryClear
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vHistoryClear.
 * RELATED FILE  : include/m400_vHistoryClear.h
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
#ifndef M400_VHISTORYCLEAR_H
#define M400_VHISTORYCLEAR_H

#include <stdint.h>

void M400_vHistoryClear(uint16_t *pusBuffer,
                        uint32_t uiBufferSize,
                        uint32_t *puiWriteIndex);

#endif
