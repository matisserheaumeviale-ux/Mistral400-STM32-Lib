/*
 * File: m400_ucApplyHysteresisControl.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for simple threshold hysteresis control.
 * License: MIT
 */
#ifndef M400_UCAPPLYHYSTERESISCONTROL_H
#define M400_UCAPPLYHYSTERESISCONTROL_H

#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucApplyHysteresisControl(float fValue,
                                      float fLowThreshold,
                                      float fHighThreshold,
                                      uint8_t ucCurrentState);

#endif
