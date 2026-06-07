---
layout: parameter
name: TKOFF_OPTIONS
display_name: Takeoff Options
description: Bitmask to enable specialized behaviors for automatic takeoff.
default_value: 0
range: 0 1
units: 
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L1254
---

# Takeoff Options (TKOFF_OPTIONS)

## Description
`TKOFF_OPTIONS` is a bitmask that selects how "Smart" the throttle is during takeoff.

Normally, ArduPilot just pins the throttle at `THR_MAX` during a takeoff to ensure the plane doesn't fall. However, high-power modern planes sometimes don't need full power for the entire climb-out. This parameter allows the plane to use its speed sensor to modulate the throttle.

**Key Bits:**
*   **Bit 0 (1): Use TECS Variable Throttle.**
    If enabled, the plane will not just "Blast" the motors. Instead, it will use the Total Energy Control System (TECS) to balance speed and height. It will reduce throttle if the plane is already exceeding its target climb rate. **Only use this if you have a well-calibrated airspeed sensor.**

## The Engineer's View
If Bit 0 is **Unset (0)**: The autopilot forces `THR_MAX` (or `TKOFF_THR_MAX`) for the duration of the takeoff. This is the safest default.
If Bit 0 is **Set (1)**: The `TECS` controller is allowed to calculate a throttle command between `THR_MIN` and `THR_MAX` based on the energy balance.

## Tuning & Behavior
*   **Default Value:** 0 (Full throttle takeoff).
*   **Recommendation:** Keep at **0** for most users. 
*   **Advanced:** Use **1** for high-efficiency gliders that would overspeed if full power was applied during the entire climb-out.