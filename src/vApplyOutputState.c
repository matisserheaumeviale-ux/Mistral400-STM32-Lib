/* =============================================================================================
 * Function      : vApplyOutputState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vApplyOutputState.
 * RELATED FILE  : src/vApplyOutputState.c
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
#include "vApplyOutputState.h"

#include "ucReadGPIOState.h"
#include "vGPIOPulse.h"

#include <stddef.h>

void vApplyOutputState(uint8_t *ucpState,
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
  uint8_t ucCurrentState = OFF;

  if (ucpState == NULL)
  {
    return;
  }

  ucCurrentState = ucReadGPIOState(xFeedbackPort,
                                        usFeedbackPin,
                                        xFeedbackActiveState,
                                        ucDefaultState,
                                        ucUseRealFeedback);

  *ucpState = ucCurrentState;

  if (ucCurrentState != ucWantedState)
  {
    vGPIOPulse(xCommandPort,
                    usCommandPin,
                    xCommandActiveState,
                    xCommandRestState,
                    uiPulseMs,
                    uiStabilizationMs);

    *ucpState = ucReadGPIOState(xFeedbackPort,
                                     usFeedbackPin,
                                     xFeedbackActiveState,
                                     ucDefaultState,
                                     ucUseRealFeedback);
  }
}
