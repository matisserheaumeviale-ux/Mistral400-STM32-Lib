/*
 * File: m400_ucCompareStateChange.c
 * Author: Matisse Rhéaume Viale
 * Description: Updates generic stored state when feedback changes.
 * License: MIT
 */
#include "m400_ucCompareStateChange.h"

#include <stddef.h>

uint8_t M400_ucCompareStateChange(uint8_t ucCurrentState,
                                  uint8_t ucPreviousState,
                                  uint8_t *pucStoredState,
                                  uint8_t *pucSoftwareCommand,
                                  uint8_t ucAutomaticMode,
                                  uint8_t *pucDelayCounter,
                                  uint8_t ucDelayReload)
{
  if (ucCurrentState == ucPreviousState)
  {
    return 0U;
  }

  if (pucStoredState != NULL)
  {
    *pucStoredState = ucCurrentState;
  }

  if ((pucSoftwareCommand != NULL) && (*pucSoftwareCommand == M400_ON))
  {
    *pucSoftwareCommand = M400_OFF;
    return 1U;
  }

  if ((ucAutomaticMode != 0U) && (pucDelayCounter != NULL))
  {
    *pucDelayCounter = ucDelayReload;
  }

  return 1U;
}
