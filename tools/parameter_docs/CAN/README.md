# CAN Bus Configuration (CAN)

## Overview
The **CAN** parameter group configures the **Controller Area Network (CAN)** interfaces on the autopilot. CAN is a robust, differential signaling bus used for connecting critical peripherals (GPS, Compass, ESCs, Servos) with high reliability and noise immunity.

ArduPilot supports multiple CAN drivers (`CAN_Dn_...`), each mapped to a physical port (`CAN_Px_...`).

## Key Concepts

### 1. Port vs. Driver
*   **Port (`CAN_Px_...`):** Configures the physical layer (Bitrate, Electrical).
    *   `CAN_P1_DRIVER`: Assigns a logical driver (1 or 2) to physical port 1.
    *   `CAN_P1_BITRATE`: Speed (typically 1000000 for 1Mbit).
*   **Driver (`CAN_Dx_...`):** Configures the protocol layer (DroneCAN, PiccoloCAN, KDE, etc.).
    *   `CAN_D1_PROTOCOL`: Selects the language spoken on this driver (1 = DroneCAN).

### 2. DroneCAN (formerly UAVCAN)
The most common protocol.
*   **`CAN_Dn_UC_NODE`**: The Node ID of the autopilot itself.
*   **`CAN_Dn_UC_ESC_BM`**: Bitmask to detect DroneCAN ESCs.

### 3. CAN FD (Flexible Data-Rate)
Newer H7 boards support CAN FD for higher speeds (up to 5Mbit).
*   **`CAN_P1_FDBITRATE`**: Data phase bitrate.
*   **`CAN_FDMODE`**: Enables FD frame format.

## Parameter Breakdown

### Physical Layer
*   **`CAN_P1_DRIVER`**: 0=Disabled, 1=First Driver, 2=Second Driver.
*   **`CAN_P1_BITRATE`**: 1000000 (1Mbit) is standard.

### Protocol Layer (Driver 1)
*   **`CAN_D1_PROTOCOL`**:
    *   1: DroneCAN
    *   4: PiccoloCAN
    *   7: KDECAN
    *   10: ToshibaCAN
*   **`CAN_D1_UC_OPTION`**: Options for DroneCAN (e.g., enable DNA server).

## Integration Guide

### Setting up a DroneCAN GPS (Here3)
1.  **Driver:** Set `CAN_P1_DRIVER = 1`.
2.  **Protocol:** Set `CAN_D1_PROTOCOL = 1` (DroneCAN).
3.  **GPS Type:** Set `GPS_TYPE = 9` (DroneCAN).
4.  **Compass:** Set `COMPASS_TYPEMASK` to allow DroneCAN (usually default).
5.  **Reboot:** The GPS should appear.

### Troubleshooting
*   **No Devices:** Check termination. A 120-ohm resistor is required at each end of the CAN bus.
*   **Node ID Conflicts:** Use the "DroneCAN/UAVCAN" inspector in Mission Planner to see active nodes.

## Developer Notes
*   **Library:** `libraries/AP_CANManager`
*   **Tunnels:** Support for tunneling Serial-over-CAN (`CAN_D1_UC_SER_EN`).