/*
 * File: m400_uiTachometerGetRPM.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for reading the last computed tachometer RPM.
 * License: MIT
 */
#ifndef M400_UITACHOMETERGETRPM_H
#define M400_UITACHOMETERGETRPM_H

#include "m400_types.h"
#include <stdint.h>

uint32_t M400_uiTachometerGetRPM(const M400_Tachometer_t *pxTachometer);

#endif
