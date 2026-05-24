/*
 * File: m400_fConvertADCToTemperature.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for converting an ADC divider reading to temperature.
 * License: MIT
 */
#ifndef M400_FCONVERTADCTOTEMPERATURE_H
#define M400_FCONVERTADCTOTEMPERATURE_H

#include <stdint.h>

float M400_fConvertADCToTemperature(uint16_t usAdcValue,
                                    uint16_t usAdcMaxValue,
                                    float fDividerResistanceOhm,
                                    float fNominalResistanceOhm,
                                    float fBeta,
                                    float fReferenceTemperatureK,
                                    float fKelvinOffset);

#endif
