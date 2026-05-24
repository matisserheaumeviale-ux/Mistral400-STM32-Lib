/* =============================================================================================
 * Function      : M400_vTimerPeriodElapsedCallback
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vTimerPeriodElapsedCallback.
 * RELATED FILE  : src/m400_vTimerPeriodElapsedCallback.c
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
#include "m400_vTimerPeriodElapsedCallback.h"

#include "m400_vIncrementSoftwareTick.h"

#include <stddef.h>

void M400_vTimerPeriodElapsedCallback(TIM_HandleTypeDef *xTimer,
                                      void *pxExpectedInstance,
                                      uint32_t *puiTick,
                                      uint32_t uiMaxValue)
{
  if ((xTimer == NULL) || (pxExpectedInstance == NULL))
  {
    return;
  }

  if ((void *)xTimer->Instance == pxExpectedInstance)
  {
    M400_vIncrementSoftwareTick(puiTick, uiMaxValue);
  }
}
