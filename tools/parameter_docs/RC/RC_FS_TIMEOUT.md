---
layout: parameter
name: RC_FS_TIMEOUT
display_name: RC Failsafe timeout
description: The amount of time (in seconds) that RC signal must be lost before a failsafe action is triggered.
default_value: 1.0
range: 0.5 10.0
units: s
group: RC
visual_asset_id: rc_fs_timeout_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/RC_Channel/RC_Channels_VarInfo.h#L88
---

# RC Failsafe timeout (RC_FS_TIMEOUT)

## Description
`RC_FS_TIMEOUT` defines how long ArduPilot waits after losing contact with your radio receiver before it decides "The pilot is gone" and triggers a failsafe action (like RTL or Land).

A shorter timeout provides faster safety response but may cause "nuisance" failsafes if your radio link is momentarily blocked by an obstacle. A longer timeout allows for more robust connections in noisy environments but delays the automatic return home.

## The Mathematics
The system monitors the "Last Pulse Time" for the RC channels. Failsafe triggers if:
$$ \Delta t_{\text{no\_signal}} > \text{RC\_FS\_TIMEOUT} $$

## The Engineer's View
Defined in `RC_Channels_VarInfo.h` as `_fs_timeout`.
It is primarily used in `ArduCopter/radio.cpp` (and equivalent vehicle files) within the `read_radio()` loop. The timeout applies to both pulse-based failsafes (like SBUS signal loss) and throttle-low failsafes.

## Tuning & Behavior
*   **Default Value:** 1.0 second
*   **Range:** 0.5 to 10.0 seconds
*   **Recommendation:**
    *   **Standard Flight:** Keep at **1.0s**. This is the best balance of safety and robustness.
    *   **Long Range:** You might increase this to **2.0s or 3.0s** if you are flying near the limit of your radio range where "telemetry lost" warnings are frequent.
    *   **Racing:** Set to **0.5s** for the absolute fastest response in a crash or signal loss.