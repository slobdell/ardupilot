# OneShot ESC Configuration (ONESHOT)

## Overview
The **ONESHOT** parameter group (specifically `ONESHOT_MASK`) configures the legacy **OneShot125** and **OneShot42** fast PWM ESC protocols.

OneShot was an intermediate step between standard 490Hz PWM and modern digital DShot. It uses shorter pulse widths to allow the autopilot to send motor updates faster (up to 8kHz) with less latency.

## Key Concepts

### 1. OneShot Mask
Selects which output channels on the flight controller will use the OneShot protocol.
*   **Recommendation:** Modern users should use **DShot** instead, as it is digital and more robust. OneShot is only recommended for legacy hardware that doesn't support DShot.

## Developer Notes
*   **Library:** `libraries/AP_HAL_ChibiOS`.
*   **Selection:** This mask is often set automatically when `MOT_PWM_TYPE` is set to 1 (OneShot) or 2 (OneShot125).