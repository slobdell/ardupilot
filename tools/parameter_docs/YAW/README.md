# Yaw Controller Configuration (YAW)

## Overview
The **YAW** parameter group handles configuration for the **Heading (Yaw) Axis** across various vehicle types.

## Key Concepts

### 1. Heading Maintenance
Yaw is critical for ensuring the vehicle's nose is pointed correctly for navigation, sensors (cameras/Lidar), or aerodynamics.
*   **`YAW_BEHAVE`**: Defines how the nose behaves during mission flight (Face next WP, Face Home, etc.).

### 2. PID Tuning (`YAW_RATE_P/I/D`)
(If present in group) Standard gains to control the responsiveness of the yaw rotation.

## Developer Notes
*   **Library:** `libraries/AC_AttitudeControl`.
*   **See Also:** [ATC](../ATC/README.md) for more details on rate PID loops.