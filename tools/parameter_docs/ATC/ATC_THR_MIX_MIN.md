---
layout: parameter
name: ATC_THR_MIX_MIN
display_name: Throttle Mix Minimum
description: Controls the priority of attitude control (leveling) over throttle when the drone is at low throttle or landing. Ensures the drone can still level itself even when the motors are nearly off.
default_value: 0.1
range: 0.1 0.25
units: 
group: ATC
visual_asset_id: atc_thr_mix_min_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L297
---

# Throttle Mix Minimum (ATC_THR_MIX_MIN)

## Description
`ATC_THR_MIX_MIN` is a "priority setting" for your drone's motors. It handles the difficult moment of **Landing**.

When you land a drone, you pull the throttle stick to zero. If the drone is tilted slightly as it touches the ground, the flight controller will try to level it by spinning up some motors. However, if the motors spin up too hard while the drone is on the ground, it can create a "bounce" or "ground resonance" that makes the drone flip over. 

`ATC_THR_MIX_MIN` limits how much "authority" the attitude controller has to overrule your low throttle command. 

*   **Low Value (0.1):** The drone prioritizes your throttle command. If you pull the stick to zero, the motors will stay very low, even if the drone is tilted. This makes for safer, "stickier" landings.
*   **High Value (0.25):** The drone prioritizes staying level. Even at zero throttle, it will spin the motors aggressively to stay flat. This can cause the drone to bounce back into the air during a touchdown.

## The Mathematics
The motor mixer calculates a priority ratio ($R$) between attitude correction and vertical lift. `ATC_THR_MIX_MIN` sets the lower bound of this ratio:

$$ \text{MixRatio} = \text{constrain}(\text{Current\_Priority}, \text{THR\_MIX\_MIN}, \text{THR\_MIX\_MAX}) $$

**Effect:** If the drone is landing and the Calculated Priority is 0.05, it will be "boosted" to 0.1 (the minimum). This ensures that at least 10% of the motor authority is always reserved for leveling the drone, regardless of how low the throttle is.

## The Engineer's View
This parameter is the `_thr_mix_min` member in `AC_AttitudeControl_Multi`.

It is used in `AC_AttitudeControl_Multi::update_throttle_rpy_mix()`:

```cpp
// AC_AttitudeControl_Multi.cpp
_throttle_rpy_mix = (1.0f - ratio) * _thr_mix_min + ratio * _thr_mix_max;
```

This dynamic mixing allows the drone to smoothly transition from "High Control" during flight to "Low Authority" during landing, preventing the feedback loops that cause "Ground Wobble."

## Tuning & Behavior
*   **Default Value:** 0.1 (10% Authority) 
*   **Range:** 0.1 - 0.25
*   **Effect of Increasing:** The drone fights harder to stay level during landing. Safer for landing in high wind on a slope.
*   **Effect of Decreasing:** The drone is more likely to stay on the ground once it touches down. Reduces "bouncing."

### Use Case Recommendations
*   **Top-Heavy Drones:** **Increase to 0.15.** Drones with high centers of gravity (e.g., those with tall antennas or top-mounted batteries) are unstable on the ground and need more authority to stay upright during touchdown.
*   **Underpowered Drones:** **Keep at 0.1.** You want the motors to stop as soon as possible to prevent a tip-over.
*   **Autonomous Landing (RTL):** **Keep Default.** 0.1 is the most tested value for reliable auto-landings.

### Troubleshooting
*   **Scenario:** Every time I land, the drone touches the ground and then "jumps" back up 20cm before finally disarming.
    *   **Diagnosis:** `ATC_THR_MIX_MIN` is too high. The drone is over-correcting for the impact and "powering" itself back into the air.
    *   **Fix:** Reduce `ATC_THR_MIX_MIN` to 0.1.