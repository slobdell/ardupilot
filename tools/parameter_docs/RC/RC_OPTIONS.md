---
layout: parameter
name: RC_OPTIONS
display_name: RC options
description: Global configuration bitmask for RC input behavior.
default_value: 32
range: 0 16383
units: 
group: RC
visual_asset_id: rc_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/RC_Channel/RC_Channels_VarInfo.h#L77
---

# RC options (RC_OPTIONS)

## Description
`RC_OPTIONS` is a bitmask used to enable specialized behaviors for your radio control link. It handles things like MAVLink overrides, Link Quality (LQ) sensing, and protocol-specific tweaks.

**Key Bits:**
*   **Bit 0 (1): Ignore RC Receiver.** Effectively disables the radio input.
*   **Bit 1 (2): Ignore MAVLink Overrides.** Prevents GCS or companion computers from injecting "fake" RC signals.
*   **Bit 5 (32): Arming check throttle for 0 input.** (Enabled by Default). Requires the throttle to be zeroed before the drone will arm.
*   **Bit 13 (8192): Use 420kbaud for ELRS.** Required for standard ExpressLRS setups on modern flight controllers to avoid synchronization errors.

## The Mathematics
$$ \text{Active Options} = \sum 2^i \cdot b_i $$

## The Engineer's View
Defined in `RC_Channels_VarInfo.h`.
Commonly set during initial configuration. For example, many ExpressLRS users will have `RC_OPTIONS` set to **8192** (Bit 13) or **8736** (Bits 5, 8, 9, 13).

## Tuning & Behavior
*   **Default Value:** 32 (Arming check for 0 throttle).
*   **Recommendation:**
    *   **ELRS Users:** Ensure Bit 13 (8192) is set.
    *   **Joystick Users (GCS):** Ensure Bit 1 (2) is NOT set, otherwise MAVLink joysticks won't work.
    *   **Companion Computers:** If your drone is controlled via Python/ROS, you might want to set Bit 1 (2) to ensure the radio doesn't override your script during autonomous flight (or vice-versa).