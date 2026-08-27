/* =============================================================================================
 * Function      : M400_vProjectPrintSystemState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements a project-specific compact UART system state print helper.
 * RELATED FILE  : src/project_specific/m400_vProjectPrintSystemState.c
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
#include "project_specific/m400_vProjectPrintSystemState.h"

#include "m400_vUARTPrintString.h"

#include <stddef.h>

static uint8_t AppendText(char *pcBuffer, uint8_t ucOffset, const char *pcText, uint8_t ucMax);
static uint8_t AppendUInt(char *pcBuffer, uint8_t ucOffset, uint32_t uiValue, uint8_t ucMax);
static uint8_t AppendState(char *pcBuffer, uint8_t ucOffset, uint8_t ucState, uint8_t ucMax);

void M400_vProjectPrintSystemState(UART_HandleTypeDef *xUart,
                                   const uint8_t *pucStateTable,
                                   uint8_t ucMode,
                                   uint16_t usTemperatureC,
                                   uint8_t ucLowSetpoint,
                                   uint8_t ucHighSetpoint,
                                   uint8_t ucHeatingStateIndex,
                                   uint8_t ucHeatingDelayIndex,
                                   uint8_t ucFanStateIndex,
                                   uint8_t ucFanDelayIndex,
                                   uint8_t ucLightStateIndex,
                                   uint8_t ucLightDelayIndex,
                                   uint32_t uiTimeoutMs)
{
  char cLine[160];
  uint8_t ucOffset = 0U;

  if (pucStateTable == NULL)
  {
    return;
  }

  ucOffset = AppendText(cLine, ucOffset, (ucMode != 0U) ? "A: " : "M: ", sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, "Temp=", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, usTemperatureC, sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, "C High=", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, ucHighSetpoint, sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, " Low=", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, ucLowSetpoint, sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, " Heat=", sizeof(cLine) - 1U);
  ucOffset = AppendState(cLine, ucOffset, pucStateTable[ucHeatingStateIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, "(", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, pucStateTable[ucHeatingDelayIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, ") Fan=", sizeof(cLine) - 1U);
  ucOffset = AppendState(cLine, ucOffset, pucStateTable[ucFanStateIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, "(", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, pucStateTable[ucFanDelayIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, ") Light=", sizeof(cLine) - 1U);
  ucOffset = AppendState(cLine, ucOffset, pucStateTable[ucLightStateIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, "(", sizeof(cLine) - 1U);
  ucOffset = AppendUInt(cLine, ucOffset, pucStateTable[ucLightDelayIndex], sizeof(cLine) - 1U);
  ucOffset = AppendText(cLine, ucOffset, ")\r\n", sizeof(cLine) - 1U);
  cLine[ucOffset] = '\0';

  M400_vUARTPrintString(xUart, cLine, uiTimeoutMs);
}

static uint8_t AppendText(char *pcBuffer, uint8_t ucOffset, const char *pcText, uint8_t ucMax)
{
  while ((*pcText != '\0') && (ucOffset < ucMax))
  {
    pcBuffer[ucOffset++] = *pcText;
    pcText++;
  }

  return ucOffset;
}

static uint8_t AppendUInt(char *pcBuffer, uint8_t ucOffset, uint32_t uiValue, uint8_t ucMax)
{
  char cDigits[10];
  uint8_t ucCount = 0U;

  if (uiValue == 0UL)
  {
    if (ucOffset < ucMax)
    {
      pcBuffer[ucOffset++] = '0';
    }
    return ucOffset;
  }

  while ((uiValue > 0UL) && (ucCount < sizeof(cDigits)))
  {
    cDigits[ucCount++] = (char)('0' + (uiValue % 10UL));
    uiValue /= 10UL;
  }

  while ((ucCount > 0U) && (ucOffset < ucMax))
  {
    pcBuffer[ucOffset++] = cDigits[--ucCount];
  }

  return ucOffset;
}

static uint8_t AppendState(char *pcBuffer, uint8_t ucOffset, uint8_t ucState, uint8_t ucMax)
{
  return AppendText(pcBuffer, ucOffset, (ucState != 0U) ? "ON" : "OFF", ucMax);
}
