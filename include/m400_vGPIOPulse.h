/* =============================================================================================
 * Function      : M400_vGPIOPulse
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vGPIOPulse.
 * RELATED FILE  : include/m400_vGPIOPulse.h
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
#ifndef M400_VGPIOPULSE_H
#define M400_VGPIOPULSE_H

#include "main.h"
#include <stdint.h>

void M400_vGPIOPulse(GPIO_TypeDef *xCommandPort,
                     uint16_t usCommandPin,
                     GPIO_PinState xActiveState,
                     GPIO_PinState xRestState,
                     uint32_t uiPulseMs,
                     uint32_t uiStabilizationMs);

#endif
