---
layout: parameter
name: WPNAV_ACCEL
display_name: Waypoint Horizontal Acceleration
description: Defines the maximum horizontal acceleration (in cm/s²) the drone is allowed to use during autonomous missions (Auto, RTL, Guided).
default_value: 100
range: 50 500
units: cm/s/s
group: WPNAV
visual_asset_id: wpnav_accel_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L61
---

# Waypoint Horizontal Acceleration (WPNAV_ACCEL)

## Description
`WPNAV_ACCEL` is the "Gas Pedal" limit for your drone's autonomous brain. It determines how hard the drone should lean forward to reach its cruising speed (`WPNAV_SPEED`) and how hard it should lean back to stop at a waypoint.

*   **Low Value (e.g. 50):** The drone accelerates and brakes very gently. Flight feels very smooth and "lazy." Ideal for cinematography.
*   **High Value (e.g. 200):** The drone snaps to its target speed instantly. Flight feels very robotic and aggressive.
*   **Default (100):** 1.0 m/s². A standard, safe value that is comfortable for most payloads.

**Physical Context:** 100 cm/s² is roughly **0.1G**. Setting this to 500 would be 0.5G, which requires a steep lean angle and high battery current.

## The Mathematics
This parameter defines the acceleration limit ($a_{max}$) for the 2D path shaper. When starting a mission segment:

$$ V(t) = V_{initial} + \text{constrain}(a_{calc}, -a_{max}, a_{max}) \cdot dt $$

Where:
*   $a_{max}$ is `WPNAV_ACCEL`.

The **Total 2D Acceleration** is limited, meaning the combination of North and East acceleration will never exceed this value, resulting in smooth, circular turn profiles rather than "square" corners.

## The Engineer's View
This parameter is the `_wp_accel_cmss` member in `AC_WPNav`.

It is a core input to the **S-Curve Kinematic path generator**. One subtle detail is that **WPNAV_ACCEL also determines the Braking Distance**.

$$ \text{Stop\_Dist} = \frac{V^2}{2 \cdot a_{max}} $$

If you set `WPNAV_SPEED` very high but `WPNAV_ACCEL` very low, the drone will have to start braking 50 meters before the waypoint, which can make the mission feel very slow.

## Tuning & Behavior
*   **Default Value:** 100 cm/s² (1.0 m/s²)
*   **Range:** 50 - 500 cm/s²
*   **Effect of Increasing:** Faster stop-and-go maneuvers. Drone reaches waypoint speed sooner. Better for high-wind handling in missions.
*   **Effect of Decreasing:** Smoother cinematic motion. Less "jerking" of the gimbal. Safer for unstable payloads.

### Use Case Recommendations
*   **Cinematography:** **Decrease to 50.** Provides extremely smooth transitions between waypoints.
*   **Rapid Delivery / Rescue:** **Increase to 150 - 200.** Every second counts; you want the drone at its cruise speed as fast as possible.
*   **Mapping:** **Keep Default.** Standard values are sufficient for consistent overlap.

### Troubleshooting
*   **Scenario:** Drone "lunges" forward violently at the start of a mission segment.
    *   **Diagnosis:** `WPNAV_ACCEL` is too high for the vehicle's power-to-weight ratio.
    *   **Fix:** Reduce to 80.
*   **Scenario:** Drone consistently overshoots the waypoint during a mission.
    *   **Diagnosis:** `WPNAV_ACCEL` is too low, and the drone doesn't have enough "braking power" to stop from its current speed.
    *   **Fix:** Increase `WPNAV_ACCEL` or reduce `WPNAV_SPEED`.