# Geofence Configuration (FENCE)

## Overview
The **FENCE** parameter group configures the **Geofence** safety system. A Geofence is a virtual perimeter (3D box, cylinder, or complex polygon) that the vehicle is not allowed to leave (Stay-In) or enter (Stay-Out).

If the vehicle breaches a fence, the autopilot takes autonomous action (usually RTL or Land) to bring it back to safety.

## Key Concepts

### 1. Fence Types (`FENCE_TYPE`)
ArduPilot supports multiple fence styles:
*   **Altitude (`ALT_MAX`):** Prevents the vehicle from flying above a legal ceiling.
*   **Circle (`RADIUS`):** A cylindrical "Stay-In" fence around the Home or takeoff point.
*   **Polygon:** Custom shapes drawn in the GCS (Mission Planner/QGC).

### 2. Actions (`FENCE_ACTION`)
What happens when a breach occurs?
*   **0:** Report Only (GCS warns, but no autonomous move).
*   **1:** RTL (Returns to Home or nearest Rally point).
*   **2:** Land (Immediate descent).

### 3. Failsafes and Margins
*   **`FENCE_MARGIN`**: The distance from the fence boundary where the "Warning" trigger fires, allowing the autopilot to brake before actually crossing the line.
*   **`FENCE_ALT_MIN`**: (Plane) Prevents the aircraft from diving below a safe terrain-clearance floor.

## Parameter Breakdown

*   **`FENCE_ENABLE`**: Master switch.
*   **`FENCE_TYPE`**: Bitmask of active fence types (1=Alt, 2=Circle, 4=Polygon).
*   **`FENCE_ACTION`**: Breach behavior.
*   **`FENCE_ALT_MAX`**: The hard altitude ceiling (meters).
*   **`FENCE_RADIUS`**: Maximum distance from Home (meters).

## Integration Guide

### Setting up a Basic Safety Fence
1.  **Enable:** Set `FENCE_ENABLE = 1`.
2.  **Ceiling:** Set `FENCE_ALT_MAX = 120` (FAA legal limit in meters).
3.  **Boundary:** Set `FENCE_RADIUS = 300` (Visible line of sight).
4.  **Action:** Set `FENCE_ACTION = 1` (RTL).
5.  **Verify:** Check for "Fence: OK" in the GCS pre-arm checklist.

## Developer Notes
*   **Library:** `libraries/AC_Fence`.
*   **Storage:** Polygon points are stored alongside mission waypoints but in a separate memory area.
*   **Precision:** Fence checks run at the main loop rate (400Hz) for near-instant detection.