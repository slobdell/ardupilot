---
layout: parameter
name: WNDVN_TEMP_PIN
display_name: "Wind vane speed sensor analog temp pin"
description: "Analog input pin for wind sensor temperature compensation"
default_value: -1
range: -1 100
units: ""
group: WNDVN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WindVane/AP_WindVane.cpp#L136
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_WindVane/AP_WindVane.h#L120
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Wind vane speed sensor analog temp pin (WNDVN_TEMP_PIN)

## Description
This parameter specifies the microcontroller pin connected to the temperature output of the wind speed sensor (specifically designed for the Modern Devices Wind Sensor Rev. P). This analog temperature reading is critical for compensating the hot-wire anemometer data, ensuring accurate wind speed measurements across varying ambient temperatures.

## The Mathematics
$$ V_{\text{wind\_comp}} = f(V_{\text{raw}}, V_{\text{temp}}) $$

## The Engineer's View
Defined in `libraries/AP_WindVane/AP_WindVane.cpp`.
*   **-1:** Disabled.
*   **Pin Number:** The ADC pin ID (e.g., 14 or 15).

## Tuning & Behavior
*   **Default Value:** -1 (Disabled)
*   **Usage:** Only relevant for analog hot-wire sensors. Mechanical cups/vanes do not use this.