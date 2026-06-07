---
layout: parameter
name: INS_GYRO_FILTER
display_name: Gyroscope Low Pass Filter
description: The cutoff frequency (in Hz) for the gyroscope low-pass filter.
default_value: 20
range: 0 250
units: Hz
group: INS
visual_asset_id: filter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L100
---

# Gyroscope Low Pass Filter (INS_GYRO_FILTER)

## Description
`INS_GYRO_FILTER` sets the "Smoothness" of the raw gyroscope data. 

All sensors produce high-frequency electrical and mechanical noise (vibration). This low-pass filter removes that noise before the autopilot uses the data for attitude control.

*   **Higher Frequency (e.g., 40Hz):** Less delay (lower latency), but more noise gets through. Best for small, clean racing quads.
*   **Lower Frequency (e.g., 10Hz):** Very smooth data, but adds delay. Best for large, vibey industrial drones.

## The Mathematics
This is a standard 2nd-order software Butterworth filter. The signal $y$ is calculated from the input $x$ using the cutoff frequency $f_c$:

$$ y_n = \text{Butterworth}(x_n, f_c) $$

Lowering $f_c$ increases the group delay (latency) of the signal, which can destabilize the PID controller if set too low.

## The Engineer's View
Defined in `AP_InertialSensor.cpp`.
The filtered gyro data is the primary input to the Rate PID loop. Delay here is "bad" for performance but necessary for stability.

## Tuning & Behavior
*   **Default Value:** 20 Hz.
*   **Small Quads (5-7 inch):** Try **30Hz to 60Hz**.
*   **Large Quads (15 inch+):** Try **10Hz to 20Hz**.
*   **Harmonic Notch:** If you have persistent motor noise, do not lower this filter excessively; use the `INS_HNTCH` (Harmonic Notch) system instead.
