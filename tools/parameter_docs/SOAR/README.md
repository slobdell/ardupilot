# Autonomous Soaring (SOAR)

## Overview
The **SOAR** parameter group configures the **Autonomous Soaring** engine for **ArduPlane**. This allows gliders to automatically detect thermals (rising air), bank into them to gain altitude, and then continue on their mission, significantly extending flight endurance.

## Key Concepts

### 1. Thermal Detection
The autopilot monitors the vertical velocity of the aircraft (via EKF and TE airspeed). If it detects a climb that cannot be explained by throttle or pitch changes, it assumes it has found a thermal.
*   **`SOAR_VSPEED`**: The minimum lift (m/s) required to trigger soaring behavior.

### 2. Loitering in Thermals (`SOAR_THML_...`)
Once a thermal is found, the plane switches to a circular loiter to stay within the rising air column.
*   **`SOAR_THML_BANK`**: The bank angle used while circling in the thermal.
*   **`SOAR_THML_ARSPD`**: The target airspeed for efficient climbing.

### 3. Altitude Limits
*   **`SOAR_ALT_MAX`**: The height at which the plane will exit the thermal and resume its mission.
*   **`SOAR_ALT_MIN`**: The minimum altitude below which the plane will ignore thermals and use its motor to stay aloft.

## Parameter Breakdown

*   **`SOAR_ENABLE`**: Master switch.
*   **`SOAR_POLAR_K / B`**: Aerodynamic "Polar" coefficients for the specific glider wing.
*   **`SOAR_ALT_CUTOFF`**: Altitude at which to stop using the motor during a climb.

## Integration Guide
1.  **Requirement:** A glider with an airspeed sensor and high efficiency.
2.  **Config:** Set your wing polar values (see Wiki for common airframes).
3.  **Mode:** Switch to `AUTO` or `CRUISE` and enable soaring via an RC switch (`RCx_OPTION = 88`).

## Developer Notes
*   **Library:** `libraries/AP_Soaring`.
*   **Algorithm:** Uses the **Total Energy** rate of change to estimate environmental air movement.