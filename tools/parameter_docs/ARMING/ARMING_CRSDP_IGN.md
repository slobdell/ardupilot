---
layout: parameter
name: ARMING_CRSDP_IGN
display_name: Disable CrashDump Arming check
description: Must have value "1" if crashdump data is present on the system, or a prearm failure will be raised. Do not set this parameter unless the risks of doing so are fully understood.
default_value: 0
range: 0 1
units: 
group: ARMING
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Arming/AP_Arming.cpp
---

# Disable CrashDump Arming check (ARMING_CRSDP_IGN)

## Description
A safety "acknowledgment" required if the flight controller previously suffered a hard crash resulting in a crash dump. Arming is blocked until the user acknowledges the crash by setting this to 1.

## Tuning & Behavior
*   **Default Value:** 0
*   **Values:** 0:Check Active, 1:Acknowledge/Ignore
*   **Setting this to 1 allows arming even if crash data is present.**