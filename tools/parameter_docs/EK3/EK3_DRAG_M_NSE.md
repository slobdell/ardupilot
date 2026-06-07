---
layout: parameter
name: EK3_DRAG_M_NSE
display_name: EKF3 Drag Observation Noise
description: Sets the expected noise (in m/s²) when using lean angle and aerodynamic drag to estimate wind speed. Enabling this allows the EKF to "calculate" the wind even without an anemometer.
default_value: 0.5
range: 0.1 2.0
units: m/s/s
group: EKF
visual_asset_id: ek3_drag_m_nse_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L687
---

# EKF3 Drag Observation Noise (EK3_DRAG_M_NSE)

## Description
`EK3_DRAG_M_NSE` is the key to ArduPilot's **Internal Wind Vane**.

When a multirotor flies forward (or hovers in a headwind), it must lean. The drone's "face" (frontal area) catches the wind, creating drag. The EKF3 can reverse-calculate the wind speed by looking at how far the drone has to lean to stay stationary. This is called **Drag Fusion**.

`EK3_DRAG_M_NSE` defines how much the EKF trusts its "Calculated Drag" vs. other sensors. 
*   **Low Value:** The EKF trusts its drag model implicitly. It will calculate wind speed very quickly and aggressively.
*   **High Value:** The EKF is cautious. It assumes the drag calculation is noisy (e.g., due to gusts or frame vibrations) and will take longer to update its wind estimate.

## The Mathematics
The EKF uses a simplified drag equation to predict the acceleration ($a_{drag}$) caused by the relative wind ($V_{rel}$):

$$ a_{drag} = \text{BCOEF} \cdot |V_{rel}|^2 + \text{MCOEF} \cdot V_{rel} $$

`EK3_DRAG_M_NSE` represents the standard deviation ($\sigma$) of this observation. In the filter, it is squared to form the measurement covariance $R$:

$$ R_{drag} = (\text{EK3\_DRAG\_M\_NSE})^2 $$

By minimizing the error between this predicted drag and the actual IMU-measured acceleration, the EKF can "solve" for the unknown wind vector.

## The Engineer's View
This parameter is the `_dragObsNoise` member in `NavEKF3`.

It is inactive unless you have provided your drone's specific drag coefficients (`EK3_DRAG_BCOEF_X/Y`). Once enabled, the EKF3 core fuses the drag data every 100ms. This provides a "synthetic airspeed" estimate, which is incredibly useful for:
1.  Maintaining ground speed during mapping.
2.  Switching to "Dead Reckoning" more accurately if GPS is lost.

```cpp
// AP_NavEKF3_Control.cpp
// Wind estimation logic incorporates _dragObsNoise to weight the accelerometer-derived drag observations.
```

## Tuning & Behavior
*   **Default Value:** 0.5 m/s²
*   **Range:** 0.1 - 2.0 m/s²
*   **Effect of Increasing:** Smoother, slower wind estimates. Less susceptible to vibration noise.
*   **Effect of Decreasing:** Rapid, real-time wind tracking. Better for drones operating in highly gusty environments.

### Use Case Recommendations
*   **Professional Mapping Drone:** **Keep at 0.5.** Provides a reliable average wind speed for georeferencing.
*   **Precision Spraying / Ag-Drones:** **Decrease to 0.3.** These drones must react instantly to wind shifts to prevent chemical drift; a faster wind estimate improves the ground-track accuracy.
*   **Racing / High Vibration frames:** **Increase to 1.0.** High vibrations can "confuse" the drag model; a higher noise value prevents the EKF from making erratic wind corrections.

### Troubleshooting
*   **Scenario:** GCS reports wildly varying wind speeds (e.g. jumping from 5 to 20 knots) while hovering in a steady breeze.
    *   **Diagnosis:** `EK3_DRAG_M_NSE` is too low, or your `BCOEF` parameters are incorrect.
    *   **Fix:** Increase `EK3_DRAG_M_NSE` to 0.8.