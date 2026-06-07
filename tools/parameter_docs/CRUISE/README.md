# Cruise Mode Configuration (CRUISE)

## Overview
The **CRUISE** parameter group (often appearing as `TRIM_ARSPD_CM`, `CRUISE_SPEED`, or `CRUISE_THROTTLE`) defines the baseline "Standard" flight/drive conditions for the vehicle.

These parameters tell the autopilot "This is what normal looks like." They are foundational for the navigation controllers (TECS / Speed Controller).

## Key Concepts

### 1. Target Speed (`CRUISE_SPEED`)
The default target speed in meters/second for Auto, Cruise, and RTL modes.
*   **Plane:** Indicated Airspeed.
*   **Rover:** Ground Speed.

### 2. Base Throttle (`CRUISE_THROTTLE`)
The approximate throttle percentage required to maintain `CRUISE_SPEED` in level flight/driving.
*   **Importance:** This provides a "FeedForward" baseline for the throttle controller. The PID loops only work to correct errors *around* this base value. If set correctly, the controller has to do very little work.

## Parameter Breakdown

*   **`CRUISE_SPEED`**: Target speed (m/s).
*   **`CRUISE_THROTTLE`**: Target throttle (%).
*   **`CRUISE_ALT_FLOOR`**: (Plane) Minimum altitude floor.

## Integration Guide

### Tuning
1.  **Fly/Drive Manual:** Establish a steady speed that feels efficient.
2.  **Observe:** Note the speed and throttle percentage from the OSD or logs.
3.  **Set:** Update `CRUISE_SPEED` and `CRUISE_THROTTLE` with these observed values.

## Developer Notes
*   **Aliases:** In older Plane parameters, `TRIM_ARSPD_CM` is the canonical name for `CRUISE_SPEED`.
*   **Dependencies:** `TECS` uses `CRUISE_SPEED` as the center of the speed envelope.