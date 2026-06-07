# ZigZag Mode Configuration (ZIGZ)

## Overview
The **ZIGZ** parameter group configures the **ZigZag** flight mode. This is a specialized semi-autonomous mode for **Agricultural Sprayers** and **Surveying**.

It allows the pilot to define two points (A and B) and then simply push the stick forward to have the drone fly a perfect straight line to the other side, "step" to the next row, and wait for the next command.

## Key Concepts

### 1. Line Sequencing
The mode automates the repetitive "Back and Forth" work of crop spraying.
*   **`ZIGZ_SIDE_DIST`**: Defines the "Step" or width (meters) of each row.
*   **`ZIGZ_DIRECTION`**: Selects if the step should be to the left or right.

### 2. Auto-Spraying (`ZIGZ_SPRAYER`)
Can be linked to the `SPRAY_` group to automatically turn the pump on during the straight segments and off during the turns.

## Developer Notes
*   **Library:** `ArduCopter/mode_zigzag.cpp`.