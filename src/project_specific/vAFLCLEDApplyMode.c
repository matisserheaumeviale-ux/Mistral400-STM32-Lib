/* =============================================================================================
 * Function      : vAFLCLEDApplyMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the AFLC LED mode mapping helper.
 * RELATED FILE  : src/project_specific/vAFLCLEDApplyMode.c
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
#include "project_specific/vAFLCLEDApplyMode.h"

#include "vLEDSet.h"

void vAFLCLEDApplyMode(LED_t *pxStatusLED,
                            LED_t *pxUSBLED,
                            LED_t *pxErrorLED,
                            LED_t *pxExtraLED,
                            AFLCLEDMode_t xMode,
                            uint32_t uiNowMs,
                            uint32_t uiCommActivityMs,
                            uint32_t uiHeartbeatPeriodMs,
                            uint32_t uiActivityHoldMs)
{
  uint8_t ucHeartbeatOn = 0U;
  uint8_t ucStatusOn = 0U;
  uint8_t ucErrorOn = 0U;
  uint8_t ucExtraOn = 0U;
  uint8_t ucUSBOn = 0U;

  if (uiHeartbeatPeriodMs > 0UL)
  {
    ucHeartbeatOn = (((uiNowMs / uiHeartbeatPeriodMs) & 1UL) == 0UL) ? ON : OFF;
  }

  switch (xMode)
  {
    case AFLC_LED_MODE_BOOT:
      ucStatusOn = ON;
      break;

    case AFLC_LED_MODE_PROFILES_READY:
      ucStatusOn = ON;
      ucExtraOn = ON;
      break;

    case AFLC_LED_MODE_WAIT_CONFIRM:
      ucStatusOn = ucHeartbeatOn;
      break;

    case AFLC_LED_MODE_STARTUP_TEST:
      ucStatusOn = ON;
      ucExtraOn = ucHeartbeatOn;
      break;

    case AFLC_LED_MODE_RUNTIME:
      ucStatusOn = ucHeartbeatOn;
      break;

    case AFLC_LED_MODE_FAULT:
    default:
      ucErrorOn = ON;
      break;
  }

  if ((uint32_t)(uiNowMs - uiCommActivityMs) <= uiActivityHoldMs)
  {
    ucUSBOn = ON;
  }

  vLEDSet(pxStatusLED, ucStatusOn);
  vLEDSet(pxUSBLED, ucUSBOn);
  vLEDSet(pxErrorLED, ucErrorOn);
  vLEDSet(pxExtraLED, ucExtraOn);
}
