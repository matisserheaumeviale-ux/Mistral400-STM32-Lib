/* =============================================================================================
 * Function      : fConvertADCToTemperature
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements fConvertADCToTemperature.
 * RELATED FILE  : src/fConvertADCToTemperature.c
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
#include "fConvertADCToTemperature.h"

#include <math.h>

float fConvertADCToTemperature(uint16_t usAdcValue,
                                    uint16_t usAdcMaxValue,
                                    float fDividerResistanceOhm,
                                    float fNominalResistanceOhm,
                                    float fBeta,
                                    float fReferenceTemperatureK,
                                    float fKelvinOffset)
{
  float fNtcResistanceOhm = 0.0f;
  float fTemperatureK = 0.0f;

  if ((usAdcValue == 0U) ||
      (usAdcMaxValue == 0U) ||
      (usAdcValue >= usAdcMaxValue) ||
      (fDividerResistanceOhm <= 0.0f) ||
      (fNominalResistanceOhm <= 0.0f) ||
      (fBeta <= 0.0f) ||
      (fReferenceTemperatureK <= 0.0f))
  {
    return 0.0f;
  }

  fNtcResistanceOhm = fDividerResistanceOhm * (((float)usAdcMaxValue / (float)usAdcValue) - 1.0f);
  if (fNtcResistanceOhm <= 0.0f)
  {
    return 0.0f;
  }

  fTemperatureK = 1.0f /
                  ((1.0f / fReferenceTemperatureK) +
                   ((1.0f / fBeta) * logf(fNtcResistanceOhm / fNominalResistanceOhm)));

  return fTemperatureK - fKelvinOffset;
}
