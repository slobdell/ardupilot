---
layout: parameter
name: RC_OVERRIDE_TIME
display_name: RC Override Timeout
description: The time (in seconds) after which MAVLink RC overrides expire and control returns to the radio receiver.
default_value: 3.0
range: 0 120
units: s
group: RC
visual_asset_id: rc_options_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/RC_Channel/RC_Channels_VarInfo.h#L97
---

# RC Override Timeout (RC_OVERRIDE_TIME)

## Description
`RC_OVERRIDE_TIME` is a safety timer for GCS/Companion Computer control.

If you control your drone using a Joystick plugged into Mission Planner, or via a Python script sending `RC_CHANNELS_OVERRIDE` messages, this timer determines what happens if that computer crashes or the telemetry link dies.

*   **3.0s (Default):** If no override message is received for 3 seconds, the autopilot ignores the stale overrides and gives control back to the physical RC Receiver.
*   **0.0:** Overrides are ignored immediately (effectively disables overrides).
*   **-1.0:** Infinite timeout. The drone will hold the last received command forever (Danger!).

## The Mathematics
$$ \text{Active} = (t_{now} - t_{last\_msg}) < \text{RC\_OVERRIDE\_TIME} $$

## The Engineer's View
Defined in `RC_Channels_VarInfo.h` as `_override_timeout`.
This timeout applies to **all** channels simultaneously.

## Tuning & Behavior
*   **Default Value:** 3.0s
*   **Recommendation:**
    *   **Joystick Flying:** Set to **1.0s** for faster safety handover if the link drops.
    *   **Companion Computer:** Set to **0.5s** to ensure the drone doesn't "hang" on an old command if the script crashes.
