/* =============================================================================================
 * Function      : M400_ucApplyHysteresisControl
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_ucApplyHysteresisControl.
 * RELATED FILE  : include/m400_ucApplyHysteresisControl.h
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
#ifndef M400_UCAPPLYHYSTERESISCONTROL_H
#define M400_UCAPPLYHYSTERESISCONTROL_H

#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucApplyHysteresisControl(float fValue,
                                      float fLowThreshold,
                                      float fHighThreshold,
                                      uint8_t ucCurrentState);

#endif
