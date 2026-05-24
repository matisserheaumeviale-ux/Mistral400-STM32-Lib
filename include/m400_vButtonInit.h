/*
 * File: m400_vButtonInit.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for initializing a debounced GPIO button context.
 * License: MIT
 */
#ifndef M400_VBUTTONINIT_H
#define M400_VBUTTONINIT_H

#include "m400_types.h"
#include <stdint.h>

void M400_vButtonInit(M400_Button_t *pxButton,
                      GPIO_TypeDef *xPort,
                      uint16_t usPin,
                      GPIO_PinState xActiveState,
                      uint32_t uiDebounceMs);

#endif
