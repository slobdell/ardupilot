---
layout: parameter
name: INS_GYRO_RATE
display_name: Gyro rate for IMUs with Fast Sampling enabled
description: Sets the raw sampling rate for gyroscopes that support fast sampling.
default_value: 0
range: 0 3
units: 
group: INS
visual_asset_id: ins_gyro_rate_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L330
---

# Gyro rate for IMUs with Fast Sampling enabled (INS_GYRO_RATE)

## Description
`INS_GYRO_RATE` sets the loop rate of the sensor backend. This is *not* the main flight control loop rate (which is usually 400Hz or 800Hz), but the rate at which the sensor driver reads data from the IMU chip.

*   **0: 1kHz (Default).** Standard rate. Good for older boards.
*   **1: 2kHz.** Required for good Harmonic Notch filtering on most quads.
*   **2: 4kHz.** Higher precision, lower latency. Requires a fast CPU (F7/H7).
*   **3: 8kHz.** Ultra-low latency. Only for high-performance H7 boards.

## The Mathematics
The sensor backend runs a loop:
1.  Read Gyro at `INS_GYRO_RATE`.
2.  Apply Hardware LPF (if configured on chip).
3.  Apply Harmonic Notch Filter.
4.  Apply `INS_GYRO_FILTER` (Software LPF).
5.  Downsample to Main Loop Rate (e.g., average 8 samples if running 8kHz sensor and 1kHz loop).

## The Engineer's View
Sets `_fast_sampling_rate` in `AP_InertialSensor`.
To use the Harmonic Notch Filter effectively, the sampling rate must be at least **2x** the highest frequency you want to filter (Nyquist Theorem).
If you want to filter noise at 400Hz (2nd harmonic of a 200Hz motor), you need at least 800Hz sampling. In practice, 2kHz is the recommended minimum for notch filtering to avoid aliasing.

## Tuning & Behavior
*   **Default Value:** 0 (1kHz)
*   **Recommendation:**
    *   **Set to 1 (2kHz)** or **2 (4kHz)** on modern boards (Cube Orange, Matek H743).
    *   This provides a dense stream of data for the filters to work with, resulting in a cleaner signal for the PID loop.
*   **Warning:** Higher rates consume more CPU. Check `LOAD` in MAVLink messages. If it exceeds 80%, lower this rate.