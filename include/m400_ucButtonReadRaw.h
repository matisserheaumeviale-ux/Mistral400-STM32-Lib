/*
 * File: m400_ucButtonReadRaw.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading a raw GPIO button state.
 * License: MIT
 */
#ifndef M400_UCBUTTONREADRAW_H
#define M400_UCBUTTONREADRAW_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucButtonReadRaw(const M400_Button_t *pxButton);

#endif
