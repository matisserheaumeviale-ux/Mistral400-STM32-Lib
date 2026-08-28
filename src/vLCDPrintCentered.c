/* =============================================================================================
 * Function      : vLCDPrintCentered
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vLCDPrintCentered.
 * RELATED FILE  : src/vLCDPrintCentered.c
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
#include "vLCDPrintCentered.h"

#include "lcd.h"

#include <stddef.h>

void vLCDPrintCentered(uint8_t ucRow, const char *pcText, uint8_t ucWidth)
{
  char cLine[21];
  uint8_t ucTextLength = 0U;
  uint8_t ucOffset = 0U;
  uint8_t ucIndex = 0U;

  if (pcText == NULL)
  {
    return;
  }

  if (ucWidth > 20U)
  {
    ucWidth = 20U;
  }

  while ((pcText[ucTextLength] != '\0') && (ucTextLength < ucWidth))
  {
    ucTextLength++;
  }

  ucOffset = (uint8_t)((ucWidth - ucTextLength) / 2U);

  for (ucIndex = 0U; ucIndex < ucWidth; ucIndex++)
  {
    cLine[ucIndex] = ' ';
  }

  for (ucIndex = 0U; ucIndex < ucTextLength; ucIndex++)
  {
    cLine[ucOffset + ucIndex] = pcText[ucIndex];
  }

  cLine[ucWidth] = '\0';
  LCD_WriteAt(0U, ucRow, cLine);
}
