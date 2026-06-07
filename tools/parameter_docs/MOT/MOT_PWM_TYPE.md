---
layout: parameter
name: MOT_PWM_TYPE
display_name: Output PWM type
description: Selects the protocol used for ESC motor outputs.
default_value: 0
range: 0 13
units: 
group: MOT
visual_asset_id: mot_pwm_type_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_Motors_Class.cpp#L442
---

# Output PWM type (MOT_PWM_TYPE)

## Description
`MOT_PWM_TYPE` selects the communication protocol used to talk to the Electronic Speed Controllers (ESCs).

*   **0: Normal (PWM).** Legacy analog protocol (1000-2000µs). Compatible with everything but slow.
*   **4: DShot150.** Digital protocol. Robust, checksummed, no calibration needed.
*   **5: DShot300.** Faster digital protocol. Good balance.
*   **6: DShot600.** Fast digital protocol. Standard for modern racing/freestyle quads.
*   **7: DShot1200.** Ultra-fast. Requires high-quality wiring and compatible ESCs.

## The Mathematics
**PWM:** Analog pulse width modulation. Updates at ~400Hz.
**DShot:** Digital packet sending 16-bit commands (11-bit throttle + telemetry request + CRC).
*   **DShot600:** 600,000 bits/sec. Frame time $\approx 26.7 \mu s$.
*   **DShot300:** 300,000 bits/sec. Frame time $\approx 53.4 \mu s$.

## The Engineer's View
Sets `_pwm_type` in `AP_Motors`.
Changing this usually requires a **Reboot** to reconfigure the timer hardware on the STM32.
If using DShot, you must also ensure your `SERVO_BLH_MASK` (or equivalent output mask) is configured correctly, although modern ArduPilot usually handles DShot on main outputs automatically if this param is set.

## Tuning & Behavior
*   **Default Value:** 0 (PWM)
*   **Recommendation:**
    *   **DShot600 (6):** Use this for almost all modern BLHeli_S, BLHeli_32, or AM32 ESCs. It enables features like "Turtle Mode", ESC Telemetry (RPM filtering), and digital precision.
    *   **DShot300 (5):** Use if you have long signal wires or signal integrity issues with DShot600.
    *   **Normal (0):** Use only for legacy SimonK/Melody ESCs or servos.