# Minimum Threshold Configuration (MIN)

## Overview
The **MIN** parameter group is a collection of minimum safety and operational thresholds for various subsystems.

## Key Concepts

### 1. Terrain Following (`MIN_CM`)
(ArduPlane) Defines the minimum clearance altitude (in centimeters) the autopilot will maintain above the ground when using **Terrain Following** (TERRAIN) logic.

### 2. Tracker Reversal (`MIN_REVERSE_TIME`)
(Antenna Tracker) For trackers that don't have continuous 360-degree rotation, they must occasionally "unwind." This parameter sets the minimum time (seconds) to continue the unwinding motion once a limit is hit, preventing rapid oscillation at the end-stop.

## Developer Notes
*   **Context:** `MIN_CM` is associated with `AP_Terrain`. `MIN_REVERSE_TIME` is specific to `AntennaTracker`.