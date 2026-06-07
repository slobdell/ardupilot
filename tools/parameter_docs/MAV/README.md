# MAVLink Stream Configuration (MAV)

## Overview
The **MAV** parameter group configures the frequency and content of the **MAVLink Telemetry** streams.

MAVLink is the language ArduPilot uses to talk to Ground Stations, Companion Computers, and HUDs. Because telemetry links (like Sik Radios) often have limited bandwidth, the autopilot allows you to tune how often specific types of data are sent.

## Key Concepts

### 1. Stream Rates (`MAVn_...`)
You can configure the frequency (Hz) for different categories of messages:
*   **`EXTRA1`**: Attitude data (Roll, Pitch, Yaw).
*   **`EXTRA2`**: VFR HUD data (Speed, Altitude, Throttle).
*   **`EXTRA3`**: System status and AHRS data.
*   **`POSITION`**: GPS coordinates and velocity.
*   **`RAW_SENS`**: Raw accelerometer, gyro, and mag data.

### 2. System ID (`MAV_SYSID`)
Every vehicle on a network must have a unique ID.
*   **`MAV_SYSID`**: The ID of this vehicle (default 1).
*   **`MAV_COMPID`**: The component ID (default 1 for autopilot).

## Parameter Breakdown

*   **`MAV_SYSID`**: System identifier (1-255).
*   **`MAV1_POSITION`**: GPS stream rate (Hz).
*   **`MAV1_EXTRA1`**: Attitude stream rate (Hz).

## Integration Guide

### Optimizing Bandwidth
1.  **High Speed:** If using a USB cable or high-speed radio, you can set rates to 10Hz or 50Hz for smooth HUD movement.
2.  **Low Speed:** If using a long-range, low-baud radio, set position to 2Hz and raw sensors to 0Hz to avoid clogging the link.

## Developer Notes
*   **Library:** `libraries/GCS_MAVLink`.
*   **Mapping:** The rates are global, but can be requested dynamically by the GCS via the `REQUEST_DATA_STREAM` message.