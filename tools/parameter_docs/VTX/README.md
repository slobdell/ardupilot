# Video Transmitter Configuration (VTX)

## Overview
The **VTX** parameter group configures the **Video Transmitter** control interface. This allows the pilot to change the channel, band, and power level of their FPV transmitter directly through the ArduPilot OSD or GCS.

## Key Concepts

### 1. SmartAudio and Tramp
ArduPilot supports the **SmartAudio** (TBS) and **Tramp** (IRC) protocols for VTX control.
*   **`VTX_ENABLE`**: Master switch.

### 2. Frequency Control
*   **`VTX_BAND`**: Selects the band (A, B, E, Fatshark, Raceband).
*   **`VTX_CHANNEL`**: Selects the channel (1-8).
*   **`VTX_FREQ`**: Displays the resulting frequency in MHz.

### 3. Power Control
*   **`VTX_POWER`**: Sets the output power (e.g., 25mW, 200mW, 800mW).
*   **`VTX_MAX_POWER`**: Limits the maximum power to ensure local legal compliance or prevent overheating.

## Integration Guide
1.  **Hardware:** Connect the SmartAudio/Tramp wire from the VTX to a UART TX pin.
2.  **Serial:** Set `SERIALx_PROTOCOL = 37` (SmartAudio) or `42` (Tramp).
3.  **Config:** Set `VTX_ENABLE = 1`.
4.  **Control:** Access the VTX menu via the OSD to change settings in the field.

## Developer Notes
*   **Library:** `libraries/AP_VideoTX`.
*   **Tables:** Supports "VTX Tables" in newer versions for custom frequency mapping.