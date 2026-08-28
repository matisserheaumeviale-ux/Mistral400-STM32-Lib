/* =============================================================================================
 * Function      : ucUARTCommandAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucUARTCommandAvailable.
 * RELATED FILE  : src/ucUARTCommandAvailable.c
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
#include "ucUARTCommandAvailable.h"

#include "bIsUARTDataAvailable.h"

#include <stddef.h>

uint8_t ucUARTCommandAvailable(UARTCommand_t *pxCommand)
{
  uint8_t ucByte = 0U;

  if ((pxCommand == NULL) || (pxCommand->xUart == NULL))
  {
    return OFF;
  }

  if (pxCommand->ucAvailable != 0U)
  {
    return ON;
  }

  if (bIsUARTDataAvailable(pxCommand->xUart, &ucByte))
  {
    pxCommand->ucCommand = ucByte;
    pxCommand->ucAvailable = ON;
  }

  return pxCommand->ucAvailable;
}
