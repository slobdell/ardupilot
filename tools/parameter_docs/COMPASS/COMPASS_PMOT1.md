---
layout: parameter
name: COMPASS_PMOT1
display_name: Compass Per-Motor Compensation (Motor 1)
description: Mathematical compensation factor to cancel out magnetic interference from Motor 1.
default_value: 0
range: -10.0 10.0
units: 
group: COMPASS
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Compass/Compass_PerMotor.cpp#L41
---

# Compass Per-Motor Compensation (COMPASS_PMOT1)

## Description
`COMPASS_PMOT1` is an advanced calibration setting used to cancel out magnetic interference caused by high-current wires and motors.

In some small or tightly packed drones, the battery wires or motors are so close to the compass that they "pull" the needle whenever the throttle is applied. This causes the drone's heading to drift during a punch-out. This parameter stores the learned compensation factor for the first motor in the system.

## Tuning & Behavior
*   **Default:** 0.
*   **Calibration:** This value is calculated automatically by running the **Compass Motor Calibration** (MagCali) routine in your Ground Control Station while safely tethering the drone and varying the throttle.
*   **Recommendation:** Do not edit this manually. Use the GCS calibration tool to find the correct values for your specific frame.