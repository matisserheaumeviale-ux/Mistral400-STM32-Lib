/* =============================================================================================
 * Function      : vButtonInit
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements vButtonInit.
 * RELATED FILE  : src/vButtonInit.c
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
#include "vButtonInit.h"

#include <stddef.h>

void vButtonInit(Button_t *pxButton,
                      GPIO_TypeDef *xPort,
                      uint16_t usPin,
                      GPIO_PinState xActiveState,
                      uint32_t uiDebounceMs)
{
  if (pxButton == NULL)
  {
    return;
  }

  pxButton->xPort = xPort;
  pxButton->usPin = usPin;
  pxButton->xActiveState = xActiveState;
  pxButton->uiDebounceMs = uiDebounceMs;
  pxButton->uiLastChangeMs = 0UL;
  pxButton->ucLastRawState = OFF;
  pxButton->ucStableState = OFF;
  pxButton->ucPressedLatch = OFF;
}
