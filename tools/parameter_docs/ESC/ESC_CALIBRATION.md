---
layout: parameter
name: ESC_CALIBRATION
display_name: ESC Calibration Trigger
description: Triggers the ESC calibration process upon the next reboot.
default_value: 0
range: 0 9
units: 
group: ESC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L319
---

# ESC Calibration Trigger (ESC_CALIBRATION)

## Description
`ESC_CALIBRATION` is used to match the autopilot's output signals to the input range of your **Electronic Speed Controllers (ESCs)**.

If your motors don't all start at the same time, or if they don't reach full power, you may need to calibrate them. Setting this parameter to **3 (Automatic)** and rebooting will put the drone into calibration mode, where it passes your transmitter's throttle stick directly to the motors (with safety limits).

## Common Values
*   **0: Normal.** No calibration.
*   **3: Automatic.** Triggers calibration on next boot.
*   **9: Disabled.** Prevents accidental calibration.

## Tuning & Behavior
*   **Safety:** **REMOVE PROPELLERS** before performing any ESC calibration.
*   **Note:** Digital protocols like **DShot** do not require (and cannot use) this calibration process. This is only for PWM/OneShot ESCs.