# Common Parameters (COMMON)

## Overview
The **COMMON** parameter group is a container for parameters that don't fit neatly into a specific library subclass or are shared generically across vehicle types (though often defined in vehicle-specific code).

In this specific documentation set, it largely contains the **Flight Mode** switch mapping parameters for Rover (and historically other vehicles before they moved to `FLTMODE_`).

## Key Concepts

### 1. Mode Switch Mapping (`MODEx`)
ArduPilot allows you to map up to 6 flight modes to a single RC channel (usually Channel 5 or 8) using PWM ranges.
*   **`MODE1`**: PWM 0-1230.
*   **`MODE2`**: PWM 1231-1360.
*   **`MODE3`**: PWM 1361-1490.
*   **`MODE4`**: PWM 1491-1620.
*   **`MODE5`**: PWM 1621-1749.
*   **`MODE6`**: PWM 1750+.

## Parameter Breakdown

*   **`MODE1`..`MODE6`**: Selects the active mode for that switch position (e.g., MANUAL, STEERING, AUTO).
*   **`DUMMY`**: A test parameter with no effect.

## Integration Guide
*   **Setup:** Use the "Flight Modes" tab in Mission Planner. It automatically sets these parameters based on the dropdown menu selections.

## Developer Notes
*   **Note:** Copter uses `FLTMODE_x`. Plane uses `FLTMODE_x`. Rover uses `MODE_x`. This inconsistency is historical.