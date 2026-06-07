---
layout: parameter
name: SIM_PLD_RATE
display_name: Simulation Precision Landing Update Rate
description: Sets the update frequency (in Hz) for the virtual precision landing sensor.
default_value: 100
range: 0 200
units: Hz
group: SIM
visual_asset_id: plnd_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/SIM_Precland.cpp#L79
---

# Simulation Precision Landing Update Rate (SIM_PLD_RATE)

## Description
`SIM_PLD_RATE` controls how many times per second the virtual Precision Landing sensor (e.g., IR-Lock or MAVLink beacon) sends data to the autopilot in SITL.

A higher rate provides smoother tracking during the final descent, while a lower rate can be used to simulate the latency or jitter of real-world sensors.

## Tuning & Behavior
*   **Default:** 100 Hz.
*   **Realistic Testing:** If you are using a sensor known to be slow (e.g. some vision systems), try lowering this to **10 Hz** or **20 Hz** to see how the landing algorithm handles the increased lag.