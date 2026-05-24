/* =============================================================================================
 * Function      : M400_ucUARTCommandAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_ucUARTCommandAvailable.
 * RELATED FILE  : include/m400_ucUARTCommandAvailable.h
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
#ifndef M400_UCUARTCOMMANDAVAILABLE_H
#define M400_UCUARTCOMMANDAVAILABLE_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucUARTCommandAvailable(M400_UARTCommand_t *pxCommand);

#endif
