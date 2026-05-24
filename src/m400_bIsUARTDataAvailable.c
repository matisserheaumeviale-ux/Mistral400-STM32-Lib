/* =============================================================================================
 * Function      : M400_bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_bIsUARTDataAvailable.
 * RELATED FILE  : src/m400_bIsUARTDataAvailable.c
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
#include "m400_bIsUARTDataAvailable.h"

#include <stddef.h>

bool M400_bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData)
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
