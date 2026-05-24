/*
 * File: m400_ucButtonWasPressed.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for consuming a debounced button press event.
 * License: MIT
 */
#ifndef M400_UCBUTTONWASPRESSED_H
#define M400_UCBUTTONWASPRESSED_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucButtonWasPressed(M400_Button_t *pxButton);

#endif
