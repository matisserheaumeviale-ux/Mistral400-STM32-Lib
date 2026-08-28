/* =============================================================================================
 * Function      : ProjectTypes
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * ???
 * RELATED FILE  : include/project_specific/project_types.h
 * DEPENDENCIES  : ???
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * ???
 * POINTER MANAGEMENT :
 * ???
 * =============================================================================================
 * Expected Result:
 * ???
 * =============================================================================================
 */
#ifndef PROJECT_TYPES_H
#define PROJECT_TYPES_H

#include <stdint.h>

#ifndef OFF
#define OFF 0U
#endif

#ifndef ON
#define ON  1U
#endif

typedef void (*ProjectOutputAction_t)(uint8_t *pucStateTable);

typedef struct
{
  uint8_t ucStateIndex;
  uint8_t ucDelayIndex;
  ProjectOutputAction_t vTurnOn;
  ProjectOutputAction_t vTurnOff;
} ProjectControlledOutput_t;

#endif
