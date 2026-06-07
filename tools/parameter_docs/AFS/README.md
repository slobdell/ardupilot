# Advanced Failsafe (AFS)

## Overview
The **AFS** parameter group configures the **Advanced Failsafe** library. This subsystem is distinct from the standard `FS_` (Failsafe) parameters found in Plane/Copter. It is designed to meet strict **Flight Termination System (FTS)** requirements for regulatory compliance or competitions (e.g., UAV Challenge Outback Rescue).

Unlike standard failsafes which try to save the vehicle (RTL, Land), **AFS is often designed to "Terminate" the flight** to ensure safety of people on the ground if the vehicle goes rogue.

## Key Concepts

### 1. Flight Termination (`AFS_TERMINATE`)
The core function of AFS. If a critical failure condition is met (RC Loss, GCS Loss, Geofence Breach), the system can be configured to:
*   **Kill Motors:** Immediately stop propulsion.
*   **Move Servos:** Force control surfaces to a "Crash" or "Spin" position (e.g., full rudder, full up elevator) to limit the impact area.
*   **Hardware Pin:** Drive a GPIO pin (`AFS_TERM_PIN`) high/low to trigger an external parachute deployment module or airbag.

### 2. Dual-Link Monitoring
AFS can monitor both the RC link and the GCS (MAVLink) link independently (`AFS_DUAL_LOSS`). It ensures that you always have at least one valid command link.

### 3. Heartbeat Hardware (`AFS_HB_PIN`)
Can output a "heartbeat" signal to an external watchdog timer. If the autopilot freezes, the heartbeat stops, and the external hardware terminates the flight.

## Parameter Breakdown

*   **`AFS_ENABLE`**: Master switch.
*   **`AFS_TERM_ACTION`**: 0=Disable, 1=Terminate immediately on failure.
*   **`AFS_MAN_PIN`**: Input pin for a manual "Kill Switch" from an external receiver.
*   **`AFS_TERM_PIN`**: Output pin to trigger external termination hardware.
*   **`AFS_RC_FAIL_TIME`**: Timeout (seconds) for RC loss before termination.
*   **`AFS_AMSL_LIMIT`**: Hard altitude ceiling (AMSL) for termination.

## Integration Guide

### Typical Setup for FTS
1.  **Enable:** Set `AFS_ENABLE = 1`.
2.  **Define Output:** Set `AFS_TERM_PIN` to the Servo/GPIO connected to your parachute release or ignition kill.
3.  **Define Logic:** Configure `AFS_RC_FAIL_TIME` and `AFS_GCS_TIMEOUT` appropriately.
4.  **Testing:** **REMOVE PROPELLERS.** Use the `AFS.TERMINATE` MAVLink command or simulate a link loss to verify the pin switches state.

## Developer Notes
*   **Library:** `libraries/AP_AdvancedFailsafe`
*   **Vehicle:** Primarily used in **ArduPlane**.
*   **Warning:** Misconfiguring this WILL crash your plane. This is a "destruct" system, not a "save me" system.