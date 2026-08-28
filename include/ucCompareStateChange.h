/* =============================================================================================
 * Function      : ucCompareStateChange
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucCompareStateChange.
 * RELATED FILE  : include/ucCompareStateChange.h
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
#ifndef UCCOMPARESTATECHANGE_H
#define UCCOMPARESTATECHANGE_H

#include <stdint.h>

#ifndef OFF
#define OFF 0U
#endif

#ifndef ON
#define ON  1U
#endif

uint8_t ucCompareStateChange(uint8_t ucCurrentState,
                                  uint8_t ucPreviousState,
                                  uint8_t *pucStoredState,
                                  uint8_t *pucSoftwareCommand,
                                  uint8_t ucAutomaticMode,
                                  uint8_t *pucDelayCounter,
                                  uint8_t ucDelayReload);

#endif
