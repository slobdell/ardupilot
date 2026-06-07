---
layout: parameter
name: PLND_BUS
display_name: Sensor Bus
description: Selects the I2C bus number for the precision landing sensor (e.g., IR-Lock).
default_value: -1
range: -1 3
units: 
group: PLND
visual_asset_id: i2c_bus_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L92
---

# Sensor Bus (PLND_BUS)

## Description
`PLND_BUS` specifies where you plugged in your I2C-based landing sensor (like an IR-Lock).

*   **-1 (Default):** The autopilot probes all external buses for a compatible sensor.
*   **0:** Forces the internal bus.
*   **1:** Forces the external bus (standard GPS/Compass port).

## Tuning & Behavior
*   **Default Value:** -1.
*   **Recommendation:** Leave at **-1** unless you have multiple identical sensors on different buses or a specialized hardware conflict.