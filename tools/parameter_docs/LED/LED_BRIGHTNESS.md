---
layout: parameter
name: LED_BRIGHTNESS
display_name: "LED Brightness"
description: "Select the RGB LED brightness level"
default_value: 100
range: 0 100
units: "%"
group: LED
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L294
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# LED Brightness (LED_BRIGHTNESS)

## Description
This parameter controls the brightness intensity of the RGB status LED on the DroneCAN peripheral (e.g., GPS/Compass module). It allows you to dim the LED for stealth or power saving, or turn it off completely.

## The Mathematics
$$ \text{Duty Cycle} \propto \text{LED\_BRIGHTNESS} \% $$

## The Engineer's View
Defined in `Tools/AP_Periph/Parameters.cpp`. Used by the `ToshibaLED` or `NeoPixel` driver on the peripheral node.

## Tuning & Behavior
*   **Default Value:** 100% (High)
*   **0:** LED Off.
*   **10-50:** Dimmed.