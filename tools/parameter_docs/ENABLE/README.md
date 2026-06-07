# IMU Enable Configuration (ENABLE)

## Overview
The **ENABLE** parameter group (specifically `ENABLE_MASK`) configures which physical **Inertial Measurement Units (IMUs)** are initialized and used by the autopilot.

In modern flight controllers with multiple redundant sensors (e.g., The Cube Orange with 3 IMUs), this mask allows the user to disable a specific sensor if it is found to be defective or performing poorly without needing to recompile the firmware.

## Key Concepts

### 1. IMU Enable Mask
The autopilot attempts to detect all sensors on the internal SPI/I2C buses.
*   **`ENABLE_MASK`**: A bitmask where each bit corresponds to an IMU index.
    *   **Bit 0:** IMU 1 (Internal)
    *   **Bit 1:** IMU 2 (Internal)
    *   **Bit 2:** IMU 3 (Internal)
    *   **Value 7 (1+2+4):** Enables all three standard IMUs.

## Integration Guide
*   **Troubleshooting:** If you see "Inconsistent Accelerometers" or "IMU Fail" and logs show one specific IMU has huge spikes or offsets, you can temporarily disable it using this mask to maintain flight capability on the remaining healthy sensors.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`
*   **Relationship:** This parameter is often aliased as `INS_ENABLE_MASK` in the full parameter list.