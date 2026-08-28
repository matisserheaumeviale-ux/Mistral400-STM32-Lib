/* =============================================================================================
 * Function      : vFanPWMInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vFanPWMInit.
 * RELATED FILE  : include/vFanPWMInit.h
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
#ifndef VFANPWMINIT_H
#define VFANPWMINIT_H

#include "main.h"
#include <stdint.h>

void vFanPWMInit(TIM_HandleTypeDef *xTimer, uint32_t uiChannel);

#endif
