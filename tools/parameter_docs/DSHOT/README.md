# DShot Configuration (DSHOT)

## Overview
The **DSHOT** parameter group (often appearing as `MOT_PWM_TYPE` options or `SERVO_BLH_` in older setups) configures the **DShot** digital motor protocol.

DShot is a digital protocol for ESCs that is faster, more robust against noise, and requires no calibration (unlike PWM/OneShot).

## Key Concepts

### 1. Protocol Speed
DShot comes in varying speeds:
*   **DShot150:** 150 kbit/s. Slowest, most robust against noise/long wires.
*   **DShot300:** 300 kbit/s. Standard.
*   **DShot600:** 600 kbit/s. Fast.
*   **DShot1200:** 1200 kbit/s. Very fast, requires high-quality wiring and F4/F7/H7 processors.

### 2. Bidirectional DShot
Allows the ESC to send RPM telemetry back down the signal wire. This is critical for the **Harmonic Notch Filter**.

## Parameter Breakdown

*   **`DSHOT_RATE`**: 0=Disabled, 150, 300, 600, 1200.
*   **`DSHOT_ESC`**: Bitmask to select which outputs use DShot.

## Integration Guide
1.  **Set Type:** Set `MOT_PWM_TYPE = 4` (DShot150) or `6` (DShot600).
2.  **Enable:** Configure the `SERVOx_FUNCTION` to Motors.
3.  **No Cal:** Do not perform ESC calibration. The endpoints are fixed (1000-2000 digital).

## Developer Notes
*   **Library:** `libraries/AP_HAL_ChibiOS` (RCOutput)
*   **Requirement:** Hardware timer support (DMA). Not all pins on all boards support DShot. Check `hwdef.dat` or the "Alt Config" documentation.