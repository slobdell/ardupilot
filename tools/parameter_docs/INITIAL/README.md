# Initial State Configuration (INITIAL)

## Overview
The **INITIAL** parameter group (specifically `INITIAL_MODE`) defines the behavior of the autopilot immediately after boot-up.

## Key Concepts

### 1. Boot-Up Mode
When you power on the vehicle, it must enter a safe and predictable state before the pilot takes control.
*   **`INITIAL_MODE`**: (ArduRover) Selects which drive mode is active at startup.
    *   **Default:** Usually 0 (Manual) or 1 (Hold).
    *   **Safety:** Setting this to "Hold" ensures the rover won't move even if the transmitter is sending a non-centered signal at boot.

## Parameter Breakdown

*   **`INITIAL_MODE`**: Mode ID to enter on boot.

## Developer Notes
*   **Vehicle:** **ArduRover**.
*   **Related:** Plane and Copter typically boot into `STABILIZE` or `MANUAL` by default and do not have a dedicated parameter for this.