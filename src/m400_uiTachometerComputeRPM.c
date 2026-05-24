/*
 * File: m400_uiTachometerComputeRPM.c
 * Author: Matisse Rhéaume Viale
 * Description: Computes RPM from tachometer period ticks.
 * License: MIT
 */
#include "m400_uiTachometerComputeRPM.h"

uint32_t M400_uiTachometerComputeRPM(uint32_t uiPeriodTicks,
                                     uint32_t uiTimerFrequencyHz,
                                     uint32_t uiPulsesPerRevolution)
{
  if ((uiPeriodTicks == 0UL) || (uiTimerFrequencyHz == 0UL) || (uiPulsesPerRevolution == 0UL))
  {
    return 0UL;
  }

  return ((uiTimerFrequencyHz * 60UL) / uiPeriodTicks) / uiPulsesPerRevolution;
}
