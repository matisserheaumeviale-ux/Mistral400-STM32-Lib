/* =============================================================================================
 * Function      : M400_ProjectTypes
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares project-specific helper types kept outside the generic M400 library.
 * RELATED FILE  : include/project_specific/m400_project_types.h
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
#ifndef M400_PROJECT_TYPES_H
#define M400_PROJECT_TYPES_H

#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

typedef void (*M400_ProjectOutputAction_t)(uint8_t *pucStateTable);

typedef struct
{
  uint8_t ucStateIndex;
  uint8_t ucDelayIndex;
  M400_ProjectOutputAction_t vTurnOn;
  M400_ProjectOutputAction_t vTurnOff;
} M400_ProjectControlledOutput_t;

#endif
