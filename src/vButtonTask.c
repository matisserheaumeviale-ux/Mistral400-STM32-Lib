/* =============================================================================================
 * Function      : vButtonTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vButtonTask.
 * RELATED FILE  : src/vButtonTask.c
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
#include "vButtonTask.h"

#include "ucButtonReadRaw.h"

#include <stddef.h>

void vButtonTask(Button_t *pxButton, uint32_t uiNowMs)
{
  uint8_t ucRawState = OFF;

  if (pxButton == NULL)
  {
    return;
  }

  ucRawState = ucButtonReadRaw(pxButton);
  if (ucRawState != pxButton->ucLastRawState)
  {
    pxButton->ucLastRawState = ucRawState;
    pxButton->uiLastChangeMs = uiNowMs;
    return;
  }

  if (((uint32_t)(uiNowMs - pxButton->uiLastChangeMs) >= pxButton->uiDebounceMs) &&
      (ucRawState != pxButton->ucStableState))
  {
    pxButton->ucStableState = ucRawState;
    if (ucRawState == ON)
    {
      pxButton->ucPressedLatch = ON;
    }
  }
}
