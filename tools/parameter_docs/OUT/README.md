# Output Configuration (OUT)

## Overview
The **OUT** parameter group (specifically within **AP_Periph** firmware) configures the motor and servo **Output Protocols**.

When using a DroneCAN peripheral to drive servos or ESCs, these parameters define how those electrical signals are generated and managed.

## Key Concepts

### 1. ESC Protocols (`OUT_BLH_...`)
Configures **BLHeli_32** and **BLHeli_S** support for ESCs connected to the peripheral node.
*   **`OUT_BLH_MASK`**: Bitmask of which outputs should use BLHeli-compatible PWM.
*   **`OUT_BLH_BDMASK`**: Enables Bidirectional DShot (RPM telemetry).

### 2. DShot Configuration (`OUT_DSHOT_RATE`)
Sets the digital speed of the motor protocol (e.g., 150, 300, 600).

### 3. GPIO Conversion (`OUT_GPIO_MASK`)
Allows some PWM pins on the peripheral to be converted to digital High/Low pins.

## Developer Notes
*   **Library:** `Tools/AP_Periph`.
*   **Performance:** DShot rates are limited by the MCU speed of the peripheral node (typically F4 or G4).