/* =============================================================================================
 * Function      : vLEDInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLEDInit.
 * RELATED FILE  : include/vLEDInit.h
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
#ifndef VLEDINIT_H
#define VLEDINIT_H

#include "types.h"
#include <stdint.h>

void vLEDInit(LED_t *pxLED,
                   GPIO_TypeDef *xPort,
                   uint16_t usPin,
                   GPIO_PinState xActiveState);

#endif
