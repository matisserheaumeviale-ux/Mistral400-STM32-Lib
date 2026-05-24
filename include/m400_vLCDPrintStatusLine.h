/*
 * File: m400_vLCDPrintStatusLine.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for printing a compact LCD status line.
 * License: MIT
 */
#ifndef M400_VLCDPRINTSTATUSLINE_H
#define M400_VLCDPRINTSTATUSLINE_H

#include <stdint.h>

void M400_vLCDPrintStatusLine(uint8_t ucRow,
                              const char *pcLabel,
                              uint16_t usValue,
                              const char *pcUnit,
                              uint8_t ucWidth);

#endif
