# Heel Control Configuration (HEEL)

## Overview
The **HEEL** parameter group (specifically `HEEL_MAX`) configures the safety limits for **ArduRover Sailboats**.

"Heeling" refers to the lean angle of a sailboat caused by wind pressure on the sails. While some heel is normal, excessive heel can lead to a capsize or lose rudder effectiveness.

## Key Concepts

### 1. Heel Limit (`HEEL_MAX`)
This is a safety threshold. If the sailboat leans (heels) past this angle (degrees), the autopilot will automatically **ease the sails** (release the sheets) to dump wind pressure and right the boat.
*   **Purpose:** Capsize prevention.

## Parameter Breakdown

*   **`HEEL_MAX`**: Maximum allowable heel angle in degrees.
    *   **0:** Disabled (Danger!).
    *   **20-30:** Common for many small monohulls.

## Integration Guide
*   **Tuning:** Set this slightly below the angle where your hull's deck begins to submerge or where you lose steering authority.

## Developer Notes
*   **Library:** `Rover/sailboat.cpp`.
*   **Context:** Requires an accurate Roll measurement from the IMU.