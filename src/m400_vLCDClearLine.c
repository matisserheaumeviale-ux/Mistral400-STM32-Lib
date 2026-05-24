/*
 * File: m400_vLCDClearLine.c
 * Author: Matisse Rhéaume Viale
 * Description: Clears one LCD row with spaces.
 * License: MIT
 */
#include "m400_vLCDClearLine.h"

#include "m400_lcd.h"

void M400_vLCDClearLine(uint8_t ucRow, uint8_t ucWidth)
{
  char cLine[21];
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
  LCD_WriteAt(0U, ucRow, cLine);
}
