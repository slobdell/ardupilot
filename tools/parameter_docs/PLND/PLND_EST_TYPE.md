---
layout: parameter
name: PLND_EST_TYPE
display_name: Precision Land Estimator Type
description: Selects the math model used to track the target location.
default_value: 1
range: 0 1
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L61
---

# Precision Land Estimator Type (PLND_EST_TYPE)

## Description
`PLND_EST_TYPE` defines how the drone interprets the data from its landing sensor.

*   **0: RawSensor.** The drone flies directly toward where the sensor "sees" the target right now. (Simple, but can be twitchy).
*   **1: KalmanFilter (Default).** The drone uses a mathematical model to predict where the target is, filtering out sensor noise and accounting for the drone's own movement. (Smooth and much more reliable).

## The Engineer's View
Used in `AC_PrecLand::run_estimator()`. 
The **Kalman Filter (1)** mode uses the `_ekf_x` and `_ekf_y` internal state machines to track the target's relative velocity and position. This allows the drone to continue "knowing" where the target is for a few seconds even if the sensor momentarily loses sight of it (e.g., due to glare).

## Tuning & Behavior
*   **Default Value:** 1
*   **Recommendation:** Always use **1 (KalmanFilter)**. It provides much better performance and handles sensor dropouts more gracefully.