/*
 * File: m400_ucCompareStateChange.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for generic feedback state-change handling.
 * License: MIT
 */
#ifndef M400_UCCOMPARESTATECHANGE_H
#define M400_UCCOMPARESTATECHANGE_H

#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucCompareStateChange(uint8_t ucCurrentState,
                                  uint8_t ucPreviousState,
                                  uint8_t *pucStoredState,
                                  uint8_t *pucSoftwareCommand,
                                  uint8_t ucAutomaticMode,
                                  uint8_t *pucDelayCounter,
                                  uint8_t ucDelayReload);

#endif
