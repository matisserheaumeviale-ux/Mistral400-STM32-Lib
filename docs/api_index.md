<!--
File: api_index.md
Author: Matisse Rhéaume Viale
Description: Public API index for Mistral400 STM32 modules.
License: MIT
-->

# API Index

## GPIO And Output Control

- `ucReadGPIOState()` - `include/ucReadGPIOState.h`
- `vGPIOPulse()` - `include/vGPIOPulse.h`
- `vApplyOutputState()` - `include/vApplyOutputState.h`

## ADC, Temperature, And UART Reads

- `usReadADC()` - `include/usReadADC.h`
- `fConvertADCToTemperature()` - `include/fConvertADCToTemperature.h`
- `bIsUARTDataAvailable()` - `include/bIsUARTDataAvailable.h`
- `vReadUARTCommand()` - `include/vReadUARTCommand.h`

## Software Time Helpers

- `vIncrementSoftwareTick()` - `include/vIncrementSoftwareTick.h`
- `bHasTickElapsed()` - `include/bHasTickElapsed.h`
- `vResetSoftwareCounter()` - `include/vResetSoftwareCounter.h`
- `vTimerPeriodElapsedCallback()` - `include/vTimerPeriodElapsedCallback.h`

## History Buffer

- `vHistoryAddSample()` - `include/vHistoryAddSample.h`
- `usHistoryGetSample()` - `include/usHistoryGetSample.h`
- `vHistoryClear()` - `include/vHistoryClear.h`
- `vHistoryExportUART()` - `include/vHistoryExportUART.h`

## Control Helpers

- `ucClampU8()` - `include/ucClampU8.h`
- `ucApplyHysteresisControl()` - `include/ucApplyHysteresisControl.h`
- `ucCompareStateChange()` - `include/ucCompareStateChange.h`

## Fan PWM

- `vFanPWMInit()` - `include/vFanPWMInit.h`
- `vFanSetDutyPermille()` - `include/vFanSetDutyPermille.h`
- `usFanGetDutyPermille()` - `include/usFanGetDutyPermille.h`
- `vFanStop()` - `include/vFanStop.h`
- `vFanStopAll()` - `include/vFanStopAll.h`

## Tachometer

- `vTachometerInit()` - `include/vTachometerInit.h`
- `vTachometerRegisterPulse()` - `include/vTachometerRegisterPulse.h`
- `uiTachometerComputeRPM()` - `include/uiTachometerComputeRPM.h`
- `vTachometerTask()` - `include/vTachometerTask.h`
- `uiTachometerGetRPM()` - `include/uiTachometerGetRPM.h`

## Button

- `vButtonInit()` - `include/vButtonInit.h`
- `ucButtonReadRaw()` - `include/ucButtonReadRaw.h`
- `ucButtonReadDebounced()` - `include/ucButtonReadDebounced.h`
- `vButtonTask()` - `include/vButtonTask.h`
- `ucButtonWasPressed()` - `include/ucButtonWasPressed.h`

## LED

- `vLEDInit()` - `include/vLEDInit.h`
- `vLEDSet()` - `include/vLEDSet.h`
- `vLEDToggle()` - `include/vLEDToggle.h`
- `vLEDBlinkTask()` - `include/vLEDBlinkTask.h`

## UART Command

- `vUARTCommandInit()` - `include/vUARTCommandInit.h`
- `ucUARTCommandAvailable()` - `include/ucUARTCommandAvailable.h`
- `ucUARTCommandRead()` - `include/ucUARTCommandRead.h`
- `vUARTPrintString()` - `include/vUARTPrintString.h`

## LCD UI Helpers

- `vLCDPrintStatusLine()` - `include/vLCDPrintStatusLine.h`
- `vLCDPrintCentered()` - `include/vLCDPrintCentered.h`
- `vLCDClearLine()` - `include/vLCDClearLine.h`

## Shared Type Header

- `Tachometer_t`, `Button_t`, `LED_t`, and `UARTCommand_t` are declared in `include/types.h`.

## Project-Specific School Helpers

- `vProjectPrintMainMenu()` - `include/project_specific/vProjectPrintMainMenu.h`
- `vProjectPrintEmergencyMenu()` - `include/project_specific/vProjectPrintEmergencyMenu.h`
- `vProjectPrintSystemState()` - `include/project_specific/vProjectPrintSystemState.h`
- `vProjectApplyAutomaticMode()` - `include/project_specific/vProjectApplyAutomaticMode.h`
- `ProjectControlledOutput_t` is declared in `include/project_specific/project_types.h`.

## Project-Specific AFLC Helpers

- `vAFLCFanUpdateStatus()` - `include/project_specific/vAFLCFanUpdateStatus.h`
- `bAFLCFanHasAnyFault()` - `include/project_specific/bAFLCFanHasAnyFault.h`
- `vAFLCFanRampTask()` - `include/project_specific/vAFLCFanRampTask.h`
- `vAFLCUARTPrintHelp()` - `include/project_specific/vAFLCUARTPrintHelp.h`
- `vAFLCLEDApplyMode()` - `include/project_specific/vAFLCLEDApplyMode.h`
- AFLC project-specific status, ramp, and LED mode types are declared in `include/project_specific/aflc_types.h`.
