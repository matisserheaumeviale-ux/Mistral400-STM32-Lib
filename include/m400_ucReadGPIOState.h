#ifndef M400_UCREADGPIOSTATE_H
#define M400_UCREADGPIOSTATE_H

#include "main.h"
#include <stdint.h>

#ifndef M400_OFF
#define M400_OFF 0U
#endif

#ifndef M400_ON
#define M400_ON  1U
#endif

uint8_t M400_ucReadGPIOState(GPIO_TypeDef *xPort,
                             uint16_t usPin,
                             GPIO_PinState xActiveState,
                             uint8_t ucDefaultState,
                             uint8_t ucUseRealFeedback);

#endif
