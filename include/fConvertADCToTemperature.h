/* =============================================================================================
 * Function      : fConvertADCToTemperature
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for fConvertADCToTemperature.
 * RELATED FILE  : include/fConvertADCToTemperature.h
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
#ifndef FCONVERTADCTOTEMPERATURE_H
#define FCONVERTADCTOTEMPERATURE_H

#include <stdint.h>

float fConvertADCToTemperature(uint16_t usAdcValue,
                                    uint16_t usAdcMaxValue,
                                    float fDividerResistanceOhm,
                                    float fNominalResistanceOhm,
                                    float fBeta,
                                    float fReferenceTemperatureK,
                                    float fKelvinOffset);

#endif
