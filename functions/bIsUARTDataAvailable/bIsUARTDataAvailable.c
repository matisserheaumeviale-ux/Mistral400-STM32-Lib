/* =============================================================================================
 * Function      : bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.1A
 * =============================================================================================
 * DESCRIPTION :
 * Checks if data is available to be read from the UART.
 * RELATED FILE  : src/bIsUARTDataAvailable.c
 * DEPENDENCIES  : UART_HandleTypeDef
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * UART_HandleTypeDef *xUart - Pointer to the UART handle
 * uint8_t *pucData - Pointer to store the received data
 * =============================================================================================
 * POINTER MANAGEMENT :
 * The function checks if the pointers are not NULL before dereferencing them.
 * =============================================================================================
 * Expected Result:
 * True if data is available, false otherwise
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

