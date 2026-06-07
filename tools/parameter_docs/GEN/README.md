# Generator Configuration (GEN)

## Overview
The **GEN** parameter group configures the **Onboard Generator** subsystem. This is used on hybrid-electric drones that use a small internal combustion engine (ICE) to charge the batteries or power the motors in flight.

ArduPilot can monitor the generator status and, for some models, autonomously control the startup and shutdown sequence.

## Key Concepts

### 1. Generator Types (`GEN_TYPE`)
Selects the driver for the generator system.
*   **0:** Disabled.
*   **1:** RichenPower.
*   **2:** Intelligent Energy (Hydrogen Fuel Cells).

### 2. Operational Safety (`GEN_OPTIONS`)
A bitmask to control autonomous behavior.
*   **Stop on Disarm:** Automatically shuts down the generator when the vehicle disarms.
*   **Autostart:** Automatically starts the generator when battery voltage drops below a threshold.

## Parameter Breakdown

*   **`GEN_TYPE`**: Driver selection.
*   **`GEN_OPTIONS`**: Behavior flags.

## Integration Guide
1.  **Hardware:** Connect the generator's serial or PWM control line.
2.  **Telemetry:** Ensure battery monitors are configured to see the charging current.

## Developer Notes
*   **Library:** `libraries/AP_Generator`.