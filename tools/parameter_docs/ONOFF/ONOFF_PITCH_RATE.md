---
layout: parameter
name: ONOFF_PITCH_RATE
display_name: "Pitch rate for on/off servos"
description: "Rate of change of pitch for on/off servos"
default_value: 1.0f
range: 0 50
units: "deg/s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L121
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Pitch rate for on/off servos (ONOFF_PITCH_RATE)

## Description
This parameter is used by the Antenna Tracker when controlling **On/Off** (Bang-Bang) type mechanisms, such as simple relay-driven DC motors without position feedback loops. It defines the estimated angular velocity of the pitch axis. The controller uses this to calculate how long to run the motor to achieve a desired angle change.

## The Mathematics
$$ \Delta t = \frac{|\Delta \text{Angle}|}{\text{ONOFF\_PITCH\_RATE}} $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`.
*   **Constraint:** Requires the `SERVO_PITCH_TYPE` to be set to On/Off.
*   **Accuracy:** Since this is an open-loop estimation, variations in battery voltage or wind load can affect the actual rate, potentially causing overshoot or undershoot.

## Tuning & Behavior
*   **Default Value:** 1.0 deg/s
*   **Procedure:** Measure the time it takes for the tracker to pitch up by 90 degrees, then calculate the rate: $ \text{Rate} = 90 / \text{Time} $.