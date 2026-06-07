# Scan Mode Configuration (SCAN)

## Overview
The **SCAN** parameter group configures the behavior of the **Scan** mode for the **Antenna Tracker**.

Scan mode is used when the tracker does not have a valid vehicle position to follow. Instead of sitting idle, the tracker can be programmed to oscillate or sweep a specific area to help the ground station radios re-acquire a signal.

## Key Concepts

### 1. Sweep Speeds
*   **`SCAN_SPEED_YAW`**: The rotation speed (deg/s) for the horizontal sweep.
*   **`SCAN_SPEED_PIT`**: The rotation speed (deg/s) for the vertical sweep.

## Integration Guide
*   **Usage:** If you fly out of range and the tracker stops moving, switching to `SCAN` mode will help sweep the sky with your directional antenna to catch a "glimmer" of telemetry data.

## Developer Notes
*   **Library:** `AntennaTracker/Parameters.cpp`.