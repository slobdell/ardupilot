# UART Physical Port Configuration (UART)

## Overview
The **UART** parameter group (specifically within **AP_Periph**) configures the physical serial ports on peripheral hardware.

## Key Concepts

### 1. Serial Mapping
On DroneCAN nodes, UARTs are used to connect GPS receivers or ADS-B units.
*   **`UARTx_OPTIONS`**: Bitmask for signal inversion and swapping.
*   **`UARTx_RTSCTS`**: Enables hardware flow control.

## Developer Notes
*   **Library:** `Tools/AP_Periph`.
*   **See Also:** [SERIAL](../SERIAL/README.md) for the main autopilot serial configuration.