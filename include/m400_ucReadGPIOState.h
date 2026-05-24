/* =============================================================================================
 * Function      : M400_ucReadGPIOState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_ucReadGPIOState.
 * RELATED FILE  : include/m400_ucReadGPIOState.h
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
#ifndef M400_UCREADGPIOSTATE_H
#define M400_UCREADGPIOSTATE_H

#include "main.h"
#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucReadGPIOState(GPIO_TypeDef *xPort,
                             uint16_t usPin,
                             GPIO_PinState xActiveState,
                             uint8_t ucDefaultState,
                             uint8_t ucUseRealFeedback);

#endif
