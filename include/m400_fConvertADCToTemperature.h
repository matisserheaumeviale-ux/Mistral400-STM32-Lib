/* =============================================================================================
 * Function      : M400_fConvertADCToTemperature
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_fConvertADCToTemperature.
 * RELATED FILE  : include/m400_fConvertADCToTemperature.h
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
