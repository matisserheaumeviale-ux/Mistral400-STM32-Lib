/* =============================================================================================
 * Function      : M400_ucUARTCommandRead
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for M400_ucUARTCommandRead.
 * RELATED FILE  : include/m400_ucUARTCommandRead.h
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
#ifndef M400_UCUARTCOMMANDREAD_H
#define M400_UCUARTCOMMANDREAD_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucUARTCommandRead(M400_UARTCommand_t *pxCommand);

#endif
