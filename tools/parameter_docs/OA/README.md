# Object Avoidance (OA)

## Overview
The **OA** parameter group configures the **Object Avoidance** path-planning engine. This subsystem uses distance data from Proximity sensors (Lidar/Sonar) or Visual Odometry to autonomously steer the vehicle away from obstacles in real-time.

Unlike simple "BendyRuler" avoidance, the OA library can manage complex 3D environments and find optimal paths around large structures.

## Key Concepts

### 1. Avoidance Types (`OA_TYPE`)
Selects the primary path-finding algorithm.
*   **0:** Disabled.
*   **1 (BendyRuler):** Simple and fast. Tries a few "rays" to see which path is clear and chooses the one closest to the target waypoint.
*   **2 (Dijkstra):** Uses a pre-mapped database of the environment (`OA_DB_...`) to calculate the mathematically shortest path around an obstacle.
*   **3 (SimpleGCS):** Offloads calculation to a Ground Station.

### 2. Database Management (`OA_DB_...`)
If using Dijkstra, the drone builds a "Database" of known obstacles.
*   **`OA_DB_SIZE`**: The number of points held in the map.
*   **`OA_DB_EXPIRE`**: How long a point stays in the map after it is no longer visible.

### 3. Lookahead (`OA_BR_LOOKAHEAD`)
Defines how far ahead of the vehicle the algorithm should search for obstacles.

## Parameter Breakdown

*   **`OA_TYPE`**: Algorithm selector.
*   **`OA_MARGIN_MAX`**: The minimum distance the vehicle will attempt to maintain from any obstacle.
*   **`OA_OPTIONS`**: Bitmask for specialized behaviors.

## Integration Guide
1.  **Sensors:** Requires a 360-degree Lidar (e.g., RPLidar) or multiple directional proximity sensors.
2.  **Enable:** Set `OA_TYPE = 1` (BendyRuler) for general outdoor use.
3.  **Margin:** Set `OA_MARGIN_MAX = 2.0` (meters) to ensure a safe buffer.

## Developer Notes
*   **Library:** `libraries/AC_Avoidance`.
*   **Path Planning:** The OA engine calculates a "Virtual Waypoint" which is then fed to the L1 or Position Controller.