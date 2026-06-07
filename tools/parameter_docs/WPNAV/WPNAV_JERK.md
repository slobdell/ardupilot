---
layout: parameter
name: WPNAV_JERK
display_name: Waypoint Jerk Limit
description: Defines the rate of change of acceleration during autonomous missions. Controls how "smoothly" the drone ramps up its lean angle when starting or stopping a move.
default_value: 1.0
range: 1 20
units: m/s/s/s
group: WPNAV
visual_asset_id: wpnav_jerk_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L85
---

# Waypoint Jerk Limit (WPNAV_JERK)

## Description
`WPNAV_JERK` is the "refinement" setting for mission flight. While `WPNAV_ACCEL` tells the drone how hard to accelerate, `WPNAV_JERK` tells it how **smoothly** to apply that acceleration.

In physics, **Jerk** is the rate at which acceleration changes. High jerk means the drone snaps into a lean instantly; low jerk means it rolls into the lean gracefully. By setting this limit, ArduPilot ensures that autonomous missions (Auto, RTL) look professional and don't place unnecessary mechanical stress on the frame.

*   **Low Value (e.g. 1.0):** Flight is extremely fluid. The drone takes a noticeable moment to "roll into" its forward flight. Best for high-end cinematography.
*   **High Value (e.g. 10.0):** The drone snaps into its acceleration ramps instantly. Flight looks more robotic and "aggressive."
*   **Default (1.0):** Optimized for standard, smooth multirotor flight.

## The Mathematics
Jerk ($j$) is the third derivative of position ($p$):

$$ j(t) = \frac{da}{dt} = \frac{d^3p}{dt^3} $$

In the ArduPilot shaper, this parameter limits the curvature of the velocity graph. A mission segment's acceleration ($a$) must satisfy:

$$ |\Delta a| \leq \text{WPNAV\_JERK} \cdot dt $$

This creates the characteristic **S-Curve velocity profile**, where the transition from hover to cruising speed is rounded off at both the beginning and the end.

## The Engineer's View
This parameter is the `_wp_jerk` member in `AC_WPNav`.

It defines the "snappiness" of the **SCurve path shaper**. One interesting technical detail is that `WPNAV_JERK` is expressed in **m/s³**, whereas `WPNAV_ACCEL` is in **cm/s²**.

*   A value of 1.0 m/s³ means the drone can increase its acceleration by 100 cm/s² every second.
*   With the default `WPNAV_ACCEL` of 100, it would take exactly 1.0 second to reach full acceleration.

## Tuning & Behavior
*   **Default Value:** 1.0 m/s³
*   **Range:** 1.0 - 20.0 m/s³
*   **Effect of Increasing:** The drone reacts faster to the mission path. Corners are tighter (less drift).
*   **Effect of Decreasing:** Maximum smoothness. Essential for capturing professional aerial video without any "horizon jitter."

### Use Case Recommendations
*   **Cinematography:** **Keep at 1.0.** This is the professional standard.
*   **High-Speed Grid Mapping:** **Increase to 2.0 - 5.0.** When flying a tight survey grid at 15 m/s, a higher jerk value is needed to ensure the drone can stop and turn fast enough at the end of each line.
*   **Small Rigid Racers (Auto-Mission):** **Set to 10.0.** Smaller frames have very little inertia and can handle high jerk rates with ease.

### Troubleshooting
*   **Scenario:** Drone "bobs" or twitches when starting or ending a mission leg.
    *   **Diagnosis:** `WPNAV_JERK` is too high, exciting a frame resonance.
    *   **Fix:** Reduce to 1.0 or 0.5.