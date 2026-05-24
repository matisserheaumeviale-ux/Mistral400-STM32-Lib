/* =============================================================================================
 * Function      : M400_vLEDToggle
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements M400_vLEDToggle.
 * RELATED FILE  : src/m400_vLEDToggle.c
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
#include "m400_vLEDToggle.h"

#include "m400_vLEDSet.h"

#include <stddef.h>

void M400_vLEDToggle(M400_LED_t *pxLED)
{
  if (pxLED == NULL)
  {
    return;
  }

  M400_vLEDSet(pxLED, (pxLED->ucState == M400_OFF) ? M400_ON : M400_OFF);
}
