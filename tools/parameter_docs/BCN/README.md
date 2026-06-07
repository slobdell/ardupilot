# Beacon Positioning (BCN)

## Overview
The **BCN** parameter group configures the **Indoor Beacon** positioning system. This driver allows ArduPilot to use range-based beacon systems (like Pozyx, Marvelmind, or Nooploop) as a substitute for GPS in indoor or GPS-denied environments.

The EKF (State Estimator) fuses distance measurements from the vehicle to known fixed beacons to calculate position (`PosHold`, `Loiter`, `Auto`).

## Key Concepts

### 1. Beacon Origin
Unlike GPS, beacons operate in a local coordinate frame (X, Y, Z relative to a "Master" beacon). To fly missions, you often need to anchor this local frame to a global Geodetic coordinate (Lat/Lon).
*   **`BCN_LATITUDE` / `BCN_LONGITUDE` / `BCN_ALT`**: Sets the global position of the system origin (usually the 0,0,0 point of the beacon network).

### 2. Alignment (`BCN_ORIENT_YAW`)
You must tell the autopilot how the beacon network's "North" aligns with True North (or the frame's heading 0).
*   If the beacon system's X-axis points East, you must set the orientation offset so the EKF aligns correctly.

## Parameter Breakdown

*   **`BCN_TYPE`**: Driver selection (0=Disabled, 1=Pozyx, 2=Marvelmind, etc.).
*   **`BCN_ORIENT_YAW`**: Rotation of the beacon network relative to True North.

## Integration Guide

### Setup
1.  **Place Beacons:** Set up your anchors/beacons in the room.
2.  **Map:** Use the manufacturer's software to map the beacon positions and freeze the map.
3.  **Config:** Set `BCN_TYPE` and `EK3_SRC1_POSXY` = Beacon.
4.  **Align:** Use a compass or known heading to align the vehicle and check if the reported position on the GCS map moves in the correct direction when you move the drone.

## Developer Notes
*   **Library:** `libraries/AP_Beacon`
*   **Usage:** Fused by `AP_NavEKF3` as a range or position source.