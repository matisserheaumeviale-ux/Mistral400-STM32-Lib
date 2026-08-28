/* =============================================================================================
 * Function      : ucUARTCommandRead
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucUARTCommandRead.
 * RELATED FILE  : src/ucUARTCommandRead.c
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
#include "ucUARTCommandRead.h"

#include <stddef.h>

uint8_t ucUARTCommandRead(UARTCommand_t *pxCommand)
{
  uint8_t ucCommand = 0U;

  if (pxCommand == NULL)
  {
    return 0U;
  }

  ucCommand = pxCommand->ucCommand;
  pxCommand->ucAvailable = 0U;
  pxCommand->ucCommand = 0U;

  return ucCommand;
}
