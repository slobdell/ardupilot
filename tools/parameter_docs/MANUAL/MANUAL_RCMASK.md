---
layout: parameter
name: MANUAL_RCMASK
display_name: Manual R/C Pass-Through Mask
description: A bitmask of RC channels that should bypass all autopilot processing and be passed directly to the servos when in MANUAL mode.
default_value: 0
range: 0 65535
units: Bitmask
group: MANUAL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L1097
---

# Manual R/C Pass-Through Mask (MANUAL_RCMASK)

## Description
`MANUAL_RCMASK` allows advanced pilots to use "Old School" transmitter mixing when flying in **MANUAL** mode.

Normally, even in MANUAL mode, ArduPilot performs some processing on your stick inputs to map them to the correct outputs (e.g., mixing Elevons). By setting bits in this mask, you tell the autopilot to completely step out of the way for specific channels. Your transmitter's mixed signals will flow directly to the servos as if the flight controller wasn't there.

*   **0 (Default):** Normal ArduPilot behavior.
*   **Bitmask:** Each bit represents a channel (Bit 0 = Chan 1, Bit 1 = Chan 2, etc.).

## Tuning & Behavior
*   **Warning:** This is an **expert-only** parameter. If your transmitter mix is different from your autopilot's stabilized mix (e.g. FBWA), the plane will behave differently depending on the mode.
*   **Safety:** Ensure your "Failsafe" behavior is still correct. If the autopilot takes over during a failsafe, it will use its *own* mixing, not your transmitter's.