# Left Button Configuration (LEFT)

## Overview
The **LEFT** parameter group (specifically `LEFT_LONG`) configures the behavior of the **Left Shoulder Button** on specialized **Toy Mode** controllers (gamepad-style).

## Key Concepts

### 1. Toy Mode Mapping
In Toy Mode, the controller buttons are mapped to specific ArduPilot flight modes or actions.
*   **`LEFT_LONG`**: Defines what happens when the left button is held for more than 1 second.
    *   **Common Actions:** Change flight mode, trigger photo, or perform a flip.

## Developer Notes
*   **Library:** `ArduCopter/toy_mode.cpp`.
*   **Context:** Only relevant if using specific SkyViper or similar gamepad-driven hardware.