---
layout: parameter
name: PILOT_ACCEL_Z
display_name: Pilot vertical acceleration
description: Controls how quickly the drone accelerates and decelerates vertically in response to throttle stick movement.
default_value: 250
range: 50 500
units: cm/s/s
group: PILOT
visual_asset_id: pilot_accel_z_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L218
---

# Pilot vertical acceleration (PILOT_ACCEL_Z)

## Description
`PILOT_ACCEL_Z` determines the "Snappiness" of the altitude control. It sets the limit for how fast the drone is allowed to change its vertical speed.

*   **Low Value (e.g., 100):** The drone will feel heavy and slow to respond. It will take several seconds to reach its full climb speed.
*   **High Value (e.g., 500):** The drone will feel very responsive and "locked-in," jumping immediately when you move the stick.

## The Mathematics
This parameter limits the derivative of the vertical velocity command $\dot{V}_z$:
$$ \left| \frac{dV_z}{dt} \right| \leq \text{PILOT\_ACCEL\_Z} $$

## Tuning & Behavior
*   **Default Value:** 250 cm/s/s
*   **Recommendation:**
    *   **Smooth Cinematic Flight:** Reduce to **100 or 150**.
    *   **Aggressive Acro/Racing:** Increase to **400 or 500**.
*   **Vibration:** If your drone has high vibration, setting this too high can cause "twitches" in altitude as the controller reacts too aggressively to sensor noise.