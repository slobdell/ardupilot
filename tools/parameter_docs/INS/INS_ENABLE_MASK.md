---
layout: parameter
name: INS_ENABLE_MASK
display_name: IMU enable mask
description: Bitmask of IMUs to enable at boot.
default_value: 127
range: 0 127
units: 
group: INS
visual_asset_id: ins_enable_mask_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_InertialSensor/AP_InertialSensor.cpp#L329
---

# IMU enable mask (INS_ENABLE_MASK)

## Description
`INS_ENABLE_MASK` allows precise control over which Inertial Measurement Units (IMUs) are detected and initialized by the autopilot at boot.

ArduPilot can support multiple IMUs (typically 3 on high-end boards like the Cube Orange). If a specific IMU sensor hardware is faulty (e.g., "IMU 2 Calibration Failed" persistent error) or is known to be noisy/defective on a particular board revision, you can use this mask to completely hide it from the flight controller.

## The Mathematics
$$ \text{Enabled IMUs} = \sum_{k=0}^{6} (2^k \text{ is set}) \rightarrow \text{IMU } k+1 $$

*   **Bit 0 (1):** IMU 1
*   **Bit 1 (2):** IMU 2
*   **Bit 2 (4):** IMU 3
*   **...**

Default is **127 (0x7F)**, which enables the first 7 possible IMUs (usually only 2 or 3 exist).

## The Engineer's View
Used in `AP_InertialSensor::detect_backends()`.
The driver check `ADD_BACKEND` verifies `(1U << probe_count) & enable_mask`. If the bit is 0, the driver probe is skipped entirely. This is cleaner than `INS_USE_x = 0` because it saves RAM and CPU by not even allocating the backend driver structures.

## Tuning & Behavior
*   **Default Value:** 127 (All Enabled)
*   **Use Case:**
    *   **Faulty Sensor:** If the GCS says "Bad Gyro Health" for IMU 3 and recalibration doesn't fix it, set `INS_ENABLE_MASK` to **3** (1 + 2) to disable IMU 3 permanently.
    *   **Cube Isolated IMU:** On the Cube Black/Orange, the isolated IMU (IMU 3) is sometimes disabled for specific industrial applications where the vibration mount causes issues.