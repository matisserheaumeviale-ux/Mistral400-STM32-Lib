/*
 * File: m400_ucApplyHysteresisControl.c
 * Author: Matisse Rhéaume Viale
 * Description: Applies a generic on/off hysteresis decision.
 * License: MIT
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
