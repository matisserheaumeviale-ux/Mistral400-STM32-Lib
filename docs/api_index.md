<!--
File: api_index.md
Author: Matisse Rhéaume Viale
Description: Public API index for Mistral400 STM32 modules.
License: MIT
-->

# API Index

## GPIO And Output Control

- `M400_ucReadGPIOState()` - `include/m400_ucReadGPIOState.h`
- `M400_vGPIOPulse()` - `include/m400_vGPIOPulse.h`
- `M400_vApplyOutputState()` - `include/m400_vApplyOutputState.h`

## ADC, Temperature, And UART Reads

- `M400_usReadADC()` - `include/m400_usReadADC.h`
- `M400_fConvertADCToTemperature()` - `include/m400_fConvertADCToTemperature.h`
- `M400_bIsUARTDataAvailable()` - `include/m400_bIsUARTDataAvailable.h`
- `M400_vReadUARTCommand()` - `include/m400_vReadUARTCommand.h`

## Software Time Helpers

- `M400_vIncrementSoftwareTick()` - `include/m400_vIncrementSoftwareTick.h`
- `M400_bHasTickElapsed()` - `include/m400_bHasTickElapsed.h`
- `M400_vResetSoftwareCounter()` - `include/m400_vResetSoftwareCounter.h`
- `M400_vTimerPeriodElapsedCallback()` - `include/m400_vTimerPeriodElapsedCallback.h`

## History Buffer

- `M400_vHistoryAddSample()` - `include/m400_vHistoryAddSample.h`
- `M400_usHistoryGetSample()` - `include/m400_usHistoryGetSample.h`
- `M400_vHistoryClear()` - `include/m400_vHistoryClear.h`
- `M400_vHistoryExportUART()` - `include/m400_vHistoryExportUART.h`

## Control Helpers

- `M400_ucClampU8()` - `include/m400_ucClampU8.h`
- `M400_ucApplyHysteresisControl()` - `include/m400_ucApplyHysteresisControl.h`
- `M400_ucCompareStateChange()` - `include/m400_ucCompareStateChange.h`

## Fan PWM

- `M400_vFanPWMInit()` - `include/m400_vFanPWMInit.h`
- `M400_vFanSetDutyPermille()` - `include/m400_vFanSetDutyPermille.h`
- `M400_usFanGetDutyPermille()` - `include/m400_usFanGetDutyPermille.h`
- `M400_vFanStop()` - `include/m400_vFanStop.h`
- `M400_vFanStopAll()` - `include/m400_vFanStopAll.h`

## Tachometer

- `M400_vTachometerInit()` - `include/m400_vTachometerInit.h`
- `M400_vTachometerRegisterPulse()` - `include/m400_vTachometerRegisterPulse.h`
- `M400_uiTachometerComputeRPM()` - `include/m400_uiTachometerComputeRPM.h`
- `M400_vTachometerTask()` - `include/m400_vTachometerTask.h`
- `M400_uiTachometerGetRPM()` - `include/m400_uiTachometerGetRPM.h`

## Button

- `M400_vButtonInit()` - `include/m400_vButtonInit.h`
- `M400_ucButtonReadRaw()` - `include/m400_ucButtonReadRaw.h`
- `M400_ucButtonReadDebounced()` - `include/m400_ucButtonReadDebounced.h`
- `M400_vButtonTask()` - `include/m400_vButtonTask.h`
- `M400_ucButtonWasPressed()` - `include/m400_ucButtonWasPressed.h`

## LED

- `M400_vLEDInit()` - `include/m400_vLEDInit.h`
- `M400_vLEDSet()` - `include/m400_vLEDSet.h`
- `M400_vLEDToggle()` - `include/m400_vLEDToggle.h`
- `M400_vLEDBlinkTask()` - `include/m400_vLEDBlinkTask.h`

## UART Command

- `M400_vUARTCommandInit()` - `include/m400_vUARTCommandInit.h`
- `M400_ucUARTCommandAvailable()` - `include/m400_ucUARTCommandAvailable.h`
- `M400_ucUARTCommandRead()` - `include/m400_ucUARTCommandRead.h`
- `M400_vUARTPrintString()` - `include/m400_vUARTPrintString.h`

## LCD UI Helpers

- `M400_vLCDPrintStatusLine()` - `include/m400_vLCDPrintStatusLine.h`
- `M400_vLCDPrintCentered()` - `include/m400_vLCDPrintCentered.h`
- `M400_vLCDClearLine()` - `include/m400_vLCDClearLine.h`

## Shared Type Header

- `M400_Tachometer_t`, `M400_Button_t`, `M400_LED_t`, and `M400_UARTCommand_t` are declared in `include/m400_types.h`.
