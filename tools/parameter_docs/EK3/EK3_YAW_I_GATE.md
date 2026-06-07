---
layout: parameter
name: EK3_YAW_I_GATE
display_name: EKF3 Yaw Innovation Gate
description: The number of standard deviations allowed before a compass (yaw) measurement is rejected.
default_value: 300
range: 100 1000
units: '%'
group: EK3
visual_asset_id: ek3_gate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L100
---

# EKF3 Yaw Innovation Gate (EK3_YAW_I_GATE)

## Description
`EK3_YAW_I_GATE` prevents the drone from following a "bad" compass.

If you fly near a large metal structure (like a bridge or power pylon), the magnetic field will twist. The compass will report a heading that is wildly different from what the Gyroscope expects. This gate detects that "Innovation" (disagreement) and rejects the compass data, forcing the drone to rely on Gyro Dead-Reckoning until it flies past the interference.

*   **Low Value (100):** Very strict. Reject compass at the slightest hint of trouble. Good for flying near steel.
*   **High Value (500):** Relaxed. Trust the compass even if it jumps.

## The Mathematics
The Normalized Innovation Squared (NIS) for yaw is compared against the gate:
$$ \text{Yaw Error}^2 / \text{Variance} < (\text{GATE}/100)^2 $$

## The Engineer's View
This is the primary defense against "Toilet Bowling" caused by magnetic interference. If the gate rejects the compass for too long (> 10 seconds), the EKF will declare a "Compass Variance" failsafe and may switch to GSF (GPS Yaw) if available.

## Tuning & Behavior
*   **Default Value:** 300 (3-Sigma).
*   **Recommendation:** Keep at **300**.
*   **High Interference:** If you must fly indoors near metal beams, reducing this to **100** can help the drone ignore the magnetic distortions and fly purely on Gyro (drift) for short periods.
