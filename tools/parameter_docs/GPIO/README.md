# GPIO Configuration (GPIO)

## Overview
The **GPIO** parameter group (specifically `GPIO_MASK` or `SERVO_GPIO_MASK`) configures the repurposing of motor/servo outputs for **General Purpose Input/Output (GPIO)** functions.

By default, the pins on your flight controller's servo rail are configured to output high-frequency PWM or DShot signals for motors. This group allows you to "re-task" some of those pins to be simple on/off digital switches (3.3V high/low).

## Key Concepts

### 1. Servo to GPIO Mapping
Pins are assigned using a bitmask. When a bit is set for a specific output channel, the PWM timer for that pin is disabled, and it is handed over to the GPIO controller.
*   **Common Uses:**
    *   Controlling a Relay.
    *   Firing a Camera Shutter.
    *   Toggling external LED strips.
    *   Input for a push-button (see `BTN` group).

## Parameter Breakdown

*   **`GPIO_MASK`**: Bitmask of pins to convert to GPIO.
    *   **Bit 0:** Servo 1.
    *   **Bit 5:** Servo 6.
    *   **Value 32 (2^5):** Converts AUX 1 (on many boards) to GPIO.

## Integration Guide
1.  **Select Pin:** Identify which servo pin you want to use.
2.  **Enable:** Set the corresponding bit in `GPIO_MASK`.
3.  **Assign Function:** Use `RELAY_PIN` or `CAM_FEEDBAK_PIN` to reference the digital ID of that pin.

## Developer Notes
*   **Library:** `libraries/SRV_Channel`.
*   **Hardware:** Not all pins on all boards can be converted (depends on the microcontroller's timer allocation). Refer to your board's "Mapping" page on the ArduPilot Wiki.