---
layout: parameter
name: SPRAY_SPINNER
display_name: Sprayer Spinner PWM
description: The PWM signal sent to the centrifugal spinner motor to control dispersal width.
default_value: 1500
range: 1000 2000
units: PWM
group: SPRAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AC_Sprayer/AC_Sprayer.cpp#L37
---

# Sprayer Spinner PWM (SPRAY_SPINNER)

## Description
`SPRAY_SPINNER` defines the speed of the centrifugal dispersal mechanism on your sprayer.

Instead of just a simple nozzle, many high-end agricultural drones use a spinning disk to fling the chemicals outward. A higher PWM value makes the disk spin faster, throwing the liquid in a wider swath.

*   **1000:** Stopped.
*   **2000:** Maximum dispersal width.

## Tuning & Behavior
*   **Calibration:** Set this based on the desired "Swath Width" for your mission. If you are flying 4m apart and the chemical is not reaching the edge, increase this value.