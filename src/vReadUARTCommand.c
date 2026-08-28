/* =============================================================================================
 * Function      : vReadUARTCommand
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vReadUARTCommand.
 * RELATED FILE  : src/vReadUARTCommand.c
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
#include "vReadUARTCommand.h"

#include <stddef.h>

void vReadUARTCommand(UART_HandleTypeDef *xUart,
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
