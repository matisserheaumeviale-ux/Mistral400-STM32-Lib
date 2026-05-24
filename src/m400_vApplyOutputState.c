/*
 * File: m400_vApplyOutputState.c
 * Author: Matisse Rhéaume Viale
 * Description: Applies a generic output state using GPIO feedback and pulse control.
 * License: MIT
 */
#include "m400_vApplyOutputState.h"

#include "m400_ucReadGPIOState.h"
#include "m400_vGPIOPulse.h"

#include <stddef.h>

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
                            uint8_t ucUseRealFeedback)
{
  uint8_t ucCurrentState = M400_OFF;

  if (ucpState == NULL)
  {
    return;
  }

  ucCurrentState = M400_ucReadGPIOState(xFeedbackPort,
                                        usFeedbackPin,
                                        xFeedbackActiveState,
                                        ucDefaultState,
                                        ucUseRealFeedback);

  *ucpState = ucCurrentState;

  if (ucCurrentState != ucWantedState)
  {
    M400_vGPIOPulse(xCommandPort,
                    usCommandPin,
                    xCommandActiveState,
                    xCommandRestState,
                    uiPulseMs,
                    uiStabilizationMs);

    *ucpState = M400_ucReadGPIOState(xFeedbackPort,
                                     usFeedbackPin,
                                     xFeedbackActiveState,
                                     ucDefaultState,
                                     ucUseRealFeedback);
  }
}
