---
layout: parameter
name: FS_OPTIONS
display_name: Failsafe Options
description: A bitmask of options that allow the drone to continue its mission or specific actions during a failsafe event.
default_value: 16
range: 0 63
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Failsafe Options (FS_OPTIONS)

## Description
`FS_OPTIONS` allows you to customize exactly when the drone should "Ignore" a radio or GCS failure and keep flying.

*   **Bit 0 (1): RC Continue if Auto.** If the drone is on an autonomous mission, it will keep going even if the RC transmitter is turned off.
*   **Bit 1 (2): GCS Continue if Auto.** Keeps the mission going if the telemetry link is lost.
*   **Bit 4 (16): GCS Continue if Pilot Control.** (Default). If you are using a GCS to control the drone but still have your RC radio connected, losing the GCS link will not trigger a failsafe.

## Tuning & Behavior
*   **Default Value:** 16.
*   **Safety:** Only enable Bits 0 or 1 if you are an expert and have verified that your drone has a fully autonomous landing/safety plan.