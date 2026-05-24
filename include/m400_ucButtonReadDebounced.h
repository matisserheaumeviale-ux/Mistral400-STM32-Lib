/*
 * File: m400_ucButtonReadDebounced.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading the stable button state.
 * License: MIT
 */
#ifndef M400_UCBUTTONREADDEBOUNCED_H
#define M400_UCBUTTONREADDEBOUNCED_H

#include "m400_types.h"
#include <stdint.h>

uint8_t M400_ucButtonReadDebounced(const M400_Button_t *pxButton);

#endif
