# Mixer Configuration (MIXING)

## Overview
The **MIXING** parameter group (specifically `MIXING_GAIN` and `MIXING_OFFSET`) configures the output scaling for **Elevon** and **V-Tail** aircraft.

In these airframes, two surfaces handle two different control axes (e.g., Elevons handle Roll AND Pitch). The mixer combines the demands from the controllers into physical servo movements.

## Key Concepts

### 1. Mixing Gain (`MIXING_GAIN`)
The multiplier applied to the mixed output.
*   **Purpose:** If your control surfaces don't move enough at full stick, increase this. If they move too much (binding), decrease it.

### 2. Reflex / Offset (`MIXING_OFFSET`)
Adds a constant bias to the surfaces.
*   **Purpose:** Many flying wings require "Reflex" (upward elevator trim) to maintain stable flight. Using this parameter allows you to add that reflex without affecting the center-point of the PID loops.

## Parameter Breakdown

*   **`MIXING_GAIN`**: Output multiplier (typically 0.5 to 1.0).
*   **`MIXING_OFFSET`**: Neutral bias (%).

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.
*   **Context:** Only used when `FRAME_TYPE` or `SERVOx_FUNCTION` indicates a mixed output (Elevon/VTail).