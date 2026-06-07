---
layout: parameter
name: RC_FS_MSK
display_name: Servo RC Failsafe Mask
description: Bitmask of scaled passthru output channels which will be set to their trim value during rc failsafe instead of holding their last position before failsafe.
default_value: 0
range: 0 4294967295
units: 
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/SRV_Channel/SRV_Channels.cpp#L231
---

# RC_FS_MSK: Servo RC Failsafe Mask

## Description
Bitmask of scaled passthru output channels which will be set to their trim value during rc failsafe instead of holding their last position before failsafe.

## Values
- **Bitmask:**
  - **Bit 0:** Servo 1
  - **Bit 1:** Servo 2
  - **...**
  - **Bit 31:** Servo 32

- **Default:** 0

## Description
This parameter defines the behavior of "Pass-Through" channels (servos directly controlled by the pilot's RC sticks) when the radio link is lost (RC Failsafe).

- **Default (0):** All pass-through channels will "Hold Last Position." For example, if you were turning right when the signal was lost, the rudder stays right.
- **Enabled Bit:** If a channel's bit is set, that servo will jump to its **TRIM** value (usually center) immediately upon failsafe.
- **Use Case:** Primarily for auxiliary surfaces like flaps or landing gear where you want a predictable, neutral state during an emergency return home, rather than leaving them in a high-drag configuration.

