---
layout: parameter
name: ATC_RATE_FF_ENAB
display_name: Rate Feedforward Enable
description: Controls whether body-frame rate feedforward is enabled or disabled. This is a critical architectural switch for modern ArduPilot flight stability.
default_value: 1
range: 0 1
units: 
group: ATC
visual_asset_id: atc_rate_ff_enab_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl.cpp#L48
---

# Rate Feedforward Enable (ATC_RATE_FF_ENAB)

## Description
`ATC_RATE_FF_ENAB` is one of the most important architectural switches in ArduPilot. It determines how the drone's "brain" talks to its "muscles."

*   **Enabled (1):** The drone uses **Body-Frame Feedforward**. This means that when you move the stick, the command is instantly translated into a target rotation rate that the drone starts to follow immediately. This is the modern standard for all multirotors.
*   **Disabled (0):** The drone uses **Euler-Angle Lead**. This is a legacy method used in older flight controllers where the drone waits to see an error in its angle before it starts moving the motors.

**WARNING:** For almost all modern drones, this parameter **MUST remain Enabled (1)**. Disabling it will make the drone feel incredibly sluggish, like it's flying in a thick liquid, and it will be unable to handle rapid maneuvers or high winds.

## The Mathematics
When enabled, the controller bypasses the slow error-accumulation of the outer loop for stick inputs. The target rate ($\omega_{target}$) is derived directly from the pilot's stick position and the shaper:

$$ \omega_{target} = \text{Shaper}(\text{Stick\_Pos}, \dots) $$

When disabled, the target rate is purely a function of angle error:

$$ \omega_{target} = k_P \cdot (\text{Angle}_{target} - \text{Angle}_{actual}) $$

## The Engineer's View
This parameter is the `_rate_bf_ff_enabled` member in `AC_AttitudeControl`.

It is a core conditional in every input function (e.g., `input_euler_angle_roll_pitch_yaw`):

```cpp
// AC_AttitudeControl.cpp
if (_rate_bf_ff_enabled) {
    // Modern: Use input shaper and feedforward
    _euler_rate_target.x = input_shaping_angle(...);
    // ...
} else {
    // Legacy: Euler target is simple angle
    _euler_angle_target.x = euler_roll_angle;
    _euler_rate_target.zero();
}
```

By enabling feedforward, ArduPilot allows the **Rate PID** loops to operate with zero-lag on pilot commands, while still using the **Angle Loop** to correct for any deviations from that command. This "Parallel Path" architecture is what gives ArduPilot its legendary stability.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Range:** 0 (Legacy) or 1 (Modern)
*   **Effect of Enabling:** Tighter, more direct stick feel. Much better wind rejection. Required for AutoTune to work correctly.
*   **Effect of Disabling:** "Loose," "Elastic" feel. Drone may overshoot targets significantly.

### Use Case Recommendations
*   **Standard Drone:** **Keep Enabled (1).** 
*   **Legacy Porting:** If you are porting very old code that doesn't support body-frame FF, you might set this to 0, but this is highly discouraged for modern flight.
*   **Debugging:** Only disable (0) if you are trying to isolate a problem with the outer angle loop and want to remove all lead-authority for testing.

### Troubleshooting
*   **Scenario:** I moved my sticks, but it takes nearly a full second for the drone to start leaning.
    *   **Diagnosis:** `ATC_RATE_FF_ENAB` has accidentally been set to 0.
    *   **Fix:** Set to 1.