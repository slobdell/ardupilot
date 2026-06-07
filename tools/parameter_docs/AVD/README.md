# ADSB Traffic Avoidance (AVD)

## Overview
The **AVD** parameter group configures the **ADSB Collision Avoidance** system. This library uses data from the ADS-B Receiver (`ADSB` group) to detect manned aircraft on a collision course and automatically take evasive action.

**Note:** Do not confuse this with `AVOID`, which handles obstacle avoidance (walls/trees) using Lidar/cameras.

## Key Concepts

### 1. Failsafe vs. Warning
*   **Warning (`W_` params):** When an intruder is detected within the "Warning" radius/time, the GCS triggers an alert ("Traffic!").
*   **Failsafe (`F_` params):** When an intruder breaches the critical "Failsafe" radius/time, the vehicle takes autonomous action.

### 2. Actions (`AVD_F_ACTION`)
What to do when a collision is imminent?
*   **0:** Disable.
*   **1:** Report Only.
*   **2:** Climb or Descend (Plane only).
*   **3:** RTL.
*   **4:** Hover.
*   **5:** Loiter.

## Parameter Breakdown

*   **`AVD_ENABLE`**: Master switch.
*   **`AVD_W_DIST_XY`**: Horizontal distance threshold for Warning.
*   **`AVD_F_DIST_XY`**: Horizontal distance threshold for Failsafe action.
*   **`AVD_F_TIME`**: Time to impact (seconds) threshold for Failsafe.

## Integration Guide
1.  **Enable:** Set `AVD_ENABLE = 1`.
2.  **Define Zones:** Set your Warning zone (e.g., 2000m) and Failsafe zone (e.g., 1000m).
3.  **Select Action:** For Copter, `RTL` or `Loiter` is common. For Plane, `Climb/Descend` tries to change altitude to clear the traffic.

## Developer Notes
*   **Library:** `libraries/AP_Avoidance`
*   **Prefix:** `AVD_`