/* =============================================================================================
 * Function      : ucUARTCommandAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucUARTCommandAvailable.
 * RELATED FILE  : include/ucUARTCommandAvailable.h
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
#ifndef UCUARTCOMMANDAVAILABLE_H
#define UCUARTCOMMANDAVAILABLE_H

#include "types.h"
#include <stdint.h>

uint8_t ucUARTCommandAvailable(UARTCommand_t *pxCommand);

#endif
