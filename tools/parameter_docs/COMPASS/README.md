# Compass Configuration (COMPASS)

## Overview
The **COMPASS** parameter group configures the **Magnetometers** (Electronic Compasses). Reliable heading information is critical for GPS flight modes (Loiter, Auto, RTL) to determine the vehicle's yaw relative to the world.

ArduPilot supports up to 3 compasses. `COMPASS` (1), `COMPASS2`, and `COMPASS3`.

## Key Concepts

### 1. Orientation (`COMPASS_ORIENT`)
**Most Critical Setting.** If using an external GPS/Compass module, the sensor is often mounted upside down or rotated relative to the flight controller.
*   **External:** Set `COMPASS_EXTERNAL = 1`.
*   **Rotation:** Match the mounting (e.g., `ROTATION_ROLL_180`).

### 2. Calibration (Offsets & Scaling)
*   **Offsets (`COMPASS_OFS_X/Y/Z`):** Compensates for "Hard Iron" distortion (permanent magnets, screws, currents) on the frame.
*   **Scaling (`COMPASS_SCALE`):** Compensates for "Soft Iron" distortion (ferrous metals stretching the field) and sensor axis sensitivity differences.

### 3. Declination (`COMPASS_DEC`)
The difference between Magnetic North and True North.
*   **Auto (`COMPASS_AUTODEC`):** Recommended. Calculates declination based on GPS location table.

### 4. Motor Compensation (`COMPASS_MOT_...`)
High current in power wires creates a magnetic field that shifts the compass as throttle increases.
*   **CompassMot:** A calibration routine that measures this interference vs. throttle/current and subtracts it in flight.

## Parameter Breakdown

*   **`COMPASS_ENABLE`**: Master switch.
*   **`COMPASS_LEARN`**: In-flight learning of offsets (Compass Learn).
*   **`COMPASS_USE`**: Trusted for navigation? (Uncheck for internal compasses with high interference).
*   **`COMPASS_DEV_ID`**: Hardware ID.

## Integration Guide

### Typical Setup
1.  **Hardware:** Mount GPS/Compass mast away from power wires/ESCs.
2.  **Calibrate:** Run "Onboard Mag Calibration" ("The Dance"). Rotate vehicle on all axes until progress bars fill.
3.  **Verify:** Check if North is North.
4.  **Prioritize:** Disable internal compasses (`COMPASS_USE2 = 0`, etc.) if they show high interference ("Compass Variance" errors).

## Developer Notes
*   **Library:** `libraries/AP_Compass`
*   **MagFit:** Advanced 3D ellipsoid fitting is used for calibration.