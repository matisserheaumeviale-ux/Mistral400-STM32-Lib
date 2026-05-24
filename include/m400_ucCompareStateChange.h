/* =============================================================================================
 * Function      : M400_ucCompareStateChange
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_ucCompareStateChange.
 * RELATED FILE  : include/m400_ucCompareStateChange.h
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
#ifndef M400_UCCOMPARESTATECHANGE_H
#define M400_UCCOMPARESTATECHANGE_H

#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucCompareStateChange(uint8_t ucCurrentState,
                                  uint8_t ucPreviousState,
                                  uint8_t *pucStoredState,
                                  uint8_t *pucSoftwareCommand,
                                  uint8_t ucAutomaticMode,
                                  uint8_t *pucDelayCounter,
                                  uint8_t ucDelayReload);

#endif
