/*
 * File: m400_vResetSoftwareCounter.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for resetting a software counter.
 * License: MIT
 */
#ifndef M400_VRESETSOFTWARECOUNTER_H
#define M400_VRESETSOFTWARECOUNTER_H

#include <stdint.h>

void M400_vResetSoftwareCounter(uint32_t *puiCounter);

#endif
