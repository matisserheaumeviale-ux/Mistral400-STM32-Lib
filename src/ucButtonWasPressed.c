/* =============================================================================================
 * Function      : ucButtonWasPressed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements ucButtonWasPressed.
 * RELATED FILE  : src/ucButtonWasPressed.c
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
#include "ucButtonWasPressed.h"

#include <stddef.h>

uint8_t ucButtonWasPressed(Button_t *pxButton)
{
  uint8_t ucWasPressed = OFF;

  if (pxButton == NULL)
  {
    return OFF;
  }

  ucWasPressed = pxButton->ucPressedLatch;
  pxButton->ucPressedLatch = OFF;

  return ucWasPressed;
}
