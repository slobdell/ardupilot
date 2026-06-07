---
layout: parameter
name: INS_FAST_SAMPLE
display_name: Fast sampling mask
description: Mask of IMUs to enable fast sampling on.
default_value: 1
range: 0 7
units: 
group: INS
visual_asset_id: ins_fast_sample_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L320
---

# Fast sampling mask (INS_FAST_SAMPLE)

## Description
`INS_FAST_SAMPLE` is a bitmask that determines which IMUs are allowed to run at the higher `INS_GYRO_RATE` (e.g., 2kHz, 4kHz, 8kHz).

*   **Bit 0:** IMU 1
*   **Bit 1:** IMU 2
*   **Bit 2:** IMU 3

If a bit is set (1), that IMU attempts to run at `INS_GYRO_RATE`.
If a bit is clear (0), that IMU runs at the standard 1kHz (or default backend rate).

## The Mathematics
$$ \text{Sample Rate}_i = \begin{cases} \text{INS\_GYRO\_RATE} & \text{if bit } i \text{ is set} \\ 1\text{kHz} & \text{otherwise} \end{cases} $$

## The Engineer's View
Default behavior depends on the board (`HAL_DEFAULT_INS_FAST_SAMPLE`).
Typically, the primary IMU (Bit 0) is enabled for fast sampling to feed the low-latency control loop. Secondary IMUs might be left slow to save CPU or reduce noise aliasing.

## Tuning & Behavior
*   **Default Value:** 1 (IMU 1 Fast)
*   **Recommendation:**
    *   **1 (IMU 1 only):** Good for most setups.
    *   **3 (IMU 1 & 2):** If you want redundancy and EKF lane switching to have equal performance on both sensors.
    *   **7 (All):** Max performance, max CPU usage.
