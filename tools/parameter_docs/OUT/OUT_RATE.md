---
layout: parameter
name: OUT_RATE
display_name: Output Rate
description: The default PWM output frequency (in Hz) for all servo channels.
default_value: 50
range: 25 400
units: Hz
group: OUT
visual_asset_id: pwm_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_HAL_ChibiOS/RCOutput.cpp#L100
---

# Output Rate (OUT_RATE)

## Description
`OUT_RATE` defines how many times per second the autopilot sends a new PWM signal to your servos.

*   **50Hz (Standard):** Standard for analog servos.
*   **400Hz (High-Speed):** Standard for digital servos.

Using a high rate with an analog servo can burn it out!

## The Engineer's View
Sets the global default timer period for the PWM peripheral. Note that if you use DShot or certain specific functions (like ESC telemetry), this global rate might be overridden for specific groups of pins sharing a timer.

## Tuning & Behavior
*   **Default Value:** 50 Hz.
*   **Digital Servos:** Set to **400** for significantly better flight performance and faster response times.
*   **Analog Servos:** Keep at **50**.