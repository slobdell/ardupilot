# Angle Limits & Configuration (ANGLE)

## Overview
The **ANGLE** parameter group is a mixed category containing angle-related limits for different vehicle types.

**Note:** The parameters here serve completely different functions depending on whether you are flying a Multicopter or sailing a Boat.

## Key Concepts

### 1. Copter Bank Limit (`ANGLE_MAX`)
This is the **Global Lean Angle Limit** for ArduCopter in all stabilized modes (Loiter, AltHold, Auto, RTL, PosHold, Drift).
*   **Function:** It clamps the maximum pitch and roll angle the autopilot will ever command.
*   **Safety:** Prevents the copter from banking so steeply that it loses altitude (insufficient vertical thrust component).
*   **Performance:** Higher angles = Faster top speed in GPS modes (Speed = sqrt(tan(Angle) * g * Radius)).

### 2. Sailboat Configuration (`ANGLE_IDEAL`, `ANGLE_MIN`)
(ArduRover - Sailboats Only)
These parameters configure the automated sail winch control.
*   **`ANGLE_IDEAL`**: The optimal angle of attack for the mainsail to generate thrust.
*   **`ANGLE_MIN`**: The tightest angle the sail can physically be pulled in (close-hauled limit).

## Parameter Breakdown

### Copter
*   **`ANGLE_MAX`**: Maximum lean angle in centi-degrees (e.g., 4500 = 45 degrees).

### Rover (Sailboat)
*   **`ANGLE_IDEAL`**: Ideal sail angle (deg).
*   **`ANGLE_MIN`**: Minimum sail angle (deg).

## Integration Guide

### Tuning Copter Speed
1.  **Default:** 45 degrees (`ANGLE_MAX = 4500`). Good for most camera drones.
2.  **Fast Flight:** Increase to 55-60 degrees for high-speed autonomous missions (ensure your T/W ratio is > 2:1).
3.  **Filming:** Decrease to 25-30 degrees for very smooth, slow movements.

### Tuning Sailboats
1.  **Bench Test:** Verify winch movement limits.
2.  **Set Limits:** Ensure `ANGLE_MIN` prevents the boom from hitting the shrouds or superstructure.

## Developer Notes
*   **Copter:** `ANGLE_MAX` is a `GSCALAR` in `ArduCopter/Parameters.cpp`.
*   **Rover:** `ANGLE_IDEAL` is defined in `Rover/sailboat.cpp`.