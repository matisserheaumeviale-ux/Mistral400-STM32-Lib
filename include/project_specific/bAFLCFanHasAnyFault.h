/* =============================================================================================
 * Function      : bAFLCFanHasAnyFault
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares an AFLC fan status fault scan helper.
 * RELATED FILE  : include/project_specific/bAFLCFanHasAnyFault.h
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
#ifndef BAFLCFANHASANYFAULT_H
#define BAFLCFANHASANYFAULT_H

#include "project_specific/aflc_types.h"
#include <stdbool.h>
#include <stdint.h>

bool bAFLCFanHasAnyFault(const AFLCFanStatus_t *pxStatuses, uint8_t ucCount);

#endif
