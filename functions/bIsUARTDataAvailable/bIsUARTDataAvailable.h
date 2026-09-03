/* =============================================================================================
 * Function      : bIsUARTDataAvailable
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Checks if data is available to be read from the UART.
 * RELATED FILE  : include/bIsUARTDataAvailable.h
 * DEPENDENCIES  : UART_HandleTypeDef
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * UART_HandleTypeDef *xUart - Pointer to the UART handle
 * uint8_t *pucData - Pointer to store the received data
 * =============================================================================================
 * POINTER MANAGEMENT :
 * The function checks if the pointers are not NULL before dereferencing them.
 * =============================================================================================
 * Expected Result:
 * True if data is available, false otherwise
 * =============================================================================================
 */
#ifndef BISUARTDATAAVAILABLE_H
#define BISUARTDATAAVAILABLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

bool bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData);

#endif

#ifndef BISUARTDATAAVAILABLE_H
#define BISUARTDATAAVAILABLE_H

#include "main.h"
#include <stdbool.h>
#include <stdint.h>

bool bIsUARTDataAvailable(UART_HandleTypeDef *xUart, uint8_t *pucData);

#endif
