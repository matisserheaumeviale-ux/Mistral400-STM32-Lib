/* =============================================================================================
 * Function      : ucReadGPIOState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucReadGPIOState.
 * RELATED FILE  : include/ucReadGPIOState.h
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
#ifndef UCREADGPIOSTATE_H
#define UCREADGPIOSTATE_H

#include "main.h"
#include <stdint.h>

#ifndef OFF
#define OFF 0U
#endif

#ifndef ON
#define ON  1U
#endif

uint8_t ucReadGPIOState(GPIO_TypeDef *xPort,
                             uint16_t usPin,
                             GPIO_PinState xActiveState,
                             uint8_t ucDefaultState,
                             uint8_t ucUseRealFeedback);

#endif
