/* =============================================================================================
 * Function      : vFanPWMInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vFanPWMInit.
 * RELATED FILE  : src/vFanPWMInit.c
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
#include "vFanPWMInit.h"

#include <stddef.h>

void vFanPWMInit(TIM_HandleTypeDef *xTimer, uint32_t uiChannel)
{
  if (xTimer == NULL)
  {
    return;
  }

  (void)HAL_TIM_PWM_Start(xTimer, uiChannel);
}
