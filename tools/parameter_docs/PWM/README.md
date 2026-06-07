# PWM Configuration (PWM)

## Overview
The **PWM** parameter group (specifically `PWM_FREQ` or `MOT_PWM_FREQ`) configures the physical output frequency of the **Pulse Width Modulation** signals.

## Key Concepts

### 1. Output Rate
*   **`PWM_FREQ`**: Defines how many times per second (Hz) the motor or servo position is updated.
    *   **50Hz:** Standard for legacy analog servos.
    *   **490Hz:** High-speed standard for most digital ESCs.
    *   **16,000Hz+:** Ultra-high frequency used for brushed motors to prevent the audible "whine."

## Integration Guide
*   **Warning:** Do not set a high frequency (e.g., 400Hz) if you are using old analog servos; they will overheat and burn out. Digital servos can usually handle 333Hz or more.

## Developer Notes
*   **Library:** `libraries/AP_HAL/RCOutput`.
*   **Scope:** This is often a global setting, but many boards allow setting different frequencies for different "Groups" of pins.