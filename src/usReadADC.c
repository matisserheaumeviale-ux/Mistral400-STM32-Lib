/* =============================================================================================
 * Function      : usReadADC
 * =============================================================================================
 * AUTHOR        : Matisse Rhéaume-Viale & AFLC
 * VERSION       : 1.0
 * =============================================================================================
 * DESCRIPTION :
 * Implements usReadADC.
 * RELATED FILE  : src/usReadADC.c
 * DEPENDENCIES  : See file includes.
 * =============================================================================================
 * DATA TYPES & VARIABLES :
 * Uses the types and variables visible in the function signature.
 * POINTER MANAGEMENT :
 * Validates pointers when received by the function.
 * =============================================================================================
 * Expected Result:
 * The function performs its task without affecting other parts of the program.
 * =============================================================================================
 */
#include "usReadADC.h"

#include <stddef.h>

uint16_t usReadADC(ADC_HandleTypeDef *xAdc,
                        uint32_t uiChannel,
                        uint32_t uiRank,
                        uint32_t uiSamplingTime,
                        uint8_t ucSampleCount,
                        uint32_t uiPollTimeoutMs)
{
  ADC_ChannelConfTypeDef xConfig = {0};
  uint32_t uiTotal = 0UL;
  uint8_t ucIndex = 0U;

  if ((xAdc == NULL) || (ucSampleCount == 0U))
  {
    return 0U;
  }

  xConfig.Channel = uiChannel;
  xConfig.Rank = uiRank;
  xConfig.SamplingTime = uiSamplingTime;

  if (HAL_ADC_ConfigChannel(xAdc, &xConfig) != HAL_OK)
  {
    return 0U;
  }

  for (ucIndex = 0U; ucIndex < ucSampleCount; ucIndex++)
  {
    if (HAL_ADC_Start(xAdc) != HAL_OK)
    {
      (void)HAL_ADC_Stop(xAdc);
      return 0U;
    }

    if (HAL_ADC_PollForConversion(xAdc, uiPollTimeoutMs) != HAL_OK)
    {
      (void)HAL_ADC_Stop(xAdc);
      return 0U;
    }

    uiTotal += HAL_ADC_GetValue(xAdc);
    (void)HAL_ADC_Stop(xAdc);
  }

  return (uint16_t)(uiTotal / ucSampleCount);
}
