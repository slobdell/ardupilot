---
layout: parameter
name: EK3_DRAG_BCOEF_Y
display_name: EKF3 Lateral Drag Coefficient
description: Defines the aerodynamic drag characteristics of the drone's side profile. Enables lateral wind estimation.
default_value: 0.0
range: 0.0 1000.0
units: kg/m²
group: EKF
visual_asset_id: ek3_drag_bcoef_y_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L678
---

# EKF3 Lateral Drag Coefficient (EK3_DRAG_BCOEF_Y)

## Description
`EK3_DRAG_BCOEF_Y` is the "Side-Wind Profile" for your drone. It tells the flight controller how much the wind pushes on the *side* of the drone when it is flying sideways or in a crosswind.

Most drones have a different profile from the side than they do from the front. For example, a drone with a wide battery or long arms will catch more wind from the side. `EK3_DRAG_BCOEF_Y` allows the EKF3 to accurately calculate the lateral (sideways) component of the wind vector.

*   **Set to 0 (Default):** Sideways wind estimation is disabled.
*   **Set > 1.0:** Enables lateral wind estimation.

## The Mathematics
The EKF uses the quadratic drag model for the lateral axis ($y$):

$$ a_{y} = \frac{1}{\text{BCOEF\_Y}} \cdot V_{rel\_y} \cdot |V_{rel\_y}| $$

Where:
*   $V_{rel\_y} = V_{ground\_y} - V_{wind\_y}$.
*   $\text{BCOEF\_Y}$ is the value of `EK3_DRAG_BCOEF_Y`.

**Note on Symmetry:** On a perfectly square quadcopter, `BCOEF_Y` should be identical to `BCOEF_X`. On rectangular drones (longitudinal frames), `BCOEF_Y` is usually **lower** than `BCOEF_X` because the side of the drone has more surface area (more drag).

## The Engineer's View
This parameter is the `_ballisticCoef_y` member in `NavEKF3`.

To calculate it manually:
1.  Fly the drone sideways at a steady 5-10 m/s on a calm day.
2.  Record the average roll angle ($\phi$).
3.  Calculate lateral acceleration from tilt: $a_{tilt} = g \cdot \tan(\phi)$.
4.  $\text{BCOEF\_Y} = \frac{V^2}{a_{tilt}}$.

## Tuning & Behavior
*   **Default Value:** 0.0 (Disabled)
*   **Range:** 0.0 - 1000.0 kg/m²
*   **Effect of Increasing:** The EKF assumes the side of the drone is "slippery." It will calculate a higher side-wind speed for a given roll angle.
*   **Effect of Decreasing:** The EKF assumes the side of the drone is "blunt." It will calculate a lower side-wind speed for a given roll angle.

### Use Case Recommendations
*   **Dead-Cat / Long-Range Frames:** **Set to 75% of `BCOEF_X`.** These frames have very long side profiles and catch significant crosswinds.
*   **Standard Quad:** **Set to match `BCOEF_X`.**
*   **Drones with Large Side Panels (Advertising/Industrial):** **Decrease to 10.0.** Large surface areas create massive lateral drag.

### Troubleshooting
*   **Scenario:** During a crosswind, the drone's position drifts sideways, and the GCS doesn't show any lateral wind.
    *   **Diagnosis:** `EK3_DRAG_BCOEF_Y` is set to 0.
    *   **Fix:** Set `EK3_DRAG_BCOEF_Y` to match your `BCOEF_X` value.