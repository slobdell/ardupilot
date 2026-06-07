---
layout: parameter
name: FS_SHORT_TIMEOUT
display_name: Short Failsafe Timeout
description: The time (in seconds) of lost RC signal before a Short Failsafe is triggered.
default_value: 1.5
range: 1 5
units: s
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L474
---

# Short Failsafe Timeout (FS_SHORT_TIMEOUT)

## Description
`FS_SHORT_TIMEOUT` defines the delay before the autopilot admits the radio signal is truly gone. 

It is designed to filter out "Micro-Glitches" caused by local interference or signal multipathing. 

*   **Standard Setting:** 1.5 seconds.

## Tuning & Behavior
*   **Default:** 1.5.
*   **Usage:** If your link is very "choppy" but you still want manual control, you can increase this to **2.0s** or **3.0s**, but be aware that the drone will keep its last RC inputs during this time.