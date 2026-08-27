/* =============================================================================================
 * Function      : M400_AFLCTypes
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares AFLC-specific helper types kept outside the generic M400 library.
 * RELATED FILE  : include/project_specific/m400_aflc_types.h
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
#ifndef M400_AFLC_TYPES_H
#define M400_AFLC_TYPES_H

#include <stdbool.h>
#include <stdint.h>

typedef enum
{
  M400_AFLC_FAN_STATE_OFF = 0,
  M400_AFLC_FAN_STATE_STARTING,
  M400_AFLC_FAN_STATE_RUNNING,
  M400_AFLC_FAN_STATE_ERROR
} M400_AFLCFanState_t;

typedef enum
{
  M400_AFLC_FAN_ACTION_NONE = 0,
  M400_AFLC_FAN_ACTION_ACCEL,
  M400_AFLC_FAN_ACTION_DETECT,
  M400_AFLC_FAN_ACTION_DECEL,
  M400_AFLC_FAN_ACTION_IDLE,
  M400_AFLC_FAN_ACTION_RAMP
} M400_AFLCFanAction_t;

typedef enum
{
  M400_AFLC_FAN_ALERT_NONE = 0,
  M400_AFLC_FAN_ALERT_WARN,
  M400_AFLC_FAN_ALERT_FAULT
} M400_AFLCFanAlert_t;

typedef enum
{
  M400_AFLC_LED_MODE_BOOT = 0,
  M400_AFLC_LED_MODE_PROFILES_READY,
  M400_AFLC_LED_MODE_WAIT_CONFIRM,
  M400_AFLC_LED_MODE_STARTUP_TEST,
  M400_AFLC_LED_MODE_RUNTIME,
  M400_AFLC_LED_MODE_FAULT
} M400_AFLCLEDMode_t;

typedef struct
{
  M400_AFLCFanState_t xState;
  M400_AFLCFanAction_t xAction;
  M400_AFLCFanAlert_t xAlert;
  uint16_t usRPM;
  uint16_t usTargetRPM;
  uint8_t ucPercent;
} M400_AFLCFanStatus_t;

typedef void (*M400_AFLCSetAllDutyCallback_t)(uint16_t usDutyPermille, void *pvUserData);

typedef struct
{
  bool bActive;
  uint16_t usCurrentPermille;
  uint16_t usStepPermille;
  uint16_t usMaxPermille;
  uint32_t uiStepMs;
  uint32_t uiNextStepMs;
  M400_AFLCSetAllDutyCallback_t vSetAllDuty;
  void *pvUserData;
} M400_AFLCRamp_t;

#endif
