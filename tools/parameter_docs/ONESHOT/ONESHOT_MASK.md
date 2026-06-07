---
layout: parameter
title: ONESHOT_MASK
name: Oneshot output mask
group: ONESHOT
---

# ONESHOT_MASK: Oneshot output mask

## Description
Mask of output channels to use OneShot125 on.

## Values
- **Bitmask:**
  - **Bit 0:** Servo 1
  - **Bit 1:** Servo 2
  - **...**
  - **Bit 15:** Servo 16

- **Default:** 0 (Disabled)

## Description
This parameter enables the **OneShot125** ESC protocol on specific servo output channels.

- **OneShot125:** A faster analog PWM protocol (125-250µs pulse width) compared to standard PWM (1000-2000µs). It provides faster motor updates and is synchronized with the main loop.
- **Usage:** Set the bit corresponding to each motor channel connected to a OneShot-capable ESC.
- **Warning:** Do **not** enable this for standard servos or older ESCs, as the high refresh rate and short pulses will damage them.

## Source Code
[ardupilot/ArduPlane/Parameters.cpp](https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1268)

