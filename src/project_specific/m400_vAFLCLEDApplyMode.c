/* =============================================================================================
 * Function      : M400_vAFLCLEDApplyMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the AFLC LED mode mapping helper.
 * RELATED FILE  : src/project_specific/m400_vAFLCLEDApplyMode.c
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
#include "project_specific/m400_vAFLCLEDApplyMode.h"

#include "m400_vLEDSet.h"

void M400_vAFLCLEDApplyMode(M400_LED_t *pxStatusLED,
                            M400_LED_t *pxUSBLED,
                            M400_LED_t *pxErrorLED,
                            M400_LED_t *pxExtraLED,
                            M400_AFLCLEDMode_t xMode,
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
    ucHeartbeatOn = (((uiNowMs / uiHeartbeatPeriodMs) & 1UL) == 0UL) ? M400_ON : M400_OFF;
  }

  switch (xMode)
  {
    case M400_AFLC_LED_MODE_BOOT:
      ucStatusOn = M400_ON;
      break;

    case M400_AFLC_LED_MODE_PROFILES_READY:
      ucStatusOn = M400_ON;
      ucExtraOn = M400_ON;
      break;

    case M400_AFLC_LED_MODE_WAIT_CONFIRM:
      ucStatusOn = ucHeartbeatOn;
      break;

    case M400_AFLC_LED_MODE_STARTUP_TEST:
      ucStatusOn = M400_ON;
      ucExtraOn = ucHeartbeatOn;
      break;

    case M400_AFLC_LED_MODE_RUNTIME:
      ucStatusOn = ucHeartbeatOn;
      break;

    case M400_AFLC_LED_MODE_FAULT:
    default:
      ucErrorOn = M400_ON;
      break;
  }

  if ((uint32_t)(uiNowMs - uiCommActivityMs) <= uiActivityHoldMs)
  {
    ucUSBOn = M400_ON;
  }

  M400_vLEDSet(pxStatusLED, ucStatusOn);
  M400_vLEDSet(pxUSBLED, ucUSBOn);
  M400_vLEDSet(pxErrorLED, ucErrorOn);
  M400_vLEDSet(pxExtraLED, ucExtraOn);
}
