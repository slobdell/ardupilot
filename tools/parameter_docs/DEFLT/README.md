# Default Configuration (DEFLT)

## Overview
The **DEFLT** parameter group is specific to **DroneCAN / AP_Periph** firmware. It allows the user to reconfigure the "default" personality of a peripheral node without reflashing it.

Since the same hardware (e.g., a generic F4 board) can serve as a GPS node, an ESC node, or a Servo controller, this parameter tells the firmware which subsystems to initialize at boot.

## Key Concepts

### 1. Personality Selection
A single `AP_Periph` binary might support multiple roles.
*   **GPS Node:** Initializes UARTs for GPS.
*   **ESC Node:** Initializes PWM outputs for motor control.
*   **Rangefinder Node:** Initializes I2C/Serial for Lidar.

## Parameter Breakdown

*   **`DEFLT_MODE`**: Bitmask or Enum selecting the active drivers.

## Integration Guide
*   **Usage:** Usually set by the factory. If you are repurposing a generic CAN node, change this to match your connected sensors.

## Developer Notes
*   **Library:** `Tools/AP_Periph`