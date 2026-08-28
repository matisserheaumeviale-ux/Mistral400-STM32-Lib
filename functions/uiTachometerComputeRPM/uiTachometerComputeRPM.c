/* =============================================================================================
 * Function      : uiTachometerComputeRPM
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements uiTachometerComputeRPM.
 * RELATED FILE  : src/uiTachometerComputeRPM.c
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
#include "uiTachometerComputeRPM.h"

uint32_t uiTachometerComputeRPM(uint32_t uiPeriodTicks,
                                     uint32_t uiTimerFrequencyHz,
                                     uint32_t uiPulsesPerRevolution)
{
  if ((uiPeriodTicks == 0UL) || (uiTimerFrequencyHz == 0UL) || (uiPulsesPerRevolution == 0UL))
  {
    return 0UL;
  }

  return ((uiTimerFrequencyHz * 60UL) / uiPeriodTicks) / uiPulsesPerRevolution;
}
