---
layout: parameter
name: RNGFND_LND_ORNT
display_name: Rangefinder Landing Orientation
description: Selects the specific rangefinder instance (by orientation) used for landing detection.
default_value: 25
range: 0 38
units: 
group: RNGFND
visual_asset_id: prx_orientation_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L1295
---

# Rangefinder Landing Orientation (RNGFND_LND_ORNT)

## Description
`RNGFND_LND_ORNT` tells the landing controller which way the "Ground" sensor is facing.

*   **Standard Plane/Copter:** Set to **25 (Pitch 270 / Down)**.
*   **Tailsitter (Landing on tail):** Set to **4 (Back)**.

## Tuning & Behavior
*   **Default:** 25 (Down).
*   **Significance:** If you have multiple rangefinders (e.g. one pointing forward for obstacle avoidance and one pointing down for landing), this parameter ensures the landing logic only listens to the downward-facing one.