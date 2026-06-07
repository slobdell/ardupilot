---
layout: parameter
name: TMODE_FLAGS
display_name: Toy Mode Flags
description: A bitmask of options to customize the simplified control behavior of Toy Mode.
default_value: 0
range: 0 15
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.h#L66
---

# Toy Mode Flags (TMODE_FLAGS)

## Description
`TMODE_FLAGS` toggles specific "Ease of Use" behaviors.

*   **Bit 0 (1): Disarm on Low Throttle.** Automatically disarms the drone if the throttle is held at minimum for a few seconds.
*   **Bit 1 (2): Arm on High Throttle.** Allows arming the motors by simply pushing the throttle stick up (Auto-Takeoff style).
*   **Bit 2 (4): Upgrade to Loiter.** Automatically switches from `AltHold` to `Loiter` once a solid GPS fix is acquired.
*   **Bit 3 (8): RTL Cancel.** Cancels an automatic Return-to-Launch if the pilot provides a large stick input.