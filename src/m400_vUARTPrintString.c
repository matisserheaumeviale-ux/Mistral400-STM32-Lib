/* =============================================================================================
 * Function      : M400_vUARTPrintString
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vUARTPrintString.
 * RELATED FILE  : src/m400_vUARTPrintString.c
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
#include "m400_vUARTPrintString.h"

#include <stddef.h>

void M400_vUARTPrintString(UART_HandleTypeDef *xUart,
                           const char *pcText,
                           uint32_t uiTimeoutMs)
{
  uint16_t usLength = 0U;

  if ((xUart == NULL) || (pcText == NULL))
  {
    return;
  }

  while (pcText[usLength] != '\0')
  {
    usLength++;
  }

  if (usLength > 0U)
  {
    (void)HAL_UART_Transmit(xUart, (uint8_t *)pcText, usLength, uiTimeoutMs);
  }
}
