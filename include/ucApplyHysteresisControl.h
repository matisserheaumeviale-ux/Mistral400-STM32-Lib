/* =============================================================================================
 * Function      : ucApplyHysteresisControl
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucApplyHysteresisControl.
 * RELATED FILE  : include/ucApplyHysteresisControl.h
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
#ifndef UCAPPLYHYSTERESISCONTROL_H
#define UCAPPLYHYSTERESISCONTROL_H

#include <stdint.h>

#ifndef OFF
#define OFF 0U
#endif

#ifndef ON
#define ON  1U
#endif

uint8_t ucApplyHysteresisControl(float fValue,
                                      float fLowThreshold,
                                      float fHighThreshold,
                                      uint8_t ucCurrentState);

#endif
