# External AHRS Configuration (EAHRS)

## Overview
The **EAHRS** parameter group configures the **External Attitude Heading Reference System** driver. This allows ArduPilot to utilize high-end, industrial-grade AHRS/INS units (like VectorNav, MicroStrain, or Inertial Labs) as the primary source of attitude and position data, bypassing the internal EKF.

## Key Concepts

### 1. External Fusion
Instead of the autopilot taking raw IMU/GPS data and running its own EKF, it trusts the "Solution" provided by the external box. The external unit does the heavy lifting of sensor fusion.

### 2. Sensor Selection (`EAHRS_SENSORS`)
You can choose which data streams to consume:
*   **Attitude:** Roll, Pitch, Yaw.
*   **Position:** Lat, Lon, Alt.
*   **Velocity:** NED velocity.
*   **Raw Data:** Accelerometers, Gyros (for logging).

## Parameter Breakdown

*   **`EAHRS_TYPE`**: Driver selection.
    *   0: Disabled.
    *   1: VectorNav (VN-100/200/300).
    *   2: MicroStrain (3DM-GX5).
    *   3: Inertial Labs.
*   **`EAHRS_RATE`**: Data update rate (Hz).
*   **`EAHRS_SENSORS`**: Bitmask of active data channels.

## Integration Guide
1.  **Hardware:** Connect the unit to a High-Speed Serial Port (Telem 1/2).
2.  **Serial:** Set `SERIALx_PROTOCOL = 36` (AHRS) and baud rate (usually 921600 or higher).
3.  **Enable:** Set `EAHRS_TYPE` to your device.
4.  **Reboot.**
5.  **Check:** Look for `AHRS_EXTERNAL` status in the GCS.

## Developer Notes
*   **Library:** `libraries/AP_ExternalAHRS`
*   **Latency:** Critical factor. The driver handles timestamp correction to align external data with the autopilot's clock.