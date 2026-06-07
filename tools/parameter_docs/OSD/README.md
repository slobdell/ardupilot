# On-Screen Display Configuration (OSD)

## Overview
The **OSD** parameter group configures the **On-Screen Display** subsystem. This library is responsible for rendering real-time flight data (HUD) onto the video feed, whether using an analog overlay chip (MAX7456) or digital telemetry (MSP).

ArduPilot supports up to 6 custom OSD screens, allowing the pilot to toggle between different layouts (e.g., a "Minimal" screen for racing and a "Full" screen for long-range).

## Key Concepts

### 1. OSD Hardware (`OSD_TYPE`)
Defines the rendering method.
*   **1 (MAX7456):** Standard analog OSD chip found on most classic flight controllers.
*   **3 (MSP):** Digital OSD for DJI, HDZero, and Avatar systems.
*   **5 (SITL):** Graphical OSD overlay in the simulator.

### 2. Screen Management
*   **`OSDn_ENABLE`**: Toggles screens 1 through 6.
*   **`OSD_SW_METHOD`**: Defines how to switch between screens (RC channel, push-button, or automatic based on flight stage).

### 3. Widget Placement (`OSD_W_...`)
Every element (Battery, Altitude, Speed) is a "Widget" that can be moved anywhere on the screen grid.
*   **`OSD_W_X` / `Y`**: Coordinates (typically 0-29 columns, 0-15 rows).
*   **`OSD_W_EN`**: Enables/Disables that specific element.

### 4. In-Flight Parameter Tuning
The OSD can display a "Tuning Menu" (Screen 5), allowing the pilot to change PID gains, rates, and limits using the RC sticks without needing a laptop.

## Parameter Breakdown

*   **`OSD_UNITS`**: Selects Metric, Imperial, or Aviation units.
*   **`OSD_FONT`**: Selects the character set (Regular, Bold, Large).
*   **`OSD_MSG_TIME`**: Duration of pop-up alerts.

## Integration Guide

### Setting up MSP (Digital) OSD
1.  **Hardware:** Connect VTX to a UART.
2.  **Serial:** Set `SERIALx_PROTOCOL = 33` (MSP).
3.  **Config:** Set `OSD_TYPE = 3`.
4.  **Reboot:** You should see the ArduPilot logo in your goggles.
5.  **Layout:** Use the "OSD" tab in Mission Planner to drag-and-drop elements to your preferred positions.

## Developer Notes
*   **Library:** `libraries/AP_OSD`.
*   **Extensibility:** New widgets can be added to the library to support specialized sensors (e.g., LiDAR distance, EFI status, or RPM).