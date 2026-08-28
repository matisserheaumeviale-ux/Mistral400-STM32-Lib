/* =============================================================================================
 * Function      : vProjectApplyAutomaticMode
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements automatic temperature and day/night control with project callbacks.
 * RELATED FILE  : src/project_specific/vProjectApplyAutomaticMode.c
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
#include "project_specific/vProjectApplyAutomaticMode.h"

#include <stddef.h>

static void ApplyTemperatureLow(uint8_t *pucStateTable,
                                float fTemperatureC,
                                uint8_t ucSetpoint,
                                const ProjectControlledOutput_t *pxOutput);
static void ApplyTemperatureHigh(uint8_t *pucStateTable,
                                 float fTemperatureC,
                                 uint8_t ucSetpoint,
                                 const ProjectControlledOutput_t *pxOutput);
static void ApplyLight(uint8_t *pucStateTable,
                       uint8_t ucDayState,
                       uint8_t ucNightState,
                       const ProjectControlledOutput_t *pxOutput);

void vProjectApplyAutomaticMode(uint8_t *pucStateTable,
                                     float fTemperatureC,
                                     uint8_t ucLowSetpoint,
                                     uint8_t ucHighSetpoint,
                                     uint8_t ucDayState,
                                     uint8_t ucNightState,
                                     const ProjectControlledOutput_t *pxHeating,
                                     const ProjectControlledOutput_t *pxFan,
                                     const ProjectControlledOutput_t *pxLight)
{
  if (pucStateTable == NULL)
  {
    return;
  }

  ApplyTemperatureLow(pucStateTable, fTemperatureC, ucLowSetpoint, pxHeating);
  ApplyTemperatureHigh(pucStateTable, fTemperatureC, ucHighSetpoint, pxFan);
  ApplyLight(pucStateTable, ucDayState, ucNightState, pxLight);
}

static void ApplyTemperatureLow(uint8_t *pucStateTable,
                                float fTemperatureC,
                                uint8_t ucSetpoint,
                                const ProjectControlledOutput_t *pxOutput)
{
  if ((pxOutput == NULL) || (pucStateTable[pxOutput->ucDelayIndex] != 0U))
  {
    return;
  }

  if ((fTemperatureC < (float)ucSetpoint) && (pxOutput->vTurnOn != NULL))
  {
    pxOutput->vTurnOn(pucStateTable);
  }
  else if ((fTemperatureC > (float)ucSetpoint) && (pxOutput->vTurnOff != NULL))
  {
    pxOutput->vTurnOff(pucStateTable);
  }
}

static void ApplyTemperatureHigh(uint8_t *pucStateTable,
                                 float fTemperatureC,
                                 uint8_t ucSetpoint,
                                 const ProjectControlledOutput_t *pxOutput)
{
  if ((pxOutput == NULL) || (pucStateTable[pxOutput->ucDelayIndex] != 0U))
  {
    return;
  }

  if ((fTemperatureC > (float)ucSetpoint) && (pxOutput->vTurnOn != NULL))
  {
    pxOutput->vTurnOn(pucStateTable);
  }
  else if ((fTemperatureC < (float)ucSetpoint) && (pxOutput->vTurnOff != NULL))
  {
    pxOutput->vTurnOff(pucStateTable);
  }
}

static void ApplyLight(uint8_t *pucStateTable,
                       uint8_t ucDayState,
                       uint8_t ucNightState,
                       const ProjectControlledOutput_t *pxOutput)
{
  if ((pxOutput == NULL) || (pucStateTable[pxOutput->ucDelayIndex] != 0U))
  {
    return;
  }

  if ((ucDayState == ON) && (pxOutput->vTurnOff != NULL))
  {
    pxOutput->vTurnOff(pucStateTable);
  }
  else if ((ucNightState == ON) && (pxOutput->vTurnOn != NULL))
  {
    pxOutput->vTurnOn(pucStateTable);
  }
}
