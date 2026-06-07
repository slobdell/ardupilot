---
layout: parameter
name: RC_SPEED
display_name: RC output speed in Hz
description: Defines the PWM update rate (frequency) for standard ESCs and servos.
default_value: 490
range: 50 490
units: Hz
group: RC
visual_asset_id: rc_speed_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L916
---

# RC output speed in Hz (RC_SPEED)

## Description
`RC_SPEED` determines how often the flight controller sends a new position update to your ESCs and servos when using standard **PWM** signaling.

*   **Standard Servos:** Usually require **50Hz**. Higher values can burn them out.
*   **Digital Servos:** Can often handle **250Hz - 330Hz**.
*   **Standard ESCs:** Usually run at **490Hz** for fast response.

**Note:** This parameter has no effect if you are using digital protocols like **DShot**. DShot speed is determined by `MOT_PWM_TYPE` and the main loop rate.

## The Mathematics
The frequency $f$ in Hz determines the period $T$ between pulses:
$$ T = \frac{1}{f} $$

At 490Hz, a new command is sent every **2.04 milliseconds**. At 50Hz, a command is sent every **20 milliseconds**. Lower period (higher frequency) means lower latency and better stabilization.

## The Engineer's View
Used during the hardware initialization of the PWM timer groups. 
On most boards, outputs are grouped (e.g., Pins 1-4 share a timer). If you set `RC_SPEED` to 490Hz for your motors on Pin 1, any servo connected to Pin 4 must also be able to handle 490Hz. If it can't, you must move the servo to a different timer group.

## Tuning & Behavior
*   **Default Value:** 490 Hz (Optimized for multicopter ESCs)
*   **Recommendation:**
    *   **Multicopters (Standard ESCs):** Keep at **490Hz**.
    *   **Planes (Analog Servos):** Set to **50Hz**.
    *   **Helicopters (Digital Cyclic Servos):** Set to **125Hz or 250Hz** (check servo specs).