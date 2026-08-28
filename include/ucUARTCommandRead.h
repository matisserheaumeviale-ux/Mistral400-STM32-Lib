/* =============================================================================================
 * Function      : ucUARTCommandRead
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for ucUARTCommandRead.
 * RELATED FILE  : include/ucUARTCommandRead.h
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
#ifndef UCUARTCOMMANDREAD_H
#define UCUARTCOMMANDREAD_H

#include "types.h"
#include <stdint.h>

uint8_t ucUARTCommandRead(UARTCommand_t *pxCommand);

#endif
