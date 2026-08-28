<!--
File: extraction_report.md
Author: Matisse Rhéaume Viale
Description: Extraction report for reusable Mistral400 STM32 modules.
License: MIT
-->

# Extraction Report

## Scope

Reusable code was extracted from `legacy/projet_fin_session_2026/` and `legacy/aflc/` into `include/` and `src/` using descriptive names without a library-specific function prefix. The legacy folders were kept unchanged.

## Extracted From `legacy/projet_fin_session_2026`

### `actions.c`

- `ucReadGPIOState()` from `xLireEtatDepuisPin()`
- `vGPIOPulse()` from `xImpulsionCommande()`
- `vApplyOutputState()` from `xAppliquerEtatElement()`

The new versions are generic and do not reference heating, ventilation, or lighting.

### `lectures.c`

- `usReadADC()` from the raw ADC read flow
- `fConvertADCToTemperature()` from the NTC conversion formula
- `bIsUARTDataAvailable()` from non-blocking UART receive logic
- `vReadUARTCommand()` from single-byte UART command reading

Project-specific keyboard command handling was not extracted.

### `temps.c`

- `vIncrementSoftwareTick()`
- `bHasTickElapsed()`
- `vResetSoftwareCounter()`
- `vTimerPeriodElapsedCallback()`

`TIM2_IRQHandler()` was not extracted because interrupt handlers are project and startup-file specific.

### `historique.c`

- `vHistoryAddSample()`
- `usHistoryGetSample()`
- `vHistoryClear()`
- `vHistoryExportUART()`

The new history API uses caller-owned `uint16_t` buffers and does not depend on a global project array.

### `affichage.c`

The generic LCD helpers remain in the main library. The school-project UART text was extracted into `project_specific`:

- `vProjectPrintMainMenu()`
- `vProjectPrintEmergencyMenu()`
- `vProjectPrintSystemState()`

### `controle.c`

- `ucClampU8()`
- `ucApplyHysteresisControl()`
- `ucCompareStateChange()`

The generic control helpers remain in the main library. The school-project automatic mode pattern was extracted into `project_specific`:

- `vProjectApplyAutomaticMode()`

It uses callback hooks instead of directly depending on heating, fan, or light functions.

## Extracted From `legacy/aflc`

### `fan_control.c/.h`

- `vFanPWMInit()`
- `vFanSetDutyPermille()`
- `usFanGetDutyPermille()`
- `vFanStop()`
- `vFanStopAll()`

The AFLC fan state machine remains outside the main library. The reusable AFLC-specific status helpers were extracted into `project_specific`:

- `vAFLCFanUpdateStatus()`
- `bAFLCFanHasAnyFault()`
- `vAFLCFanRampTask()`

The full profile-to-RPM mapping was not copied.

### `tachometer.c/.h`

- `vTachometerInit()`
- `vTachometerRegisterPulse()`
- `uiTachometerComputeRPM()`
- `vTachometerTask()`
- `uiTachometerGetRPM()`

The new version uses a caller-owned `Tachometer_t` context instead of fixed TIM2 channels.

### `button.c/.h`

- `vButtonInit()`
- `ucButtonReadRaw()`
- `ucButtonReadDebounced()`
- `vButtonTask()`
- `ucButtonWasPressed()`

The UART-only simulated confirm button from AFLC was not copied as application logic.

### `led_status.c/.h`

- `vLEDInit()`
- `vLEDSet()`
- `vLEDToggle()`
- `vLEDBlinkTask()`

AFLC-specific LED mode mapping was extracted into `project_specific`:

- `vAFLCLEDApplyMode()`

### `uart_cmd.c/.h`

- `vUARTCommandInit()`
- `ucUARTCommandAvailable()`
- `ucUARTCommandRead()`
- `vUARTPrintString()`

The AFLC UART help menu was extracted into `project_specific`:

- `vAFLCUARTPrintHelp()`

The full command executor was not copied because it directly dispatches AFLC application actions.

### `ui_lcd.c/.h`

- `vLCDPrintStatusLine()`
- `vLCDPrintCentered()`
- `vLCDClearLine()`

AFLC runtime screens, profile screens, startup screens, and debug overlays were not extracted.

## Shared Types

`include/types.h` contains reusable context structs for tachometer, button, LED, and UART command helpers. It has no public function and exists so each public function can still stay in its own matching source/header pair.

## Ignored As Too Specific

- School project menus and emergency-state text
- Heating, ventilation, lighting action wrappers
- `TIM2_IRQHandler()`
- AFLC startup safe-state policy
- AFLC profile rendering and runtime LCD screens
- AFLC full UART command menu
- Missing `AFLCalcul`, `Profil`, and `temperature_stub` modules were not present in this local legacy tree, so no extraction was performed for them.
