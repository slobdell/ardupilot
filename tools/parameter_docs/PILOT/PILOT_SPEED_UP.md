---
layout: parameter
name: PILOT_SPEED_UP
display_name: Pilot maximum vertical speed ascending
description: The maximum vertical velocity (in cm/s) the pilot can request while climbing in semi-autonomous modes.
default_value: 250
range: 50 500
units: cm/s
group: PILOT
visual_asset_id: pilot_speed_up_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L213
---

# Pilot maximum vertical speed ascending (PILOT_SPEED_UP)

## Description
`PILOT_SPEED_UP` determines how fast your drone climbs when you push the throttle stick all the way up in modes like **AltHold**, **Loiter**, and **PosHold**.

*   **250 (Default):** The drone will climb at 2.5 meters per second (m/s).

Unlike **Stabilize** mode (where the stick directly controls motor power), in autonomous modes, the stick controls the "Requested Vertical Velocity." This parameter acts as the speed limiter for that request.

## The Engineer's View
Defined in `ArduCopter/Parameters.cpp`.
The vertical velocity controller in `AC_PosControl` takes the pilot's normalized stick input ($S \in [-1, 1]$) and maps it to a target velocity $V_z$:
$$ V_{z\_target} = S_{throttle} \cdot \text{PILOT\_SPEED\_UP} $$

## Tuning & Behavior
*   **Default Value:** 250 cm/s
*   **Recommendation:** 
    *   **Cinematography:** Reduce to **150 or 200** for smoother, more cinematic ascents.
    *   **Sport / Inspection:** Increase to **400 or 500** for rapid altitude changes.
*   **Note:** If your drone is underpowered, setting this too high will cause it to lose stability during a climb as the motors hit their maximum output and can no longer maintain attitude (Tilt).