/*
 * File: m400_vLCDPrintCentered.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for printing centered text on a character LCD line.
 * License: MIT
 */
#ifndef M400_VLCDPRINTCENTERED_H
#define M400_VLCDPRINTCENTERED_H

#include <stdint.h>

void M400_vLCDPrintCentered(uint8_t ucRow, const char *pcText, uint8_t ucWidth);

#endif
