/* =============================================================================================
 * Function      : M400_ucUARTCommandAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucUARTCommandAvailable.
 * RELATED FILE  : src/m400_ucUARTCommandAvailable.c
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
#include "m400_ucUARTCommandAvailable.h"

#include "m400_bIsUARTDataAvailable.h"

#include <stddef.h>

uint8_t M400_ucUARTCommandAvailable(M400_UARTCommand_t *pxCommand)
{
  uint8_t ucByte = 0U;

  if ((pxCommand == NULL) || (pxCommand->xUart == NULL))
  {
    return M400_OFF;
  }

  if (pxCommand->ucAvailable != 0U)
  {
    return M400_ON;
  }

  if (M400_bIsUARTDataAvailable(pxCommand->xUart, &ucByte))
  {
    pxCommand->ucCommand = ucByte;
    pxCommand->ucAvailable = M400_ON;
  }

  return pxCommand->ucAvailable;
}
