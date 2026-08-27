/* =============================================================================================
 * Function      : M400_vProjectPrintSystemState
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares a project-specific compact UART system state print helper.
 * RELATED FILE  : include/project_specific/m400_vProjectPrintSystemState.h
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
#ifndef M400_VPROJECTPRINTSYSTEMSTATE_H
#define M400_VPROJECTPRINTSYSTEMSTATE_H

#include "main.h"
#include <stdint.h>

void M400_vProjectPrintSystemState(UART_HandleTypeDef *xUart,
                                   const uint8_t *pucStateTable,
                                   uint8_t ucMode,
                                   uint16_t usTemperatureC,
                                   uint8_t ucLowSetpoint,
                                   uint8_t ucHighSetpoint,
                                   uint8_t ucHeatingStateIndex,
                                   uint8_t ucHeatingDelayIndex,
                                   uint8_t ucFanStateIndex,
                                   uint8_t ucFanDelayIndex,
                                   uint8_t ucLightStateIndex,
                                   uint8_t ucLightDelayIndex,
                                   uint32_t uiTimeoutMs);

#endif
