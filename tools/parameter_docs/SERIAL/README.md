# Serial Port Configuration (SERIAL)

## Overview
The **SERIAL** parameter group configures the physical **UART (Universal Asynchronous Receiver-Transmitter)** ports on the flight controller.

Effective serial configuration is the backbone of drone integration, allowing the autopilot to talk to GPS units, Telemetry Radios, Companion Computers, ESCs, and OSDs.

## Key Concepts

### 1. Serial Port Indexing
*   **`SERIAL0`**: Usually the USB port.
*   **`SERIAL1`**: Usually Telemetry 1.
*   **`SERIAL3`**: Usually GPS 1.
*(Note: Mapping varies by board. Check your board's Wiki page).*

### 2. Protocol Selection (`SERIALx_PROTOCOL`)
Tells the autopilot what "Language" to speak on each port.
*   **1:** MAVLink 1.
*   **2:** MAVLink 2 (Recommended for telemetry).
*   **5:** GPS (NMEA/u-Blox).
*   **10:** FrSky Passthrough.
*   **16:** ESC Telemetry.
*   **33:** MSP (Digital OSD).

### 3. Baud Rate (`SERIALx_BAUD`)
The communication speed. Both the autopilot and the connected device must match.
*   **57:** 57,600 (Standard for SiK Radios).
*   **115:** 115,200 (Standard for GPS/OSD).
*   **921:** 921,600 (Recommended for Companion Computers/ROS).

### 4. Options (`SERIALx_OPTIONS`)
A bitmask for advanced UART features.
*   **Bit 0:** Invert TX.
*   **Bit 1:** Invert RX.
*   **Bit 2:** Swap TX/RX pins (handy if you cross your wires!).
*   **Bit 3:** Single-wire mode.

## Parameter Breakdown

*   **`SERIALx_PROTOCOL`**: Function of the port.
*   **`SERIALx_BAUD`**: Speed of the port.
*   **`SERIAL_PASS1 / 2`**: Used for "Serial Passthrough," allowing you to update GPS or ESC firmware through the autopilot.

## Integration Guide
1.  **Requirement:** Check your device manual for its default baud rate.
2.  **Config:** Set the protocol and baud rate.
3.  **Reboot:** **Critical.** Serial settings almost always require a full reboot to initialize the new drivers.

## Developer Notes
*   **Library:** `libraries/AP_SerialManager`.
*   **DMA:** High-speed ports (921k+) often utilize DMA (Direct Memory Access) to reduce CPU load.