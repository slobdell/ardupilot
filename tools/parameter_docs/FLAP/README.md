# Flap Configuration (FLAP)

## Overview
The **FLAP** parameter group configures the deployment behavior for aircraft **Flaps**. Flaps increase lift and drag, allowing for slower landing and takeoff speeds.

ArduPlane manages the deployment of flaps based on pilot switch position and, optionally, automatic flight stages (e.g., auto-landing).

## Key Concepts

### 1. Deployment Stages (`FLAP_n_PERCNT`)
Defines the percentage of servo travel for each switch position.
*   **Stage 1:** Partial flaps (often used for takeoff or loiter).
*   **Stage 2:** Full flaps (used for final approach and landing).

### 2. Deployment Speed (`FLAP_SLEWRATE`)
Prevents the flaps from "snapping" into position, which could cause a sudden ballooning effect (rapid increase in lift).
*   **Slew Rate:** Limits the degrees per second the servo can move.

## Parameter Breakdown

*   **`FLAP_1_PERCNT`**: Percentage for first stage (0-100%).
*   **`FLAP_2_PERCNT`**: Percentage for second stage.
*   **`FLAP_SLEWRATE`**: Maximum movement speed (% per second).

## Integration Guide
1.  **Outputs:** Map a servo output to `Flap` (Function 3).
2.  **Config:** Set the percentages based on your airframe manufacturer's recommendations.
3.  **Mixing:** Flaps often require a corresponding **Elevator-to-Flap** mix (see `TKOFF_FLAP_ELEV`) to counter the pitching moment they create.

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.
*   **Context:** Only relevant for **ArduPlane**.