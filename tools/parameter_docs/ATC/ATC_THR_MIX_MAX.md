---
layout: parameter
name: ATC_THR_MIX_MAX
display_name: Throttle Mix Maximum
description: Controls the priority of attitude control (leveling) over throttle when the drone is at high throttle or in active flight. Ensures the drone can still level itself even when the motors are at 100% power.
default_value: 0.5
range: 0.5 0.9
units: 
group: ATC
visual_asset_id: atc_thr_mix_max_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Multi.cpp#L304
---

# Throttle Mix Maximum (ATC_THR_MIX_MAX)

## Description
`ATC_THR_MIX_MAX` handles the most dangerous moment for a flight controller: **Motor Saturation**.

If you punch the throttle to 100% to avoid an obstacle, all your motors spin up to their absolute limit. At that moment, the drone has no "extra" power left to roll or pitch. If a gust of wind hits it, the drone will tilt over and crash because the motors can't spin any faster to correct the attitude.

`ATC_THR_MIX_MAX` solves this by forcing the drone to "sacrifice" some vertical lift to save its attitude. It caps the priority of throttle, ensuring that a certain percentage of motor power is *always* reserved for staying level, even if that means the drone doesn't climb as fast as you asked.

*   **Low Value (0.5):** Very safe. The drone will always keep 50% of its motor range available for attitude control. It will never flip over at full throttle, but its "vertical punch" will feel weak.
*   **High Value (0.9):** Maximum performance. The drone uses 90% of its power for climbing. It will have a massive vertical "pop," but it is at high risk of losing attitude control (and crashing) during that climb.

## The Mathematics
The controller calculates how much "headroom" is needed for the RPY (Roll/Pitch/Yaw) loops. `ATC_THR_MIX_MAX` sets the upper limit for this priority:

$$ \text{Headroom\_Reserved} = \text{MixRatio} \cdot \text{Max\_Authority} $$

**Physical Meaning:** If `ATC_THR_MIX_MAX` is 0.5, and you are at 100% throttle, the flight controller will actually *reduce* the average throttle of all motors to 50% to give the Roll and Pitch loops the room they need to increase/decrease individual motor speeds.

## The Engineer's View
This parameter is the `_thr_mix_max` member in `AC_AttitudeControl_Multi`.

It is enforced in the motor mixer:

```cpp
// AC_AttitudeControl_Multi.cpp
_throttle_rpy_mix_desired = (1.0f - ratio) * _thr_mix_min + ratio * _thr_mix_max;
```

This is the reason why ArduPilot drones sometimes sound like they are "stuttering" or reducing power when you do a high-speed maneuver—the software is dynamically lowering the throttle to ensure it can still meet the roll/pitch torque requirements.

## Tuning & Behavior
*   **Default Value:** 0.5 (50% headroom)
*   **Range:** 0.5 - 0.9
*   **Effect of Increasing:** Much faster vertical acceleration. The drone "rockets" up.
*   **Effect of Decreasing:** Maximum stability. The drone will never lose its level orientation, regardless of how hard you push it.

### Use Case Recommendations
*   **Standard Multirotor:** **Keep Default (0.5).** 50% is a very safe value that prevents "washout" in turns.
*   **Racing Drone:** **Increase to 0.7 - 0.8.** Needed for that "snappy" vertical authority, but requires a very rigid frame and perfectly balanced props.
*   **Heavy Lift / Expensive Payload:** **Decrease to 0.45.** Never sacrifice the safety of the payload for a faster climb rate.

### Troubleshooting
*   **Scenario:** When I do a 100% throttle "punch out," the drone starts to tilt or "tumble" to one side.
    *   **Diagnosis:** Throttle Saturation. The motors are at 100%, and there isn't enough headroom left for the attitude controller to stay level.
    *   **Fix:** Reduce `ATC_THR_MIX_MAX` to 0.5 or 0.45.