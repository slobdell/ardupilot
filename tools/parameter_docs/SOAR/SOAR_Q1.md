---
layout: parameter
name: SOAR_Q1
display_name: Soaring EKF Thermal Strength Noise
description: The process noise (uncertainty) for the estimated thermal lift strength.
default_value: 0.001
range: 0.0001 0.01
units: 
group: SOAR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Soaring/AP_Soaring.cpp#L33
---

# Soaring EKF Thermal Strength Noise (SOAR_Q1)

## Description
`SOAR_Q1` is a low-level tuning parameter for the soaring Kalman Filter. 

It defines how much the autopilot expects the strength of a thermal to change over time. A higher value tells the filter that thermals are turbulent and their strength can change rapidly. A lower value tells the filter that thermals are steady, resulting in a smoother but slower-reacting estimate of the climb rate.

## Tuning & Behavior
*   **Default:** 0.001.
*   **Recommendation:** Leave at **0.001**. Only adjust if you are a developer testing the soaring estimator's response to artificial lift profiles.