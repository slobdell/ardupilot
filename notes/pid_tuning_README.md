# PID Tuning Process: In-Flight RC-Based Tuning
**Document Version:** 1.0
**Date:** 2025-10-14

## 1.0 Objective

To facilitate rapid and efficient PID tuning of the custom Thrust Vectoring Controller (TVC), we need a method that allows for real-time, in-flight adjustments without relying on a connection to a Ground Control Station (GCS) like Mission Planner.

This document outlines the implementation of a simple, RC-based tuning mode. This mode will allow a pilot to use two spare RC channels (one switch, one knob) to select and adjust the P, I, and D gains of the TVC's control loops directly from their transmitter. The resulting tuned values will be continuously logged over the existing debug UART port for later analysis and implementation.

## 2.0 Requirements

### 2.1 Hardware

1.  **RC Transmitter:** A transmitter with at least two spare, assignable auxiliary channels:
    *   One 3-position switch (to select P, I, or D).
    *   One rotary knob or slider (to adjust the value).
2.  **RC Receiver:** Configured to pass these two channels to the TVC flight controller.

### 2.2 Software

The implementation will be entirely self-contained within the TVC's custom ArduPilot code (`custom_main.cpp` and related files).

## 3.0 Implementation Strategy

The implementation is a straightforward, 4-step process.

### 3.1 Step 1: Add Configuration Constants

In `custom_main.cpp`, we will add the necessary configuration constants to define the tuning mode.

```cpp
// --- IN-FLIGHT TUNING CONFIGURATION ---

// Set to true to enable RC-based PID tuning mode.
// WARNING: This mode bypasses the saved PID gains.
#define PID_TUNING_MODE true

// Define the RC input channels (0-indexed) for tuning.
// Corresponds to RC Channel 9
#define TUNING_SELECTOR_CHANNEL 8
// Corresponds to RC Channel 10
#define TUNING_VALUE_CHANNEL    9

// Define the min/max range for each gain.
// These ranges will be mapped to the 1000-2000us range of the value knob.
const float P_GAIN_MIN = 0.5f;
const float P_GAIN_MAX = 5.0f;

const float I_GAIN_MIN = 0.0f;
const float I_GAIN_MAX = 2.0f;

const float D_GAIN_MIN = 0.0f;
const float D_GAIN_MAX = 0.1f;
```

### 3.2 Step 2: Create State Variables

We need temporary, non-constant variables to hold the tuned gain values in memory. These will be initialized with the default gains from the `tvc_config` struct.

```cpp
// In the global scope of custom_main_ardupilot.cpp

// Temporary state variables to hold the live-tuned PID gains.
static float tuned_pitch_rate_p;
// ... and so on for all P, I, and D gains for both pitch and roll rate controllers.
```

### 3.3 Step 3: Implement the Tuning Logic in `newMain()`

The core logic will be placed inside the `newMain()` loop within `custom_main_ardupilot.cpp`.

```cpp
// Inside the newMain() loop

#if PID_TUNING_MODE
    // Read the selector switch's PWM value
    uint16_t selector_pwm = hal.rcin->read(TUNING_SELECTOR_CHANNEL);
    uint16_t value_pwm = hal.rcin->read(TUNING_VALUE_CHANNEL);

    // Determine which gain is being tuned
    if (selector_pwm < 1300) {
        // Position 1: Tune P Gain
        // Map the 1000-2000us knob value to the P_GAIN range
        tuned_pitch_rate_p = sbus_pwm_to_float(value_pwm, P_GAIN_MIN, P_GAIN_MAX);
        // Also apply to roll for simplicity, or use another switch position
        tuned_roll_rate_p = tuned_pitch_rate_p;

    } else if (selector_pwm < 1700) {
        // Position 2: Tune I Gain
        tuned_pitch_rate_i = sbus_pwm_to_float(value_pwm, I_GAIN_MIN, I_GAIN_MAX);
        tuned_roll_rate_i = tuned_pitch_rate_i;

    } else {
        // Position 3: Tune D Gain
        tuned_pitch_rate_d = sbus_pwm_to_float(value_pwm, D_GAIN_MIN, D_GAIN_MAX);
        tuned_roll_rate_d = tuned_pitch_rate_d;
    }

    // Override the gains in the PID controller objects before they are used
    state.pitch_rate_pid.p(tuned_pitch_rate_p);
    state.pitch_rate_pid.i(tuned_pitch_rate_i);
    state.pitch_rate_pid.d(tuned_pitch_rate_d);
    // ... repeat for the roll_rate_pid ...

#endif

// ... (The rest of the newMain loop continues as normal) ...
```
*(Note: The exact method to set the PID gains, e.g., `state.pitch_rate_pid.p(value)`, depends on the `LinearPIDController` class having a public setter method for each gain.)*

### 3.4 Step 4: Log the Tuned Values

We will add a logging statement to the existing periodic debug output to display the live values.

```cpp
// Inside the periodic logging block in newMain()

#if PID_TUNING_MODE
    // Log the current live-tuned values
    gcs().send_text(MAV_SEVERITY_INFO, "TUNE P:%.4f I:%.4f D:%.4f", tuned_pitch_rate_p, tuned_pitch_rate_i, tuned_pitch_rate_d);
#endif
```

## 4.0 Tuning Workflow

1.  **Enable Mode:** Set `PID_TUNING_MODE` to `true` in the code and flash the TVC.
2.  **Configure Transmitter:** Assign a 3-position switch to Channel 9 and a rotary knob to Channel 10 on the RC transmitter.
3.  **Connect and Fly:** Power on the aircraft and connect the debug UART to a serial monitor.
4.  **Select and Tune:**
    *   Put the selector switch in the first position to select the **P gain**.
    *   Take off and hover.
    *   Adjust the knob while observing the aircraft's response to stick inputs.
    *   Land, move the switch to the second position to tune the **I gain**, and repeat.
    *   Land, move the switch to the third position to tune the **D gain**, and repeat.
5.  **Record Values:** Once the optimal flight characteristics are achieved, read the final, stable values from the serial monitor log (e.g., "TUNE P:1.8500 I:0.5000 D:0.0150").
6.  **Implement and Disable:**
    *   Set `PID_TUNING_MODE` back to `false`.
    *   Hardcode the recorded optimal values into the main `tvc_config` struct.
    *   Re-flash the final firmware.

This process provides a simple, fast, and effective workflow for tuning the custom TVC controller directly in the field.
