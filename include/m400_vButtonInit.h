/* =============================================================================================
 * Function      : M400_vButtonInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vButtonInit.
 * RELATED FILE  : include/m400_vButtonInit.h
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
#ifndef M400_VBUTTONINIT_H
#define M400_VBUTTONINIT_H

#include "m400_types.h"
#include <stdint.h>

void M400_vButtonInit(M400_Button_t *pxButton,
                      GPIO_TypeDef *xPort,
                      uint16_t usPin,
                      GPIO_PinState xActiveState,
                      uint32_t uiDebounceMs);

#endif
