# Failsafe Configuration (FS)

## Overview
The **FS** parameter group configures the autopilot's **Failsafe** systems. These are automatic emergency protocols that trigger when something goes wrong (e.g., you lose radio contact or the battery is critically low).

Failsafes are the primary defense against "Fly-Aways."

## Key Concepts

### 1. Triggers
The autopilot monitors several conditions:
*   **Radio (RC):** Triggered if the signal from your transmitter is lost.
*   **Battery:** Triggered based on `BATT_LOW_VOLT` or `BATT_LOW_MAH`.
*   **GCS:** Triggered if the telemetry link to the Ground Control Station is lost (useful for long-range autonomous missions).
*   **EKF:** Triggered if the state estimator becomes unhealthy (e.g., GPS glitch).

### 2. Actions (`FS_..._ACTION`)
What the drone does when a failsafe triggers:
*   **0 (None):** Does nothing (Dangerous!).
*   **1 (RTL):** Returns to the launch point and lands.
*   **2 (Land):** Lands immediately at its current position.
*   **3 (SmartRTL):** Retraces its path home.

## Parameter Breakdown

*   **`FS_THR_ENABLE`**: Enable/Disable Radio Failsafe.
*   **`FS_THR_VALUE`**: The PWM threshold below which the autopilot assumes the radio is disconnected (usually ~950us).
*   **`FS_BATT_ENABLE`**: Action for low battery.
*   **`FS_GCS_ENABL`**: Action for GCS link loss.

## Integration Guide

### Testing Radio Failsafe
1.  **Remove Props.**
2.  Arm the vehicle in a safe mode (e.g., Loiter).
3.  **Turn off your RC Transmitter.**
4.  Verify the HUD switches to "Failsafe" and the vehicle mode changes to "RTL" or "Land."

## Developer Notes
*   **Library:** `libraries/AP_Vehicle` / `AP_Failsafe`.
*   **Priority:** If multiple failsafes trigger, the system prioritizes the most conservative action (e.g., Land over RTL).