# Flight Mode Configuration (FLTMODE)

## Overview
The **FLTMODE** parameter group assigns specific autopilot behaviors (Flight Modes) to the physical switch positions on your RC transmitter.

ArduPilot supports up to 6 distinct flight modes accessible via a single RC channel (usually Channel 5). Each position corresponds to a specific PWM range.

## Key Concepts

### 1. Switch Mapping (`FLTMODE1`...`FLTMODE6`)
*   **Position 1 (Low PWM):** Controlled by `FLTMODE1`.
*   **Position 6 (High PWM):** Controlled by `FLTMODE6`.
*   **Common Modes:**
    *   **Manual/Stabilize:** Pilot has full control.
    *   **Loiter/PosHold:** GPS-based position hold.
    *   **Auto:** Follows a mission.
    *   **RTL:** Returns to home.

### 2. Mode Channel (`FLTMODE_CH`)
Defines which RC channel is used for mode selection.
*   **Default:** 5 (Standard).
*   **Change:** Some pilots prefer channel 8 or others.

## Parameter Breakdown

*   **`FLTMODE1`..`6`**: Integer mode ID (Vehicle dependent).
*   **`FLTMODE_CH`**: RC channel number.
*   **`FLTMODE_GCSBLOCK`**: Prevents the Ground Station from changing modes while the RC transmitter is in a specific state.

## Integration Guide
1.  **Configure Transmitter:** Use "Mixes" to map a 3-position and 2-position switch to a single channel to achieve 6 positions.
2.  **Assign Modes:** In the GCS "Flight Modes" screen, select your desired modes for each position.
3.  **Verify:** Toggle the switches and ensure the active mode changes in the HUD.

## Developer Notes
*   **Library:** `AP_Vehicle` / `libraries/AP_Common`.
*   **IDs:** Mode IDs are NOT the same across vehicles (e.g., Copter Mode 0 is Stabilize, but Plane Mode 0 is Manual).