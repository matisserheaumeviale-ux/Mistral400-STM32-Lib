/* =============================================================================================
 * Function      : Types
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the public API for Types.
 * RELATED FILE  : include/types.h
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
#ifndef TYPES_H
#define TYPES_H

#include "main.h"
#include <stdint.h>

#ifndef OFF
#define OFF 0U
#endif

#ifndef ON
#define ON  1U
#endif

typedef struct
{
  uint32_t uiLastCaptureTick;
  uint32_t uiPeriodTicks;
  uint32_t uiLastPulseMs;
  uint32_t uiRPM;
  uint8_t ucHasCapture;
  uint8_t ucPendingPeriod;
  uint8_t ucSignalPresent;
} Tachometer_t;

typedef struct
{
  GPIO_TypeDef *xPort;
  uint16_t usPin;
  GPIO_PinState xActiveState;
  uint32_t uiDebounceMs;
  uint32_t uiLastChangeMs;
  uint8_t ucLastRawState;
  uint8_t ucStableState;
  uint8_t ucPressedLatch;
} Button_t;

typedef struct
{
  GPIO_TypeDef *xPort;
  uint16_t usPin;
  GPIO_PinState xActiveState;
  uint32_t uiLastToggleMs;
  uint8_t ucState;
} LED_t;

typedef struct
{
  UART_HandleTypeDef *xUart;
  uint8_t ucCommand;
  uint8_t ucAvailable;
} UARTCommand_t;

#endif
