<!--
File: extraction_report.md
Author: Matisse Rhéaume Viale
Description: Extraction report for reusable Mistral400 STM32 modules.
License: MIT
-->

# Extraction Report

## Scope

Reusable code was extracted from `legacy/projet_fin_session_2026/` and `legacy/aflc/` into `include/` and `src/` using the `M400_` naming convention. The legacy folders were kept unchanged.

## Extracted From `legacy/projet_fin_session_2026`

### `actions.c`

- `M400_ucReadGPIOState()` from `xLireEtatDepuisPin()`
- `M400_vGPIOPulse()` from `xImpulsionCommande()`
- `M400_vApplyOutputState()` from `xAppliquerEtatElement()`

The new versions are generic and do not reference heating, ventilation, or lighting.

### `lectures.c`

- `M400_usReadADC()` from the raw ADC read flow
- `M400_fConvertADCToTemperature()` from the NTC conversion formula
- `M400_bIsUARTDataAvailable()` from non-blocking UART receive logic
- `M400_vReadUARTCommand()` from single-byte UART command reading

Project-specific keyboard command handling was not extracted.

### `temps.c`

- `M400_vIncrementSoftwareTick()`
- `M400_bHasTickElapsed()`
- `M400_vResetSoftwareCounter()`
- `M400_vTimerPeriodElapsedCallback()`

`TIM2_IRQHandler()` was not extracted because interrupt handlers are project and startup-file specific.

### `historique.c`

- `M400_vHistoryAddSample()`
- `M400_usHistoryGetSample()`
- `M400_vHistoryClear()`
- `M400_vHistoryExportUART()`

The new history API uses caller-owned `uint16_t` buffers and does not depend on a global project array.

### `affichage.c`

No project menu was extracted. The display text is specific to the school project. Generic LCD helpers were instead extracted from AFLC UI patterns.

### `controle.c`

- `M400_ucClampU8()`
- `M400_ucApplyHysteresisControl()`
- `M400_ucCompareStateChange()`

The full automatic and manual control modes were not extracted because they directly depend on heating, ventilation, lighting, and project table indexes.

## Extracted From `legacy/aflc`

### `fan_control.c/.h`

- `M400_vFanPWMInit()`
- `M400_vFanSetDutyPermille()`
- `M400_usFanGetDutyPermille()`
- `M400_vFanStop()`
- `M400_vFanStopAll()`

The AFLC fan state machine, startup test, fault policy, and profile-to-RPM mapping were not copied into the main library.

### `tachometer.c/.h`

- `M400_vTachometerInit()`
- `M400_vTachometerRegisterPulse()`
- `M400_uiTachometerComputeRPM()`
- `M400_vTachometerTask()`
- `M400_uiTachometerGetRPM()`

The new version uses a caller-owned `M400_Tachometer_t` context instead of fixed TIM2 channels.

### `button.c/.h`

- `M400_vButtonInit()`
- `M400_ucButtonReadRaw()`
- `M400_ucButtonReadDebounced()`
- `M400_vButtonTask()`
- `M400_ucButtonWasPressed()`

The UART-only simulated confirm button from AFLC was not copied as application logic.

### `led_status.c/.h`

- `M400_vLEDInit()`
- `M400_vLEDSet()`
- `M400_vLEDToggle()`
- `M400_vLEDBlinkTask()`

AFLC-specific LED modes were not extracted.

### `uart_cmd.c/.h`

- `M400_vUARTCommandInit()`
- `M400_ucUARTCommandAvailable()`
- `M400_ucUARTCommandRead()`
- `M400_vUARTPrintString()`

The AFLC command menu and fan test commands were not extracted.

### `ui_lcd.c/.h`

- `M400_vLCDPrintStatusLine()`
- `M400_vLCDPrintCentered()`
- `M400_vLCDClearLine()`

AFLC runtime screens, profile screens, startup screens, and debug overlays were not extracted.

## Shared Types

`include/m400_types.h` contains reusable context structs for tachometer, button, LED, and UART command helpers. It has no public function and exists so each public function can still stay in its own matching source/header pair.

## Ignored As Too Specific

- School project menus and emergency-state text
- Heating, ventilation, lighting action wrappers
- Automatic mode tied to temperature and luminosity outputs
- `TIM2_IRQHandler()`
- AFLC fan ramp test and startup safe-state policy
- AFLC profile rendering and runtime LCD screens
- AFLC full UART command menu
- Missing `AFLCalcul`, `Profil`, and `temperature_stub` modules were not present in this local legacy tree, so no extraction was performed for them.
