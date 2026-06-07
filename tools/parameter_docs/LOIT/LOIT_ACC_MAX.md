---
layout: parameter
name: LOIT_ACC_MAX
display_name: Loiter Horizontal Maximum Acceleration
description: Defines the maximum horizontal acceleration (in cm/s²) the drone is allowed to use in Loiter mode when reacting to the pilot's stick inputs.
default_value: 500
range: 50 1000
units: cm/s/s
group: LOIT
visual_asset_id: loit_acc_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_Loiter.cpp#L46
---

# Loiter Horizontal Maximum Acceleration (LOIT_ACC_MAX)

## Description
`LOIT_ACC_MAX` is the "throttle response" setting for your drone's horizontal movement in Loiter mode. It determines how fast the drone can transition from a hover to full speed (`LOIT_SPEED`) when you slam the stick forward.

*   **Low Value (e.g. 100):** The drone accelerates very slowly and "lazily." It feels like a massive ship. Ideal for smooth cinematic pans.
*   **High Value (e.g. 800):** The drone accelerates instantly and aggressively. It feels like a high-performance sports car.
*   **Default (500):** 5.0 m/s² (roughly 0.5G). A standard setting that feels snappy but controllable for most pilots.

## The Mathematics
This parameter provides the acceleration limit ($a_{max}$) for the pilot-driven path shaper:

$$ \vec{V}_{target}(t) = \vec{V}_{target}(t-dt) + \text{constrain}(\vec{a}_{calc}, -a_{max}, a_{max}) \cdot dt $$

Where:
*   $a_{max}$ is `LOIT_ACC_MAX`.

**Physical Consequence:** If `LOIT_ACC_MAX` is set to 500, and your drone has a Hover Throttle of 50%, it will have to tilt by about 27 degrees ($ \tan^{-1}(500/980) $) to achieve this acceleration. If your `ANGLE_MAX` is lower than this, you will never reach full acceleration.

## The Engineer's View
This parameter is the `_accel_cmss` member in `AC_Loiter`.

Unlike **Auto** mode (which uses `WPNAV_ACCEL`), **Loiter** mode uses this parameter to calculate the "Inertia" felt by the pilot. A critical feature of this controller is that **Acceleration is prioritized over Speed**. If the drone is hit by a gust, it will use the full `LOIT_ACC_MAX` authority to hold its position before it even considers the pilot's speed request.

## Tuning & Behavior
*   **Default Value:** 500 cm/s² (5.0 m/s²)
*   **Range:** 50 - 1000 cm/s²
*   **Effect of Increasing:** Snappier, more "connected" feel to the sticks. Better performance for manual object tracking.
*   **Effect of Decreasing:** Smoother, "floaty" feel. Greatly reduces the chance of accidental jerky movements appearing on camera.

### Use Case Recommendations
*   **Aerial Cinematography:** **Decrease to 200 - 300.** Makes every start and stop look smooth and professionally damped.
*   **Precision Industrial Work:** **Keep at 500.** You want the drone to move exactly when you tell it to, with no lazy ramp-up.
*   **Racing / Freestyle:** **Increase to 800 - 1000.** Provides the instant authority needed to change directions at the edge of the flight envelope.

### Troubleshooting
*   **Scenario:** Drone feels "nervous" or "jittery" in Loiter, even though P-gains are low.
    *   **Diagnosis:** `LOIT_ACC_MAX` is too high, causing the drone to over-react to tiny finger twitches.
    *   **Fix:** Reduce `LOIT_ACC_MAX` to 250.