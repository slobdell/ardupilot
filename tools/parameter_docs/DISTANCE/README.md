# Distance Minimum (DISTANCE)

## Overview
The **DISTANCE** parameter group is specific to the **Antenna Tracker** firmware. It prevents the tracker from trying to track a vehicle that is too close.

## Key Concepts

### 1. Cone of Silence
When a vehicle is very close (or directly overhead), the angular rate required to track it becomes infinite (singularity). Attempting to track here causes violent servo movements.
*   **`DISTANCE_MIN`** defines this "safe zone" radius.

## Parameter Breakdown

*   **`DISTANCE_MIN`**: Minimum distance in meters.
    *   If `Target Distance` < `DISTANCE_MIN`: Stop tracking (Hold position).

## Integration Guide
*   **Launch:** Set this to 5-10 meters so the tracker doesn't freak out while you are arming the drone next to it.

## Developer Notes
*   **Vehicle:** **AntennaTracker**.