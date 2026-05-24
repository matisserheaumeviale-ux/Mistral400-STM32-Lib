/*
 * File: m400_vLCDPrintStatusLine.c
 * Author: Matisse Rhéaume Viale
 * Description: Prints a label, numeric value, and unit on one LCD line.
 * License: MIT
 */
#include "m400_vLCDPrintStatusLine.h"

#include "m400_lcd.h"

#include <stddef.h>

static uint8_t AppendTextLimited(char *pcLine, uint8_t ucOffset, const char *pcText, uint8_t ucWidth);
static uint8_t AppendUIntLimited(char *pcLine, uint8_t ucOffset, uint16_t usValue, uint8_t ucWidth);

void M400_vLCDPrintStatusLine(uint8_t ucRow,
                              const char *pcLabel,
                              uint16_t usValue,
                              const char *pcUnit,
                              uint8_t ucWidth)
{
  char cLine[21];
  uint8_t ucOffset = 0U;
  uint8_t ucIndex = 0U;

  if (ucWidth > 20U)
  {
    ucWidth = 20U;
  }

  for (ucIndex = 0U; ucIndex < ucWidth; ucIndex++)
  {
    cLine[ucIndex] = ' ';
  }
  cLine[ucWidth] = '\0';

  ucOffset = AppendTextLimited(cLine, ucOffset, pcLabel, ucWidth);
  if (ucOffset < ucWidth)
  {
    cLine[ucOffset++] = ' ';
  }
  ucOffset = AppendUIntLimited(cLine, ucOffset, usValue, ucWidth);
  (void)AppendTextLimited(cLine, ucOffset, pcUnit, ucWidth);

  LCD_WriteAt(0U, ucRow, cLine);
}

static uint8_t AppendTextLimited(char *pcLine, uint8_t ucOffset, const char *pcText, uint8_t ucWidth)
{
  if (pcText == NULL)
  {
    return ucOffset;
  }

  while ((*pcText != '\0') && (ucOffset < ucWidth))
  {
    pcLine[ucOffset++] = *pcText;
    pcText++;
  }

  return ucOffset;
}

static uint8_t AppendUIntLimited(char *pcLine, uint8_t ucOffset, uint16_t usValue, uint8_t ucWidth)
{
  char cDigits[5];
  uint8_t ucCount = 0U;

  if (usValue == 0U)
  {
    if (ucOffset < ucWidth)
    {
      pcLine[ucOffset++] = '0';
    }
    return ucOffset;
  }

  while ((usValue > 0U) && (ucCount < sizeof(cDigits)))
  {
    cDigits[ucCount++] = (char)('0' + (usValue % 10U));
    usValue /= 10U;
  }

  while ((ucCount > 0U) && (ucOffset < ucWidth))
  {
    pcLine[ucOffset++] = cDigits[--ucCount];
  }

  return ucOffset;
}
