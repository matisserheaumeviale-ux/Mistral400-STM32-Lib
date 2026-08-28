/* =============================================================================================
 * Function      : vProjectPrintMainMenu
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Declares the project-specific UART main menu print helper.
 * RELATED FILE  : include/project_specific/vProjectPrintMainMenu.h
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
#ifndef VPROJECTPRINTMAINMENU_H
#define VPROJECTPRINTMAINMENU_H

#include "main.h"
#include <stdint.h>

void vProjectPrintMainMenu(UART_HandleTypeDef *xUart, uint32_t uiTimeoutMs);

#endif
