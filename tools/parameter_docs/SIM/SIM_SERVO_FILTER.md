---
layout: parameter
name: SIM_SERVO_FILTER
display_name: Simulation Servo Filter
description: Adds a low-pass filter (2-pole Butterworth) to the simulated servo outputs.
default_value: 0
range: 0 100
units: Hz
group: SIM
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/SITL/ServoModel.cpp#L44
---

# Simulation Servo Filter (SIM_SERVO_FILTER)

## Description
`SIM_SERVO_FILTER` adds damping to the simulated control surfaces.

Real servos and mechanical linkages don't snap to a new position instantly; they have physical inertia. This parameter simulates that "Smoothness" by applying a frequency-based filter to the output.

*   **0: Disabled.**
*   **Value (Hz):** The cutoff frequency. Lower values make the servos move slower and "mushier."

## Tuning & Behavior
*   **Default:** 0.
*   **Usage:** Set to **20** or **30** to simulate a typical high-quality servo.
*   **Integration:** Works in combination with [SIM_SERVO_SPEED](SIM_SERVO_SPEED.html).