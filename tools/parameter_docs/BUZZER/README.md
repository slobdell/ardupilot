# Buzzer Configuration (BUZZER)

## Overview
The **BUZZER** parameter group controls the behavior of the active piezoelectric buzzer connected to the flight controller. The buzzer provides audible feedback for system status (Arming, GPS Lock, Failsafe) and acts as a "Lost Model Alarm."

## Key Concepts

### 1. Volume Control
*   **`BUZZER_VOLUME`**: Sets the PWM duty cycle for the buzzer pin.
    *   **100%:** Full volume.
    *   **20%:** Quiet (good for bench testing).
    *   **0%:** Silent.

## Integration Guide
*   **Too Loud?** If the startup tone is annoying during development, set `BUZZER_VOLUME = 10`.
*   **Tone Control:** Specific tones (Startup, Arming, Warning) are controlled by the `NTF_BUZZ_` (Notify) parameters, not here.

## Developer Notes
*   **Library:** `AP_Notify` (ToneAlarm driver).
*   **Hardware:** Requires an active buzzer (DC driven), not a passive speaker.