---
layout: parameter
name: MOT_THST_EXPO
display_name: Thrust Curve Expo
description: Motor thrust curve exponential factor.
default_value: 0.65
range: -1.0 1.0
units: 
group: MOT
visual_asset_id: mot_thst_expo_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_Motors_Class.cpp#L442
---

# Thrust Curve Expo (MOT_THST_EXPO)

## Description
`MOT_THST_EXPO` linearizes the relationship between the autopilot's requested thrust and the actual physical thrust produced by the motors.

Most brushless motors/propellers produce thrust roughly proportional to the **square** of RPM, and RPM is roughly proportional to throttle signal. This means 50% throttle signal might only produce 25% thrust. This nonlinearity confuses the PID controller (which assumes linear response). `MOT_THST_EXPO` corrects this.

## The Mathematics
The conversion from desired thrust ($T_{des} \in [0,1]$) to throttle signal ($Out \in [0,1]$) is:
$$ Out = \frac{(1 - k) T_{des}}{1 - k T_{des}} $$
where $k = \text{MOT\_THST\_EXPO}$.

If $k=0$, $Out = T_{des}$ (Linear).
If $k \approx 1$, the curve corrects for the square-law thrust.

## The Engineer's View
Used in `AP_MotorsMulticopter::output_to_motors()`.
Correct setting makes the PID gains effective across the entire throttle range.
*   If set too **low**: Drones will oscillate at high throttle (over-gained) and feel sluggish at low throttle.
*   If set too **high**: Drones will oscillate at low throttle and feel sluggish at high throttle.

## Tuning & Behavior
*   **Default Value:** 0.65
*   **Range:** -1.0 to 1.0 (Typical range for multicopters is 0.5 to 0.8).
*   **Recommendation:**
    *   **5" Racing Quad:** 0.55 - 0.65
    *   **10-15" Props:** 0.65 - 0.70
    *   **Large (18"+) Props:** 0.70 - 0.75
    *   **Flame/T-Motor ESCs:** These often have internal linearization. If so, set this to **0**. Check your ESC manual.