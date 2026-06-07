---
layout: parameter
name: TRQD_SLEW_TIME
display_name: Torqeedo Throttle Slew Time
description: The minimum time (in seconds) allowed for the motor to ramp from 0% to 100% throttle.
default_value: 2.0
range: 0 5.0
units: s
group: TRQD
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Torqeedo/AP_Torqeedo_Params.cpp#L54
---

# Torqeedo Throttle Slew Time (TRQD_SLEW_TIME)

## Description
`TRQD_SLEW_TIME` ensures smooth power delivery to the **Torqeedo** motor.

Large electric boat motors generate massive torque. If the autopilot "slams" the throttle from 0 to 100% instantly, it can cause the boat to lurch, put excessive strain on the transom, or even trigger a fuse/breaker due to the massive current surge. This parameter limits how fast the throttle can increase.

*   **Higher Value (e.g. 5.0):** Very slow, majestic ramp-up.
*   **Lower Value (e.g. 0.5):** Very aggressive, snappy response.
*   **0:** (Not Recommended). Instantaneous response.

## Tuning & Behavior
*   **Default:** 2.0 seconds.
*   **Recommendation:** Leave at **2.0** or higher for large hulls to ensure mechanical longevity.
*   **Note:** This only limits the *increase* in throttle; for safety, throttle can always be *decreased* much faster.