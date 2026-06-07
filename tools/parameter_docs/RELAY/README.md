# Relay Configuration (RELAY)

## Overview
The **RELAY** parameter group configures the **Digital Relay** subsystem. Relays are simple On/Off (3.3V/5V digital) switches used to control external hardware that does not require a PWM signal.

ArduPilot supports up to 6 standard relays (and more in some versions) that can be mapped to any GPIO-capable pin on the flight controller.

## Key Concepts

### 1. Relay Assignment (`RELAYx_PIN`)
Maps a physical pin on the flight controller to a logical relay ID.
*   **`RELAY1_PIN`**: The GPIO ID of the first relay (e.g., 50 for AUX 1).
*   **Disabled (-1):** The relay is not active.

### 2. Logic Polarity (`RELAYx_INVERTED`)
Defines whether "On" is High (3.3V) or Low (0V).
*   **0 (Normal):** On = High, Off = Low.
*   **1 (Inverted):** On = Low, Off = High.

### 3. Default State (`RELAYx_DEFAULT`)
Defines the state of the relay immediately after the autopilot boots up.
*   **0:** Off.
*   **1:** On.
*   **2:** No change (Maintain state across reboots if possible).

## Parameter Breakdown

*   **`RELAY_ON`**: (Legacy/Global) Global command to toggle.
*   **`RELAY1_FUNCTION`**: Sets the purpose of the relay (e.g., Relay, Ignition, Brush).

## Integration Guide
1.  **Select Pin:** Identify an AUX pin you wish to use.
2.  **GPIO Mask:** Ensure that pin is enabled in `BRD_PWM_COUNT` or `GPIO_MASK` (depending on firmware).
3.  **Config:** Set `RELAY1_PIN` to the pin ID.
4.  **Control:** Map an RC channel to `Relay 1` (RC Option 33) to toggle it with a switch.

## Developer Notes
*   **Library:** `libraries/AP_Relay`.
*   **Capacity:** Useful for controlling lights, smoke systems, camera shutters, or high-power battery isolation contactors.