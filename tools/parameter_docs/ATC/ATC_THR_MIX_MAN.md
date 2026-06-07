---
layout: parameter
name: ATC_THR_MIX_MAN
display_name: Throttle Mix Manual
description: Controls the priority of attitude control (leveling) over throttle specifically during manual flight (Stabilize/Acro).
default_value: 0.1
range: 0.1 0.9
units: 
group: ATC
visual_asset_id: atc_thr_mix_man_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L311
---

# Throttle Mix Manual (ATC_THR_MIX_MAN)

## Description
`ATC_THR_MIX_MAN` is the manual counterpart to `ATC_THR_MIX_MAX`. It defines how much authority the drone's stabilization loops have when you are flying in "Old School" manual modes like **Stabilize** or **Acro**.

In manual modes, the pilot is in direct control of the throttle. If you push the stick to 100%, you expect 100% power. However, the drone still needs to stay level. `ATC_THR_MIX_MAN` determines how much the drone should "ignore" your 100% throttle request to ensure it doesn't flip over.

*   **Low Value (0.1):** The drone prioritizes **Pilot Intent**. If you push 100% throttle, you get almost 100% throttle. This makes the drone feel extremely powerful, but it may "wash out" (lose control) during full-throttle climbs.
*   **High Value (0.5+):** The drone prioritizes **Stability**. It will automatically lower your effective throttle to ensure it has enough motor range to keep the attitude perfectly locked.

## The Mathematics
The Mixing Ratio ($M$) for manual modes is directly set by this parameter:

$$ \text{Effective\_Throttle} = \text{constrain}(\text{Pilot\_Throttle}, \text{Min}, \text{Max} - \text{M} \cdot \text{Headroom}) $$

**Physical Meaning:** A value of 0.5 means that even if you hold full throttle, the drone will reduce its average lift by 50% if that's what it takes to stop it from tilting or tumbling.

## The Engineer's View
This parameter is the `_thr_mix_man` member in `AC_AttitudeControl_Multi`.

It is particularly important for high-power-to-weight vehicles (like 5-inch racing quads). On these vehicles, the motors are so powerful that even a 10% torque difference can create a massive roll rate. If `ATC_THR_MIX_MAN` is too low, the drone will "torque roll" (unintentionally tilt) when you floor the throttle.

## Tuning & Behavior
*   **Default Value:** 0.1 (10% reservation)
*   **Range:** 0.1 - 0.9
*   **Effect of Increasing:** Much more stable full-throttle climbs. Drone feels more "locked" during punch-outs.
*   **Effect of Decreasing:** Maximum vertical power. Drone feels "raw" and "unfiltered."

### Use Case Recommendations
*   **Racing Drone (Standard Setup):** **Increase to 0.5.** Provides the best balance between speed and control during high-speed gate navigation.
*   **FPV Freestyle:** **Keep at 0.1.** Freestyle pilots often use "Air Mode" (which handles mixing differently) and prefer the raw power of the motors for maneuvers like "Matty Flips."
*   **Heavy Cargo Drone (Manual Recovery):** **Increase to 0.5.** If you ever have to switch to manual to save a heavy drone, you want it to prioritize staying level above all else.

### Troubleshooting
*   **Scenario:** In Stabilize mode, if I punch the throttle, the drone "climbs" but also tilts violently to the right.
    *   **Diagnosis:** Torque Roll. The motors on the left can't spin any faster to correct the roll because they are already at 100%.
    *   **Fix:** Increase `ATC_THR_MIX_MAN` to 0.5.
*   **Scenario:** My drone feels "weak" in manual mode, even at 100% throttle.
    *   **Diagnosis:** `ATC_THR_MIX_MAN` is too high, and the drone is excessively reserving power for stability.
    *   **Fix:** Reduce `ATC_THR_MIX_MAN` to 0.2.