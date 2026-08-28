/* =============================================================================================
 * Function      : vButtonTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vButtonTask.
 * RELATED FILE  : include/vButtonTask.h
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
#ifndef VBUTTONTASK_H
#define VBUTTONTASK_H

#include "types.h"
#include <stdint.h>

void vButtonTask(Button_t *pxButton, uint32_t uiNowMs);

#endif
