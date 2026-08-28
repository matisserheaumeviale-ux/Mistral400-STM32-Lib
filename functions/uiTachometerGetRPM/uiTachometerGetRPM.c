/* =============================================================================================
 * Function      : uiTachometerGetRPM
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements uiTachometerGetRPM.
 * RELATED FILE  : src/uiTachometerGetRPM.c
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
#include "uiTachometerGetRPM.h"

#include <stddef.h>

uint32_t uiTachometerGetRPM(const Tachometer_t *pxTachometer)
{
  if (pxTachometer == NULL)
  {
    return 0UL;
  }

  return pxTachometer->uiRPM;
}
