/* =============================================================================================
 * Function      : M400_ucApplyHysteresisControl
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucApplyHysteresisControl.
 * RELATED FILE  : src/m400_ucApplyHysteresisControl.c
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
#include "m400_ucApplyHysteresisControl.h"

uint8_t M400_ucApplyHysteresisControl(float fValue,
                                      float fLowThreshold,
                                      float fHighThreshold,
                                      uint8_t ucCurrentState)
{
  if (fLowThreshold > fHighThreshold)
  {
    float fSwap = fLowThreshold;
    fLowThreshold = fHighThreshold;
    fHighThreshold = fSwap;
  }

  if (fValue <= fLowThreshold)
  {
    return M400_ON;
  }

  if (fValue >= fHighThreshold)
  {
    return M400_OFF;
  }

  return ucCurrentState;
}
