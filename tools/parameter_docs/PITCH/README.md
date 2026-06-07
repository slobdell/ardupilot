# Pitch Axis Configuration (PITCH)

## Overview
The **PITCH** parameter group handles configuration for the **Pitch (Tilt) Axis** across various vehicle and peripheral types.

## Key Concepts

### 1. Tracker Speed (`PITCH_SLEW_TIME`)
(Antenna Tracker) This parameter limits the maximum angular velocity of the tilt mechanism.
*   **Purpose:** Prevents mechanical damage to heavy high-gain antennas by ensuring the servos don't jerk the assembly too violently.
*   **Units:** Time (seconds) to traverse 180 degrees.

### 2. Trim (`PITCH_TRIM`)
(Helicopter) Defines the collective pitch trim value required to maintain hover.

## Developer Notes
*   **Context:** `PITCH_SLEW_TIME` is specific to **AntennaTracker**. `PITCH_TRIM` is common in **ArduCopter Heli**.