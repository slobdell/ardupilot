---
layout: parameter
name: Q_ENABLE
display_name: Enable QuadPlane
description: Master switch to enable VTOL (Vertical Takeoff and Landing) functionality on a fixed-wing aircraft.
default_value: 0
range: 0 2
units: 
group: Q
visual_asset_id: q_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L15
---

# Enable QuadPlane (Q_ENABLE)

## Description
`Q_ENABLE` transforms a standard ArduPlane installation into a **QuadPlane**. 

When enabled, the autopilot allocates memory for the multicopter flight controllers (Attitude, Position, Motors) and mixes the output of vertical lift motors with the forward flight control surfaces.

*   **0: Disable.** The aircraft flies as a standard fixed-wing plane.
*   **1: Enable.** QuadPlane features are active. You can switch between VTOL modes (QLoiter, QHover) and Fixed-Wing modes (FBWA, Auto).
*   **2: Enable VTOL AUTO.** Same as 1, but forces `AUTO` missions to default to VTOL behavior unless specified otherwise.

## The Engineer's View
Defined in `ArduPlane/quadplane.cpp`. 
Changing this parameter triggers a massive reallocation of internal objects (Motors, PID controllers, WPNav) during the next boot. 
**Reboot Required:** You MUST reboot the flight controller after changing this parameter for the VTOL motors to function.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Recommendation:** Set to **1** for any hybrid VTOL aircraft.
*   **Safety:** Ensure your frame configuration (`Q_FRAME_CLASS`, `Q_FRAME_TYPE`) is set correctly *before* plugging in the battery after enabling this.