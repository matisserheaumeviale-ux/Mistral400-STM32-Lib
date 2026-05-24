/*
 * File: m400_uiTachometerComputeRPM.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for converting tachometer period ticks to RPM.
 * License: MIT
 */
#ifndef M400_UITACHOMETERCOMPUTERPM_H
#define M400_UITACHOMETERCOMPUTERPM_H

#include <stdint.h>

uint32_t M400_uiTachometerComputeRPM(uint32_t uiPeriodTicks,
                                     uint32_t uiTimerFrequencyHz,
                                     uint32_t uiPulsesPerRevolution);

#endif
