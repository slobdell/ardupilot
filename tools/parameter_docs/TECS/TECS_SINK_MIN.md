---
layout: parameter
name: TECS_SINK_MIN
display_name: Minimum Glide Sink Rate
description: The expected vertical descent rate (sink) of the aircraft at cruise speed with motors at minimum throttle.
default_value: 2.0
range: 0.1 10.0
units: m/s
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_TECS/AP_TECS.cpp#L35
---

# Minimum Glide Sink Rate (TECS_SINK_MIN)

## Description
`TECS_SINK_MIN` defines the "Glide Profile" of your aircraft. 

It represents the vertical descent rate the plane naturally experiences when flying at its cruise speed with the engine at idle or turned off. This is a fundamental physical constant for the TECS (Total Energy Control System) to understand how much potential energy (altitude) is lost simply to overcome aerodynamic drag.

## Tuning & Behavior
*   **Default:** 2.0 m/s.
*   **Calibration:** Fly the plane in Manual or FBWA mode, cut the throttle, and maintain a level cruise speed. Note your rate of descent on the GCS. Enter that value here.
*   **Gliders:** Typically have a very low sink rate (**0.5 to 1.0 m/s**).
*   **Draggy Planes:** (Like a Cub or a loaded cargo plane) may have a sink rate of **3.0 to 5.0 m/s**.
*   **Effect:** If this value is too high, the drone will undershoot its glide path during autonomous landings. If too low, it will overshoot (float).