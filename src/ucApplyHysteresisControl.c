/* =============================================================================================
 * Function      : ucApplyHysteresisControl
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucApplyHysteresisControl.
 * RELATED FILE  : src/ucApplyHysteresisControl.c
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
#include "ucApplyHysteresisControl.h"

uint8_t ucApplyHysteresisControl(float fValue,
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
    return ON;
  }

  if (fValue >= fHighThreshold)
  {
    return OFF;
  }

  return ucCurrentState;
}
