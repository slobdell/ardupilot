# Glide Slope Configuration (GLIDE)

## Overview
The **GLIDE** parameter group (often appearing as `LAND_GLIDE_` in the full parameter list) configures the **Autonomous Landing Glide Slope** for ArduPlane.

The glide slope is the imaginary path (usually 3 to 10 degrees) that the plane follows from the start of the landing sequence to the touchdown point.

## Key Concepts

### 1. Glide Slope Rebuilding (`GLIDE_SLOPE_THR`)
If the plane is pushed off its planned path by a gust of wind, should it dive back to the original line?
*   **Threshold:** If the plane is higher than this value (meters) above the planned slope, the autopilot will "rebuild" the slope from its current position to the target, ensuring a smoother descent.

### 2. Minimum Slope (`GLIDE_SLOPE_MIN`)
Defines the shallowest angle the plane is allowed to fly during a landing approach. This prevents the autopilot from trying to "float" indefinitely if it has too much energy.

## Parameter Breakdown

*   **`GLIDE_SLOPE_THR`**: Altitude error threshold for slope recalculation.
*   **`GLIDE_SLOPE_MIN`**: Minimum allowable glide angle (degrees).

## Integration Guide
*   **Landing Issues:** If your plane dives aggressively during landing, check if `GLIDE_SLOPE_THR` is too low.
*   **Floating:** If your plane consistently overshoots the runway, increase `GLIDE_SLOPE_MIN`.

## Developer Notes
*   **Library:** `ArduPlane/mode_landing.cpp`.
*   **TECS:** Works in tight coordination with the `TECS_` (Total Energy) library to manage the trade-off between altitude and airspeed.