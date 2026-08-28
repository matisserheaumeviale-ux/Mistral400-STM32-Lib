/* =============================================================================================
 * Function      : vHistoryClear
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vHistoryClear.
 * RELATED FILE  : include/vHistoryClear.h
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
#ifndef VHISTORYCLEAR_H
#define VHISTORYCLEAR_H

#include <stdint.h>

void vHistoryClear(uint16_t *pusBuffer,
                        uint32_t uiBufferSize,
                        uint32_t *puiWriteIndex);

#endif
