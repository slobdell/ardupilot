# Cellular Telemetry (CELL)

## Overview
The **CELL** parameter group configures the **4G/LTE Cellular Telemetry** subsystem. This allows the autopilot to communicate over cellular networks using supported modems (e.g., Skywire, SIMCOM) connected via Serial or USB (PPP).

**Note:** The parameter `CELL_COUNT` listed in some databases often belongs to the **OSD** library (used for displaying average cell voltage) rather than the Cellular driver itself. This overlap can be confusing.

## Key Concepts

### 1. Cellular Modems
ArduPilot can manage basic modem initialization (AT commands) to establish an IP connection. Once connected, telemetry is routed over UDP/TCP to a Ground Station IP.

### 2. OSD Helper (`CELL_COUNT`)
(If present) This parameter helps the OSD calculate the "Average Cell Voltage" by dividing the total pack voltage by the number of cells.
*   **Auto (-1):** Guesses the cell count based on total voltage at boot (assuming 3.7V-4.2V/cell).
*   **Manual:** Forces a specific count (e.g., 6S, 12S). Useful if you plug in a partially discharged pack that might be mistaken for a full pack of lower cell count.

## Parameter Breakdown

*   **`CELL_ENABLE`**: Master switch for cellular driver.
*   **`CELL_TYPE`**: Driver selection.
*   **`CELL_PIN`**: PIN code for the SIM card.
*   **`CELL_APN`**: Access Point Name string.

*(Note: `CELL_COUNT` is functionally part of the OSD group logic).*

## Integration Guide
1.  **Hardware:** Connect modem to a UART.
2.  **Serial:** Set `SERIALx_PROTOCOL = 1` (MAVLink) or specific modem protocol.
3.  **Config:** Set `CELL_ENABLE`, `CELL_TYPE`, and `CELL_APN`.

## Developer Notes
*   **Library:** `libraries/AP_Cellular` (Driver) and `libraries/AP_OSD` (Display).