# Fast Sampling Configuration (FAST)

## Overview
The **FAST** parameter group (specifically `FAST_SAMPLE`) controls high-rate hardware oversampling for **IMU Sensors**.

## Key Concepts

### 1. IMU Fast Sampling
Modern IMU chips (InvenSense, Bosch) can sample data at multi-kHz rates internally. By enabling fast sampling, the autopilot's CPU pulls data as fast as the SPI bus allows (e.g., 8kHz or 16kHz) and performs a low-pass filter in software before down-sampling to the main loop rate (e.g., 400Hz).
*   **Benefit:** Dramatically improves noise rejection and reduces "aliasing" (where high-frequency vibration looks like low-frequency control problems).

## Parameter Breakdown

*   **`FAST_SAMPLE`**: Bitmask to enable fast sampling for specific IMUs.
    *   **Bit 0:** IMU 1.
    *   **Bit 1:** IMU 2.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`
*   **Hardware:** Requires high-performance processors (F7, H7) and sensors capable of high-speed SPI (ICM-20602, ICM-42688).
*   **Alias:** `INS_FAST_SAMPLE`.