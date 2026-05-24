/* =============================================================================================
 * Function      : M400_vApplyOutputState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vApplyOutputState.
 * RELATED FILE  : src/m400_vApplyOutputState.c
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
