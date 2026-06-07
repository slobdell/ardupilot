# Notify Configuration (NTF)

## Overview
The **NTF** parameter group configures the **Notification Subsystem**. This library handles user-facing feedback, including RGB status LEDs, buzzers, display screens, and OreoLEDs.

Effective notification setup is critical for safety, as it provides the pilot with visual and audible confirmation of arming state, GPS lock, and failsafe conditions.

## Key Concepts

### 1. LED Types (`NTF_LED_TYPES`)
ArduPilot supports many LED hardware types.
*   **Built-in:** The small LED on the flight controller.
*   **External (I2C):** Common Toshiba or NeoPixel LEDs found on GPS modules.
*   **Scripting:** LEDs controlled by Lua scripts.
*   **OreoLED:** Specific to the 3DR Solo and similar high-power LED systems.

### 2. Buzzer Behavior (`NTF_BUZZ_...`)
*   **`NTF_BUZZ_VOLUME`**: Global volume for the internal alarm buzzer.
*   **`NTF_BUZZ_TYPES`**: Bitmask to enable/disable specific tones (e.g., quiet the "Startup" tone but keep the "Failsafe" tone).

### 3. Display Types (`NTF_DISPLAY_TYPE`)
Supports small I2C OLED screens (SSD1306) mounted to the drone to show battery voltage and status without a GCS.

## Parameter Breakdown

*   **`NTF_LED_BRIGHT`**: LED intensity (Low, Medium, High).
*   **`NTF_LED_OVERRIDE`**: Allows selecting simplified color schemes (e.g., "Traffic Light").
*   **`NTF_OREO_THEME`**: Color themes for OreoLED rings.

## Integration Guide
*   **NeoPixels:** To use NeoPixel strips for status, set `NTF_LED_TYPES` to include NeoPixel and ensure a servo output is mapped to `LED` (Function 120).

## Developer Notes
*   **Library:** `libraries/AP_Notify`.
*   **Drivers:** Handles hardware abstraction for I2C and dedicated PWM notification devices.