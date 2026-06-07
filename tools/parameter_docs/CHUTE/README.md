# Parachute Configuration (CHUTE)

## Overview
The **CHUTE** parameter group configures the emergency **Parachute Release** system. This system acts as a last-resort recovery method to save the vehicle and minimize ground impact energy in the event of a catastrophic failure (e.g., motor loss, mid-air collision, or loss of attitude control).

## Key Concepts

### 1. Automatic Triggering
The parachute can be deployed automatically if the autopilot detects:
*   **Crash:** Vehicle is tumbling or hitting limits.
*   **Critical Sink Rate:** Falling faster than `CHUTE_CRT_SINK`.
*   **Motor Loss:** Requires thrust loss detection to be active.

### 2. Motor Interlock
**Crucial Safety Feature:** When the parachute deploys, the autopilot **IMMEDIATELY kills all motors**. This prevents the props from cutting the parachute lines or entangling the chute.

### 3. Release Mechanism
*   **Servo:** Moves a servo to a specific PWM position to release a latch/pin.
*   **Relay:** Toggles a voltage pin (e.g., for a pyrotechnic charge or solenoid).

## Parameter Breakdown

*   **`CHUTE_ENABLED`**: Master switch.
*   **`CHUTE_TYPE`**: 10=Servo, 11=Relay.
*   **`CHUTE_SERVO_ON` / `OFF`**: PWM positions for deployed/stowed states.
*   **`CHUTE_ALT_MIN`**: Minimum altitude to allow auto-deployment (prevents accidental firing on the ground).
*   **`CHUTE_DELAY_MS`**: Delay between killing motors and firing the chute (allows props to spin down).

## Integration Guide

### Testing (Ground)
1.  **Remove Props.**
2.  Set `CHUTE_ALT_MIN = 0` (temporarily).
3.  Arm the vehicle.
4.  Switch to a mode or flip a switch assigned to `Parachute Release` (RC Option 22).
5.  Verify the motors stop and the servo moves.
6.  **Reset `CHUTE_ALT_MIN` before flight.**

## Developer Notes
*   **Library:** `libraries/AP_Parachute`
*   **Integration:** Tightly coupled with `AP_Motors` to ensure immediate shutdown.