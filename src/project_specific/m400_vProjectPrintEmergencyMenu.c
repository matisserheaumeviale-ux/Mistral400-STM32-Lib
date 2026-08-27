/* =============================================================================================
 * Function      : M400_vProjectPrintEmergencyMenu
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the project-specific UART emergency menu print helper.
 * RELATED FILE  : src/project_specific/m400_vProjectPrintEmergencyMenu.c
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
#include "project_specific/m400_vProjectPrintEmergencyMenu.h"

#include "m400_vUARTPrintString.h"

void M400_vProjectPrintEmergencyMenu(UART_HandleTypeDef *xUart, uint32_t uiTimeoutMs)
{
  static const char cMenu[] =
    "\r\n==============================\r\n"
    "     EMERGENCY STOP ACTIVE\r\n"
    "==============================\r\n"
    "All outputs are forced OFF.\r\n"
    "A = Leave emergency stop and enter automatic mode\r\n"
    "M = Leave emergency stop and enter manual mode\r\n"
    "H = Show this emergency menu again\r\n"
    "X = Run emergency stop again\r\n";

  M400_vUARTPrintString(xUart, cMenu, uiTimeoutMs);
}
