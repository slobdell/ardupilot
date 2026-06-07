---
layout: parameter
name: BARO_OPTIONS
display_name: "Barometer options"
description: "Bitmask of advanced barometer options and workarounds."
default_value: 0
range: null
units: "Bitmask"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L254
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Barometer options (BARO_OPTIONS)

## Description
This parameter is a bitmask used to enable specialized workarounds or features for barometric sensors. 

Its primary current use is to solve a common "Hardware Identity Crisis": some manufacturers sell flight controllers labeled as containing an MS5611 barometer, but actually install an MS5607 (which is cheaper and looks identical). If the software treats an MS5607 as an MS5611, your altitude will be wildly incorrect. Enabling the workaround bit here forces the software to use the correct math for the substituted part.

## The Mathematics
This parameter is a bitmask ($B$):
*   **Bit 0 (Value 1):** Treat MS5611 as MS5607.

If Bit 0 is set, the `AP_Baro_MS56XX` driver swaps the internal PROM coefficients and scaling constants ($C_1$ to $C_6$) to match the MS5607 physics model, ensuring correct pressure-to-altitude conversion.

## The Engineer's View
In `AP_Baro.cpp`, this is defined as `_options`.
In `AP_Baro_MS56XX::probe()`, the driver checks the global `AP_Baro` options. If the "Treat as MS5607" bit is set, it overrides the auto-detected sensor type. This is necessary because the MS5611 and MS5607 have the same I2C/SPI identifiers and cannot always be distinguished purely by electronic signatures.

## Tuning & Behavior
*   **Bit 0 (Value 1):** Enable the MS5611 $\rightarrow$ MS5607 workaround.
*   **Usage:** Only enable this if you are getting a `BARO_ALTERR_MAX` (GPS altitude discrepancy) error on a new flight controller and you suspect the manufacturer substituted the barometer.
*   **Reboot Required:** Yes. Barometer driver initialization happens on boot.

