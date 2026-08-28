/* =============================================================================================
 * Function      : vLEDBlinkTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for vLEDBlinkTask.
 * RELATED FILE  : include/vLEDBlinkTask.h
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
#ifndef VLEDBLINKTASK_H
#define VLEDBLINKTASK_H

#include "types.h"
#include <stdint.h>

void vLEDBlinkTask(LED_t *pxLED,
                        uint32_t uiNowMs,
                        uint32_t uiPeriodMs,
                        uint8_t ucEnabled);

#endif
