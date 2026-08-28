/* =============================================================================================
 * Function      : bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.1A
 * =============================================================================================
 * DESCRIPTION :
 * Implements bIsUARTDataAvailable.
 * RELATED FILE  : src/bIsUARTDataAvailable.c
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
#include "bIsUARTDataAvailable.h"

#include <stddef.h>

bool bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData)
{
  uint8_t ucByte = 0U;

  if (xUart == NULL)
  {
    return false;
  }

  if (HAL_UART_Receive(xUart, &ucByte, 1U, 0U) != HAL_OK)
  {
    return false;
  }

  if (pucData != NULL)
  {
    *pucData = ucByte;
  }

  return true;
}
