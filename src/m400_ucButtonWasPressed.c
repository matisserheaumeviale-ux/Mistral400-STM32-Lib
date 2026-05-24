/* =============================================================================================
 * Function      : M400_ucButtonWasPressed
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_ucButtonWasPressed.
 * RELATED FILE  : src/m400_ucButtonWasPressed.c
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
#include "m400_ucButtonWasPressed.h"

#include <stddef.h>

uint8_t M400_ucButtonWasPressed(M400_Button_t *pxButton)
{
  uint8_t ucWasPressed = M400_OFF;

  if (pxButton == NULL)
  {
    return M400_OFF;
  }

  ucWasPressed = pxButton->ucPressedLatch;
  pxButton->ucPressedLatch = M400_OFF;

  return ucWasPressed;
}
