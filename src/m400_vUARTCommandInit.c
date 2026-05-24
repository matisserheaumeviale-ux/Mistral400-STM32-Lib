/* =============================================================================================
 * Function      : M400_vUARTCommandInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vUARTCommandInit.
 * RELATED FILE  : src/m400_vUARTCommandInit.c
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
#include "m400_vUARTCommandInit.h"

#include <stddef.h>

void M400_vUARTCommandInit(M400_UARTCommand_t *pxCommand, UART_HandleTypeDef *xUart)
{
  if (pxCommand == NULL)
  {
    return;
  }

  pxCommand->xUart = xUart;
  pxCommand->ucCommand = 0U;
  pxCommand->ucAvailable = 0U;
}
