---
layout: parameter
name: SPRAY_PUMP_RATE
display_name: Pump speed
description: Desired pump speed when travelling 1m/s expressed as a percentage.
default_value: 10
range: 0 100
units: %
group: SPRAY
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Sprayer/AC_Sprayer.cpp#L29
---

# SPRAY_PUMP_RATE: Pump speed

## Description
Desired pump speed when travelling 1m/s expressed as a percentage.

## Values
- **Range:** 0 to 100
- **Units:** %
- **Default:** 10

## Description
This parameter defines the "Volume" of the spray. 

- **Function:** It sets the baseline pump speed (PWM output) required to deliver the desired amount of liquid per square meter when the drone is flying at exactly 1 meter per second.
- **Scaling:** If the drone flies faster (e.g., 2m/s), the autopilot will automatically double the pump speed to maintain the same application rate. If it slows down, the pump slows down.
- **Tuning:** You must calibrate this based on your nozzle size and pump flow rate. If you find the drone is under-applying, increase this value.

