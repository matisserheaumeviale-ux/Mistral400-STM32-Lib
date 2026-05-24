/*
 * File: m400_fConvertADCToTemperature.c
 * Author: Matisse Rhéaume Viale
 * Description: Converts an NTC voltage divider ADC value to degrees Celsius.
 * License: MIT
 */
#include "m400_fConvertADCToTemperature.h"

#include <math.h>

float M400_fConvertADCToTemperature(uint16_t usAdcValue,
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
