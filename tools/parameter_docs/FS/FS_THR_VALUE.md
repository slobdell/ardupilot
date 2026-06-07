---
layout: parameter
name: FS_THR_VALUE
display_name: Throttle Failsafe Threshold
description: The PWM level on the throttle channel below which a radio failsafe is triggered.
default_value: 910
range: 910 1100
units: PWM
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/Rover/Parameters.cpp#L138
---

# Throttle Failsafe Threshold (FS_THR_VALUE)

## Description
`FS_THR_VALUE` sets the "Alarm Trigger" for your radio connection.

Most RC receivers are configured to pull the throttle channel to a very low value (e.g. 900) if the link to the transmitter is lost. If the autopilot sees the throttle signal drop below this parameter's value, it immediately triggers a Failsafe action (like RTL or Hold).

## Tuning & Behavior
*   **Default:** 910.
*   **Setup:**
    1.  Check your normal throttle range in the GCS (usually 1100 to 1900).
    2.  Turn off your transmitter and see what the throttle value drops to.
    3.  Set `FS_THR_VALUE` to at least **10 units above** that value, but well below your normal minimum throttle (e.g. if transmitter-off is 900, set this to 910).
*   **Warning:** If set too high (e.g. 1150), the drone might trigger a failsafe even when you just pull the stick to idle.