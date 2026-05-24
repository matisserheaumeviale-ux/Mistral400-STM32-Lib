/* =============================================================================================
 * Function      : M400_vButtonTask
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vButtonTask.
 * RELATED FILE  : src/m400_vButtonTask.c
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
#include "m400_vButtonTask.h"

#include "m400_ucButtonReadRaw.h"

#include <stddef.h>

void M400_vButtonTask(M400_Button_t *pxButton, uint32_t uiNowMs)
{
  uint8_t ucRawState = M400_OFF;

  if (pxButton == NULL)
  {
    return;
  }

  ucRawState = M400_ucButtonReadRaw(pxButton);
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
    if (ucRawState == M400_ON)
    {
      pxButton->ucPressedLatch = M400_ON;
    }
  }
}
