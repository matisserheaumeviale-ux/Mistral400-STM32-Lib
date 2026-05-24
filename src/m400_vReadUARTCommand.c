/* =============================================================================================
 * Function      : M400_vReadUARTCommand
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vReadUARTCommand.
 * RELATED FILE  : src/m400_vReadUARTCommand.c
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
#include "m400_vReadUARTCommand.h"

#include <stddef.h>

void M400_vReadUARTCommand(UART_HandleTypeDef *xUart,
                           uint8_t *pucCommand,
                           uint32_t uiTimeoutMs)
{
  uint8_t ucByte = 0U;

  if ((xUart == NULL) || (pucCommand == NULL))
  {
    return;
  }

  if (HAL_UART_Receive(xUart, &ucByte, 1U, uiTimeoutMs) == HAL_OK)
  {
    *pucCommand = ucByte;
  }
}
