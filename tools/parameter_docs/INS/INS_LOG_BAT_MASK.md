---
layout: parameter
name: INS_LOG_BAT_MASK
display_name: Sensor Bitmask
description: Bitmask of sensors to enable for batch sampling logging.
default_value: 0
range: 0 511
units: 
group: INS
visual_asset_id: ins_log_bat_mask_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/BatchSampler.cpp#L19
---

# Sensor Bitmask (INS_LOG_BAT_MASK)

## Description
`INS_LOG_BAT_MASK` enables "Batch Sampling". This is a special high-rate logging mode used primarily for **FFT (Fast Fourier Transform) Analysis**.

When enabled, ArduPilot logs short bursts of high-frequency gyro data (e.g., at 1kHz or 2kHz) to the SD card. This data is critical for identifying motor noise frequencies so you can tune the Harmonic Notch Filters.

*   **0:** Disabled (Normal logging).
*   **1:** Log IMU 1 Gyro.
*   **3 (1+2):** Log IMU 1 & 2 Gyros (Recommended for tuning).

## The Mathematics
$$ \text{Active Samplers} = \sum_{k=0}^{n} (2^k \text{ is set}) \rightarrow \text{Sensor } k $$

*   **Bit 0 (1):** IMU 1 Gyro
*   **Bit 1 (2):** IMU 2 Gyro
*   **Bit 2 (4):** IMU 3 Gyro
*   **Bit 3 (8):** IMU 1 Accel
*   **Bit 4 (16):** IMU 2 Accel
*   ...

## The Engineer's View
Used in `AP_InertialSensor::BatchSampler::init()`.
Batch sampling creates massive log files. A 5-minute flight with `INS_LOG_BAT_MASK = 1` can produce a 100MB+ binary log. The data is stored in `ISBH` and `ISBD` messages.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Recommendation:**
    *   **For Tuning:** Set to **1** (or 3) for a single hover flight to capture noise data.
    *   **For Normal Flight:** Set to **0**. Leaving this on wastes SD card space and CPU cycles (though it runs at low priority).
*   **How to use:**
    1.  Set `INS_LOG_BAT_MASK = 1`.
    2.  Set `INS_LOG_BAT_OPT = 0` (Pre-filter) to see raw noise.
    3.  Fly/Hover.
    4.  Download log.
    5.  Use Mission Planner's "FFT" button to analyze the noise profile.