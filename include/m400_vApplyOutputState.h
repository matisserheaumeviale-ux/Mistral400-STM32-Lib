/*
 * File: m400_vApplyOutputState.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for applying a generic feedback-controlled output state.
 * License: MIT
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
