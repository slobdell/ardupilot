# SFML Joystick Configuration (SF)

## Overview
The **SF** parameter group (specifically `SF_JS_AXISx`) is a **SITL-only** tool used to map physical USB Gamepads or Joysticks to the simulator using the **SFML** library.

## Key Concepts

### 1. Direct Control
When developers want to test flight modes using a real controller rather than keyboard commands or GCS sliders, they use the SFML backend to pipe the USB HID data directly into the simulated RC input stack.
*   **`SF_JS_AXIS1`..`8`**: Maps physical joystick axes (0, 1, 2...) to virtual RC channels (Throttle, Roll, etc.).

## Developer Notes
*   **Library:** `libraries/SITL`.
*   **Requirement:** Requires the autopilot to be compiled with `SFML` support.