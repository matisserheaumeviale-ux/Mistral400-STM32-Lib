/* =============================================================================================
 * Function      : AFLCTypes
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares AFLC-specific helper types kept outside the generic library.
 * RELATED FILE  : include/project_specific/aflc_types.h
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
#ifndef AFLC_TYPES_H
#define AFLC_TYPES_H

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
  AFLC_FAN_STATE_OFF = 0,
  AFLC_FAN_STATE_STARTING,
  AFLC_FAN_STATE_RUNNING,
  AFLC_FAN_STATE_ERROR
} AFLCFanState_t;

typedef enum
{
  AFLC_FAN_ACTION_NONE = 0,
  AFLC_FAN_ACTION_ACCEL,
  AFLC_FAN_ACTION_DETECT,
  AFLC_FAN_ACTION_DECEL,
  AFLC_FAN_ACTION_IDLE,
  AFLC_FAN_ACTION_RAMP
} AFLCFanAction_t;

typedef enum
{
  AFLC_FAN_ALERT_NONE = 0,
  AFLC_FAN_ALERT_WARN,
  AFLC_FAN_ALERT_FAULT
} AFLCFanAlert_t;

typedef enum
{
  AFLC_LED_MODE_BOOT = 0,
  AFLC_LED_MODE_PROFILES_READY,
  AFLC_LED_MODE_WAIT_CONFIRM,
  AFLC_LED_MODE_STARTUP_TEST,
  AFLC_LED_MODE_RUNTIME,
  AFLC_LED_MODE_FAULT
} AFLCLEDMode_t;

typedef struct
{
  AFLCFanState_t xState;
  AFLCFanAction_t xAction;
  AFLCFanAlert_t xAlert;
  uint16_t usRPM;
  uint16_t usTargetRPM;
  uint8_t ucPercent;
} AFLCFanStatus_t;

typedef void (*AFLCSetAllDutyCallback_t)(uint16_t usDutyPermille, void *pvUserData);

typedef struct
{
  bool bActive;
  uint16_t usCurrentPermille;
  uint16_t usStepPermille;
  uint16_t usMaxPermille;
  uint32_t uiStepMs;
  uint32_t uiNextStepMs;
  AFLCSetAllDutyCallback_t vSetAllDuty;
  void *pvUserData;
} AFLCRamp_t;

#endif
