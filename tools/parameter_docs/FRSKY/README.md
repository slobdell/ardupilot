# FrSky Telemetry Configuration (FRSKY)

## Overview
The **FRSKY** parameter group configures the telemetry output for **FrSky** radio systems (SmartPort and D-Series). This allows you to see live battery voltage, GPS position, and flight mode directly on your FrSky transmitter screen.

## Key Concepts

### 1. Telemetry Options (`FRSKY_OPTIONS`)
A bitmask for advanced features.
*   **Bit 0:** Enable Passthrough (Requires OpenTX/EdgeTX and a Lua script like Yaapu). This is the modern, high-bandwidth method.
*   **Bit 1:** Enable individual sensor IDs.

### 2. D-Series vs SmartPort
*   **D-Series:** Legacy (Hub protocol).
*   **SmartPort (S.Port):** Modern, bi-directional protocol used by X-series receivers (X8R, R-XSR).

## Parameter Breakdown

*   **`FRSKY_D_RATE`**: Update rate for D-Series telemetry.
*   **`FRSKY_OPTIONS`**: Bitmask for Passthrough and other features.

## Integration Guide
1.  **Hardware:** Connect the S.Port pin of your receiver to a UART TX pin. (Note: FrSky S.Port is inverted; many boards have a dedicated "FrSky" port or require `SERIALx_OPTIONS` to enable inversion).
2.  **Protocol:** Set `SERIALx_PROTOCOL = 10` (Passthrough) or `4` (SmartPort).
3.  **Lua Script:** If using Passthrough, download and install the **Yaapu Telemetry Script** on your Taranis/Horus/TX16S.

## Developer Notes
*   **Library:** `libraries/AP_Frsky_Telem`.