---
layout: parameter
name: FOLL_TIMEOUT
display_name: "Follow Mode Data Timeout"
description: "Currently unused/hardcoded. Defines the timeout period for target data loss before Follow mode stops tracking."
default_value: 3000
range: 0 10000
units: "ms"
group: FOLL
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L29
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Follow Mode Data Timeout (FOLL_TIMEOUT)

## Description
This parameter is intended to set the failsafe timeout for Follow Mode. If the drone stops receiving position updates from the target vehicle for this duration, it will stop tracking and potentially switch flight modes or loiter in place.

**CRITICAL NOTE:** As of the current codebase analysis, this parameter does **not exist** in the `AP_Follow` parameter table (`var_info`). The timeout is currently hardcoded to **3000ms (3 seconds)** via the macro `AP_FOLLOW_TIMEOUT_MS`.

## The Mathematics
The logic checks the age of the last valid packet:

$$ T_{now} - T_{last\_update} > 3000ms $$

If this condition is met, `have_target()` returns `false`, causing the vehicle to stop updating its target position.

## The Engineer's View
In `AP_Follow.cpp`, line 29:
```cpp
#define AP_FOLLOW_TIMEOUT_MS    3000    // position estimate timeout after 1 second (comment says 1s, code is 3s)
```
The parameter `FOLL_TIMEOUT` appears in some documentation scaffolds but is not exposed in the `var_info` struct for user configuration. It is effectively a compile-time constant.

## Tuning & Behavior
*   **Default Value:** 3000 (Hardcoded).
*   **Behavior:** If the MAVLink stream from the lead vehicle is interrupted (e.g., telemetry loss), the follower will continue on its last known trajectory for 3 seconds before giving up.
*   **Correction:** Do not attempt to change `FOLL_TIMEOUT` in your Ground Control Station; it will likely not be found or will have no effect.
