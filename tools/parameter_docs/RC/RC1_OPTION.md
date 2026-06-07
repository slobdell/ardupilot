---
layout: parameter
name: RC1_OPTION
display_name: RC Input Channel 1 Auxiliary Option
description: Assigns a specialized function (like a switch) to this RC channel.
default_value: 0
range: 0 300
units: 
group: RC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/RC_Channel/RC_Channel.cpp#L109
---

# RC Input Channel 1 Auxiliary Option (RC1_OPTION)

## Description
`RC1_OPTION` allows you to turn a radio channel into a "Function Switch." 

While channels 1-4 are usually reserved for flight axes (Roll, Pitch, Throttle, Yaw), channels 5-16 can be used to trigger features like "Return to Launch," "Arm/Disarm," "AutoTune," or "Camera Trigger."

*   **0: Do Nothing.**
*   **7: RTL.**
*   **300+: Lua Script Trigger.**