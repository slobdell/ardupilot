# Data Enable Pin (DE)

## Overview
The **DE** parameter group (specifically `DE_PIN`) is a helper configuration for the **Torqeedo** electric boat motor driver.

Torqeedo motors often communicate via **RS485**. To use a standard UART-to-RS485 adapter, the autopilot must manually control the **Driver Enable (DE)** pin to switch the transceiver between Transmit and Receive modes (Half-Duplex).

## Key Concepts

### 1. RS485 Half-Duplex
*   **Idle/Receive:** The DE pin is held Low. The autopilot listens for data.
*   **Transmit:** The autopilot pulls the DE pin High, sends the data bytes, and then immediately pulls DE Low again.

## Parameter Breakdown

*   **`DE_PIN`**: The GPIO pin number connected to the RS485 DE/RE pin.
    *   **-1:** Automatic/None (Use Hardware Flow Control/CTS if available).

## Integration Guide
*   **Wiring:** Connect the converter's DE and RE pins together to the Flight Controller's `DE_PIN`.
*   **Torqeedo:** This is part of the `AP_Torqeedo` library setup.

## Developer Notes
*   **Library:** `libraries/AP_Torqeedo`
*   **Context:** Only relevant if `TRQD_TYPE` is set.