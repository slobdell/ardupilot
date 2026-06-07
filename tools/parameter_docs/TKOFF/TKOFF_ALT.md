---
layout: parameter
name: TKOFF_ALT
display_name: Takeoff Target Altitude
description: The target altitude (in meters) to reach during an automatic takeoff.
default_value: 50
range: 10 1000
units: m
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/mode_takeoff.cpp#L16
---

# Takeoff Target Altitude (TKOFF_ALT)

## Description
`TKOFF_ALT` defines the "Destination Height" for an automatic plane takeoff. 

When you trigger a takeoff mission (e.g., via a catapult or hand-launch in AUTO mode), the plane will climb at a steady angle until it reaches this specific height. Once this altitude is reached, the takeoff is considered complete, and the autopilot will move to the next waypoint in your mission.

*   **Default Value:** 50 meters.
*   **Units:** Meters above the takeoff point.

## The Engineer's View
Defined in `ArduPlane/mode_takeoff.cpp`. 
This parameter is used by the `ModeTakeoff` state machine. While the altitude is below `TKOFF_ALT`, the system enforces specific pitch and roll limits (`TKOFF_LVL_ALT`, `TKOFF_LVL_PITCH`) to ensure a safe, stable climb-out.

```cpp
// ArduPlane/mode_takeoff.cpp
AP_GROUPINFO("ALT", 1, ModeTakeoff, target_alt, 50),
```

The climb logic is typically handled by the **TECS (Total Energy Control System)**, which manages throttle and pitch together to maintain the requested climb rate and airspeed.

## Tuning & Behavior
*   **Default Value:** 50 m.
*   **Effect of Increasing:** The drone spends more time in the "Takeoff" protected state. Safer for clearing tall trees or buildings around your launch site.
*   **Effect of Decreasing:** The drone transitions to mission navigation sooner.

### Use Case Recommendations
*   **Small Field (Tight Space):** **Increase to 100m.** Ensure you have plenty of height before the drone tries to bank and turn toward the first waypoint.
*   **Large Open Area:** **Keep at 50m.** Standard value provides a safe buffer for most airframes.
*   **Long-Range Mapping:** **Set to 50m.** Allows the drone to get on track as quickly as possible to maximize efficiency.