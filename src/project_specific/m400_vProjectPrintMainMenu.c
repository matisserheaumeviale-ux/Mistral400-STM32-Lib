/* =============================================================================================
 * Function      : M400_vProjectPrintMainMenu
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the project-specific UART main menu print helper.
 * RELATED FILE  : src/project_specific/m400_vProjectPrintMainMenu.c
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
#include "project_specific/m400_vProjectPrintMainMenu.h"

#include "m400_vUARTPrintString.h"

void M400_vProjectPrintMainMenu(UART_HandleTypeDef *xUart, uint32_t uiTimeoutMs)
{
  static const char cMenu[] =
    "\r\nFinal Session Project\r\n"
    "Basic domotic control with temperature history\r\n"
    "\r\n"
    "PC commands:\r\n"
    "A = Automatic mode\r\n"
    "M = Manual mode\r\n"
    "X = Emergency stop\r\n"
    "ESC = Emergency stop\r\n"
    "H = Show main menu\r\n"
    "T = Transfer history\r\n"
    "J = Toggle day/night periodic display\r\n"
    "0 = Clear history\r\n"
    "\r\n"
    "Automatic mode:\r\n"
    "C = Decrease low setpoint\r\n"
    "D = Increase low setpoint\r\n"
    "V = Decrease high setpoint\r\n"
    "F = Increase high setpoint\r\n"
    "L = Light ON\r\n"
    "K = Light OFF\r\n"
    "\r\n"
    "Manual mode:\r\n"
    "D = Heating ON\r\n"
    "C = Heating OFF\r\n"
    "F = Fan ON\r\n"
    "V = Fan OFF\r\n"
    "L = Light ON\r\n"
    "K = Light OFF\r\n";

  M400_vUARTPrintString(xUart, cMenu, uiTimeoutMs);
}
