# Reset Configuration (RST)

## Overview
The **RST** parameter group (specifically `RST_SWITCH_CH`) configures the manual **Reset** behavior for ArduRover.

## Key Concepts

### 1. The Reset Switch
In some scenarios, a rover might be stuck in a failsafe state or a geofence breach. This parameter allows the pilot to assign a specific RC channel to a "Reset" button.
*   **Action:** When the switch is toggled, the autopilot attempts to clear the current error state and return to the last active flight mode.

## Developer Notes
*   **Library:** `ArduRover/Parameters.cpp`.
*   **Context:** Only relevant for **ArduRover**.