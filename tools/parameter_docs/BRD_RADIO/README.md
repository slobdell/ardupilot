# Integrated Radio Configuration (BRD_RADIO)

## Overview
The **BRD_RADIO** parameter group configures the **Internal Radio** found on certain flight controllers (e.g., SkyViper or boards with integrated SiK/ExpressLRS hardware).

Unlike external radios connected via UART, these are directly managed by the board's HAL (Hardware Abstraction Layer).

## Key Concepts

### 1. Transmit Power (`BRD_RADIO_TXPOW`)
Sets the output power of the integrated radio module.
*   **Safety:** Ensure compliance with local RF regulations (e.g., 20dBm / 100mW).

### 2. Stick Mode (`BRD_RADIO_STKMD`)
Defines the mapping of the transmitter sticks (Mode 1, Mode 2, etc.) for integrated controllers.

## Developer Notes
*   **Library:** `libraries/AP_Radio`.
*   **Context:** Primarily used for RTF (Ready-To-Fly) consumer-grade hardware running ArduPilot.
