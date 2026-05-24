/* =============================================================================================
 * Function      : M400_vButtonTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vButtonTask.
 * RELATED FILE  : include/m400_vButtonTask.h
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
#ifndef M400_VBUTTONTASK_H
#define M400_VBUTTONTASK_H

#include "m400_types.h"
#include <stdint.h>

void M400_vButtonTask(M400_Button_t *pxButton, uint32_t uiNowMs);

#endif
