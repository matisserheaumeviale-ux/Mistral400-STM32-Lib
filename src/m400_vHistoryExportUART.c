/* =============================================================================================
 * Function      : M400_vHistoryExportUART
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vHistoryExportUART.
 * RELATED FILE  : src/m400_vHistoryExportUART.c
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
#include "m400_vHistoryExportUART.h"

#include <stddef.h>

static uint8_t AppendUInt(char *pcBuffer, uint8_t ucOffset, uint32_t uiValue);
static uint8_t AppendText(char *pcBuffer, uint8_t ucOffset, const char *pcText);
static void SendText(UART_HandleTypeDef *xUart, const char *pcText, uint32_t uiTimeoutMs);

void M400_vHistoryExportUART(UART_HandleTypeDef *xUart,
                             const uint16_t *pusBuffer,
                             uint32_t uiSampleCount,
                             uint32_t uiTimeoutMs)
{
  uint32_t uiIndex = 0UL;

  if ((xUart == NULL) || (pusBuffer == NULL))
  {
    return;
  }

  SendText(xUart, "Index,Sample\r\n", uiTimeoutMs);

  for (uiIndex = 0UL; uiIndex < uiSampleCount; uiIndex++)
  {
    char cLine[32];
    uint8_t ucOffset = 0U;

    ucOffset = AppendUInt(cLine, ucOffset, uiIndex + 1UL);
    cLine[ucOffset++] = ',';
    ucOffset = AppendUInt(cLine, ucOffset, pusBuffer[uiIndex]);
    ucOffset = AppendText(cLine, ucOffset, "\r\n");
    (void)HAL_UART_Transmit(xUart, (uint8_t *)cLine, ucOffset, uiTimeoutMs);
  }
}

static uint8_t AppendUInt(char *pcBuffer, uint8_t ucOffset, uint32_t uiValue)
{
  char cDigits[10];
  uint8_t ucCount = 0U;

  if (uiValue == 0UL)
  {
    pcBuffer[ucOffset++] = '0';
    return ucOffset;
  }

  while ((uiValue > 0UL) && (ucCount < sizeof(cDigits)))
  {
    cDigits[ucCount++] = (char)('0' + (uiValue % 10UL));
    uiValue /= 10UL;
  }

  while (ucCount > 0U)
  {
    pcBuffer[ucOffset++] = cDigits[--ucCount];
  }

  return ucOffset;
}

static uint8_t AppendText(char *pcBuffer, uint8_t ucOffset, const char *pcText)
{
  while (*pcText != '\0')
  {
    pcBuffer[ucOffset++] = *pcText;
    pcText++;
  }

  return ucOffset;
}

static void SendText(UART_HandleTypeDef *xUart, const char *pcText, uint32_t uiTimeoutMs)
{
  uint16_t usLength = 0U;

  while (pcText[usLength] != '\0')
  {
    usLength++;
  }

  (void)HAL_UART_Transmit(xUart, (uint8_t *)pcText, usLength, uiTimeoutMs);
}
