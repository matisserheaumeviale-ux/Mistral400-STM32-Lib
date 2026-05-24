/* =============================================================================================
 * Function      : M400_vApplyOutputState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_vApplyOutputState.
 * RELATED FILE  : include/m400_vApplyOutputState.h
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
#ifndef M400_VAPPLYOUTPUTSTATE_H
#define M400_VAPPLYOUTPUTSTATE_H

#include "main.h"
#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

void M400_vApplyOutputState(uint8_t *ucpState,
                            uint8_t ucWantedState,
                            GPIO_TypeDef *xCommandPort,
                            uint16_t usCommandPin,
                            GPIO_PinState xCommandActiveState,
                            GPIO_PinState xCommandRestState,
                            uint32_t uiPulseMs,
                            uint32_t uiStabilizationMs,
                            GPIO_TypeDef *xFeedbackPort,
                            uint16_t usFeedbackPin,
                            GPIO_PinState xFeedbackActiveState,
                            uint8_t ucDefaultState,
                            uint8_t ucUseRealFeedback);

#endif
