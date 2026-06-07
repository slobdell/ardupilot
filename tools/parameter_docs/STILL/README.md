# Motion Detection Threshold (STILL)

## Overview
The **STILL** parameter group (specifically `STILL_THRESH` or `INS_STILL_THRESH`) defines the sensitivity of the autopilot's **Motion Detection** logic.

The system needs to know if the vehicle is physically stationary for critical operations like gyro calibration on boot or performing pre-arm checks.

## Key Concepts

### 1. Stillness Detection
The autopilot monitors the raw variance of the accelerometers.
*   **Stationary:** If the variance is below `STILL_THRESH`, the system assumes it is on the ground and still.
*   **Moving:** If vibrations or movement exceed this value, the system assumes it is being handled or is on a moving platform.

## Parameter Breakdown

*   **`STILL_THRESH`**: Acceleration variance threshold.
    *   **Typical:** 0.1 for fixed-wing, 2.5 for multicopters (to account for motor vibration).

## Integration Guide
*   **Boat Starts:** If you are launching from a moving boat, the autopilot may refuse to calibrate its gyros because it thinks it is moving. In this case, you must **increase** `STILL_THRESH` to allow the calibration to finish despite the deck's motion.

## Developer Notes
*   **Library:** `libraries/AP_InertialSensor`.