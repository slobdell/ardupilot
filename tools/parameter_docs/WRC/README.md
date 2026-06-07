# Wheel Rate Control Configuration (WRC)

## Overview
The **WRC** parameter group configures the **Closed-Loop Wheel Speed** controller for **ArduRover**.

Without WRC, a rover uses "Open-Loop" control, sending a fixed throttle percentage. With WRC, the autopilot uses feedback from **Wheel Encoders** to ensure the wheels are spinning at exactly the commanded speed, regardless of surface friction, slope, or battery voltage.

## Key Concepts

### 1. Velocity Feedback
The system calculates the error between the "Commanded Wheel Speed" and the "Actual Wheel Speed" (measured by encoders).
*   **`WRC_ENABLE`**: Master switch.

### 2. PID Tuning
(If present in group) Standard gains to control the responsiveness of the wheel motor response.

## Integration Guide
1.  **Hardware:** Install and calibrate wheel encoders (`WENC` group).
2.  **Enable:** Set `WRC_ENABLE = 1`.
3.  **Tuning:** Adjust gains to ensure the rover can maintain a crawl up a hill without stalling or jerking.

## Developer Notes
*   **Library:** `libraries/AP_WheelEncoder/AP_WheelRateControl.cpp`.
*   **Dependency:** This group is functionally useless without the `WENC` group being configured first.