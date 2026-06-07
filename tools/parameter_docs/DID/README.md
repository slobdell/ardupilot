# Remote ID / Drone ID (DID)

## Overview
The **DID** parameter group configures the **Remote ID** (OpenDroneID) subsystem. This is required for compliance with FAA (USA), EASA (Europe), and other CAA regulations regarding UAV identification.

Remote ID systems broadcast the drone's position, altitude, velocity, and serial number over Bluetooth/Wi-Fi to local receivers (like smartphones).

## Key Concepts

### 1. ODID Hardware
ArduPilot supports communicating with external Remote ID modules (like CubeID, Bluemark, Holybro) via MAVLink (`DID_MAVPORT`) or CAN (`DID_CANDRIVER`).

### 2. Data Source
The autopilot feeds the ODID module with live GPS and telemetry data. The module then handles the BLE/WiFi broadcasting.

## Parameter Breakdown

*   **`DID_ENABLE`**: Master switch.
*   **`DID_MAVPORT`**: Serial port connected to the ODID module (if using Serial).
*   **`DID_CANDRIVER`**: CAN driver connected to the ODID module (if using CAN).
*   **`DID_OPTIONS`**: Configuration flags.

## Integration Guide
1.  **Hardware:** Connect the Remote ID module to a Telemetry port or CAN bus.
2.  **Enable:** Set `DID_ENABLE = 1`.
3.  **Port:** If Serial, set `DID_MAVPORT` to the serial port index (e.g., 2 for Serial2). Ensure `SERIAL2_PROTOCOL` is set to MAVLink 2.
4.  **Verify:** Check GCS for "OpenDroneID" status messages.

## Developer Notes
*   **Library:** `libraries/AP_OpenDroneID`
*   **Protocol:** Uses the OpenDroneID MAVLink extension.