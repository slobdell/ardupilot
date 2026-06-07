# Hardpoint Configuration (HARDPOINT)

## Overview
The **HARDPOINT** parameter group (specifically within **AP_Periph**) configures the DroneCAN **Hardpoint** subsystem.

A "Hardpoint" is a designated mechanical output used for payload release, crop spraying, or robotic actuation that is commanded via the CAN bus rather than a dedicated PWM wire from the main autopilot.

## Key Concepts

### 1. Hardpoint ID (`HARDPOINT_ID`)
Assigns a unique identifier to the peripheral output. The main autopilot sends a MAVLink or DroneCAN command specifying "Activate Hardpoint 1," and only the device with `HARDPOINT_ID = 1` will actuate.

## Parameter Breakdown

*   **`HARDPOINT_ID`**: Identifier (0-15).
*   **`HARDPOINT_RATE`**: The frequency (Hz) at which the hardpoint status is reported back to the autopilot.

## Integration Guide
1.  **Node Setup:** On your `AP_Periph` node (e.g., a CAN-to-PWM converter), set `HARDPOINT_ID`.
2.  **Autopilot:** Use the `Do_Hardpoint` mission command or a GCS trigger to actuate the device.

## Developer Notes
*   **Library:** `Tools/AP_Periph`.
*   **Message:** Uses the `uavcan.equipment.hardpoint.Status` and `Command` messages.