/*
 * File: m400_vButtonTask.h
 * Author: Matisse Rhéaume Viale
 * Description: Public API for updating a debounced button context.
 * License: MIT
 */
#ifndef M400_VBUTTONTASK_H
#define M400_VBUTTONTASK_H

#include "m400_types.h"
#include <stdint.h>

void M400_vButtonTask(M400_Button_t *pxButton, uint32_t uiNowMs);

#endif
