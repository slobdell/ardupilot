---
layout: parameter
name: FS_DR_ENABLE
display_name: Dead Reckoning Failsafe Enable
description: Enables the ability for the drone to attempt a Return-to-Launch (RTL) using "Dead Reckoning" if GPS is lost.
default_value: 1
range: 0 1
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L100
---

# Dead Reckoning Failsafe Enable (FS_DR_ENABLE)

## Description
`FS_DR_ENABLE` allows the drone to try and come home even if its GPS "Goes Blind."

Normally, if GPS is lost, the drone can only land vertically. With Dead Reckoning (DR), the autopilot uses the compass, IMU, and air data to estimate its position and "Guess" its way back to the Home point. It isn't perfect, but it's often enough to get the drone back into transmitter range.

*   **0: Disabled.** The drone will Land instantly if GPS is lost during a mission.
*   **1: Enabled (Default).** The drone will try to fly toward Home for a short time using DR.

## Tuning & Behavior
*   **Requirement:** Requires a well-calibrated compass and a good wind estimation (from a pitot tube or EKF learning).