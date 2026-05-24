/*
 * File: m400_ucButtonReadDebounced.c
 * Author: Matisse Rhéaume Viale
 * Description: Returns the stable state held by a button context.
 * License: MIT
 */
#include "m400_ucButtonReadDebounced.h"

#include <stddef.h>

uint8_t M400_ucButtonReadDebounced(const M400_Button_t *pxButton)
{
  if (pxButton == NULL)
  {
    return M400_OFF;
  }

  return pxButton->ucStableState;
}
