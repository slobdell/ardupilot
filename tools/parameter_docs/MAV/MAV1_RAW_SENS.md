---
layout: parameter
name: MAV1_RAW_SENS
display_name: Raw sensor stream rate (Telem 1)
description: Controls the MAVLink streaming rate for Raw IMU, Pressure, and Airspeed data.
default_value: 1
range: 0 50
units: Hz
group: MAV
visual_asset_id: mav_stream_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/GCS_Mavlink.cpp#L504
---

# Raw sensor stream rate (MAV1_RAW_SENS)

## Description
`MAV1_RAW_SENS` sets how many times per second the autopilot sends "Raw Sensor" data to the Ground Control Station (GCS) or Companion Computer.

This includes:
*   `RAW_IMU` (Accelerometers, Gyroscopes, Magnetometers)
*   `SCALED_PRESSURE` (Barometer)
*   `SCALED_PRESSURE2`
*   `SCALED_PRESSURE3`
*   `AIRSPEED`

## The Engineer's View
This controls the `SR1_RAW_SENS` stream group.
High rates are essential for off-board Visual Inertial Odometry (VIO) or FFT analysis, but consume significant telemetry bandwidth.

## Tuning & Behavior
*   **Default:** 1 Hz.
*   **Telemetry (SiK Radio):** Keep at **1-2 Hz** to save bandwidth.
*   **Companion Computer (VIO):** **50 Hz** (or higher if supported) is required for accurate state estimation.
*   **Log Replay:** If you are recording tlogs for replay, higher rates give smoother playback but huge file sizes.

