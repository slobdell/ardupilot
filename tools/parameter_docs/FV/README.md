# Forward/Vertical Decoupling (FV)

## Overview
The **FV** parameter group (specifically `FV_CPLNG_K`) is a specialized configuration for **Vectored ROVs** (Submarines).

Due to the hydrodynamic design of some ROV frames, applying high vertical thrust (climbing/diving) can induce an unwanted pitching moment if the center of drag is not aligned with the center of thrust. This group manages the mathematical decoupling of these forces.

## Key Concepts

### 1. Hydrodynamic Coupling
In a perfectly balanced vehicle, Forward thrust and Vertical thrust are independent. However, in reality, as water flows over the frame, the vehicle may want to pitch up or down.
*   **`FV_CPLNG_K`**: Acts as a gain factor that limits the maximum allowed forward thrust based on the amount of vertical thrust being applied.

## Parameter Breakdown

*   **`FV_CPLNG_K`**: Forward/Vertical to Pitch decoupling factor.
    *   **0:** Disabled (Full power available on both axes).
    *   **1.0 (Default):** Balanced decoupling.

## Integration Guide
*   **Symptom:** If your ROV pitches up or down uncontrollably when you apply full throttle (vertical) while moving forward, **increase** this value.

## Developer Notes
*   **Library:** `libraries/AP_Motors/AP_Motors6DOF.cpp`.
*   **Context:** Only used in **ArduSub**.