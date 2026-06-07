---
layout: parameter
name: RNGFND_MAX_RATE
display_name: Rangefinder Max Update Rate
description: The maximum frequency (in Hz) at which rangefinder data is sent to the flight controller.
default_value: 50
range: 0 200
units: Hz
group: RNGFND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Tools/AP_Periph/Parameters.cpp#L350
---

# Rangefinder Max Update Rate (RNGFND_MAX_RATE)

## Description
`RNGFND_MAX_RATE` acts as a "Data Limiter" for your distance sensor. 

While high-end Lidars can report data hundreds of times per second, sending all that data over a CAN or MAVLink network can cause congestion (too much traffic). This parameter ensures that the sensor node only sends a fresh measurement at this maximum frequency, keeping the network efficient.

*   **0:** No limit (Send as fast as possible).
*   **50 (Default):** Sufficient for most navigation and landing tasks.

## Tuning & Behavior
*   **Default:** 50 Hz.
*   **Recommendation:** Leave at **50** for most setups. If you have multiple distance sensors on a slow CAN bus, you might reduce this to **20** to free up bandwidth.
*   **Note:** This is primarily used on **AP_Periph** CAN nodes.