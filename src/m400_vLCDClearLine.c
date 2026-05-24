/* =============================================================================================
 * Function      : M400_vLCDClearLine
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vLCDClearLine.
 * RELATED FILE  : src/m400_vLCDClearLine.c
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
