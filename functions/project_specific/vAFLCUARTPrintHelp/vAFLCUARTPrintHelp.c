/* =============================================================================================
 * Function      : vAFLCUARTPrintHelp
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements the AFLC UART help menu print helper.
 * RELATED FILE  : src/project_specific/vAFLCUARTPrintHelp.c
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
#include "project_specific/vAFLCUARTPrintHelp.h"

#include "vUARTPrintString.h"

void vAFLCUARTPrintHelp(UART_HandleTypeDef *xUart, uint32_t uiTimeoutMs)
{
  static const char cHelp[] =
    "\r\nCommands:\r\n"
    "  h : help\r\n"
    "  s : system status\r\n"
    "  t : tach/rpm status\r\n"
    "  c : confirm startup\r\n"
    "  ? : toggle LCD fan debug\r\n"
    "  0..9 : set all fans to 0%..90%\r\n"
    "  a : set all fans to 100%\r\n"
    "  z : non-blocking ramp test\r\n";

  vUARTPrintString(xUart, cHelp, uiTimeoutMs);
}
