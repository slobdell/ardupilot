# MSP Protocol Configuration (MSP)

## Overview
The **MSP** parameter group configures the **Multiwii Serial Protocol** (MSP) interface. While originally developed for the MultiWii firmware, MSP has become the standard communication protocol for modern digital FPV systems (DJI, Avatar, HDZero) to receive OSD telemetry from the autopilot.

## Key Concepts

### 1. Digital OSD Support
Digital VTX modules (like the DJI Air Unit) do not support the old analog "Overlay" method. Instead, they request data from the autopilot via MSP and render the OSD elements themselves within the goggles.

### 2. MSP DisplayPort
This is an extension of MSP used by HDZero and Avatar to provide high-definition, pixel-accurate OSD rendering that matches the look of Betaflight or ArduPilot's native OSD.

## Parameter Breakdown

*   **`MSP_OPTIONS`**: Bitmask for specific behaviors (e.g., enable DisplayPort mode).
*   **`MSP_OSD_NCELLS`**: Manual cell count for digital OSDs that can't auto-calculate.

## Integration Guide
1.  **Hardware:** Connect the TX/RX pins of your Digital VTX to a UART on the flight controller.
2.  **Serial:** Set `SERIALx_PROTOCOL = 33` (MSP).
3.  **Config:** If using DJI (original V1/V2), no further config is needed. If using Avatar/HDZero, set `MSP_OPTIONS` to enable DisplayPort.

## Developer Notes
*   **Library:** `libraries/AP_MSP`.