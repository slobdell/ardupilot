# Ground Effect Compensation (GND)

## Overview
The **GND** parameter group (specifically `GND_EFFECT_COMP`) configures the **Ground Effect Compensation** feature for ArduCopter.

When a multicopter is very close to the ground, the downward air from the propellers (prop wash) creates a high-pressure bubble under the frame. This high pressure can "fool" the barometer into thinking the drone has suddenly dropped in altitude, causing it to jump or bounce during landing/takeoff.

## Key Concepts

### 1. Pressure Compensation
This system uses a model of the vehicle's thrust to estimate the pressure increase caused by the ground and subtracts it from the barometer reading.
*   **Trigger:** The compensation is only active when the vehicle is within a certain distance of the ground (based on rangefinder or takeoff altitude).

## Parameter Breakdown

*   **`GND_EFFECT_COMP`**:
    *   **0:** Disabled.
    *   **1:** Enabled.

## Integration Guide
*   **Symptom:** If your drone hovers stably at 5 meters but "balloons" or jumps when you try to land it, enable `GND_EFFECT_COMP`.

## Developer Notes
*   **Library:** `libraries/AP_Baro`.
*   **Algorithm:** Uses the estimated thrust and the current height above ground to calculate a dynamic pressure offset.