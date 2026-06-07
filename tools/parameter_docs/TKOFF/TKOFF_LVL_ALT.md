---
layout: parameter
name: TKOFF_LVL_ALT
display_name: Takeoff Level-Flight Altitude
description: The altitude above which the aircraft transitions from restricted roll limits to full flight envelope limits during takeoff.
default_value: 10
range: 0 50
units: m
group: TKOFF
visual_asset_id: takeoff_sequence_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/mode_takeoff.cpp#L25
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/takeoff.cpp#L149
---

# Takeoff Level-Flight Altitude (TKOFF_LVL_ALT)

## Description
`TKOFF_LVL_ALT` is a safety buffer that prevents your airplane from banking too steeply when it is close to the ground. 

When a plane first takes off, it is often flying slowly and lacks full stability. If the drone tried to make a sharp turn while only 2 meters high, it could strike a wing on the ground. `TKOFF_LVL_ALT` keeps the wings level (or nearly level) until the drone has reached a safe "Staging Altitude."

*   **Default Value:** 10 meters.
*   **Units:** Meters above the takeoff point.

## The Mathematics
ArduPilot uses a dual-threshold scaling logic for the maximum allowed bank angle ($\phi_{max}$) during takeoff:

1.  **Below `TKOFF_LVL_ALT`:** Roll is restricted to `LEVEL_ROLL_LIMIT` (typically 5-10 degrees).
2.  **Above `TKOFF_LVL_ALT` x 3:** Roll is allowed up to the full `ROLL_LIMIT_DEG` (typically 45 degrees).
3.  **In Between:** The limit is linearly interpolated.

$$ \text{Active\_Roll\_Limit} = \text{lerp}(\text{LEVEL\_ROLL}, \text{ROLL\_LIMIT}, \text{Alt}, \text{LVL\_ALT}, \text{LVL\_ALT} \times 3) $$

## The Engineer's View
Defined in `ArduPlane/takeoff.cpp` inside `takeoff_calc_roll()`. 

```cpp
// ArduPlane/takeoff.cpp
const float lim1 = MAX(mode_takeoff.level_alt, 0);
const float lim2 = MIN(mode_takeoff.level_alt*3, mode_takeoff.target_alt);
const float current_baro_alt = barometer.get_altitude();

takeoff_roll_limit_cd = linear_interpolate(g.level_roll_limit*100, roll_limit_cd, 
                                current_baro_alt,
                                auto_state.baro_takeoff_alt+lim1, auto_state.baro_takeoff_alt+lim2);
```

This logic ensures a smooth transition of control authority. As the plane gains altitude and clears ground obstacles, it is granted more freedom to maneuver toward its mission path.

## Tuning & Behavior
*   **Default Value:** 10 m.
*   **Effect of Increasing:** Safer, but the drone will take longer to correct its heading if it was thrown off-track.
*   **Effect of Decreasing:** Allows earlier turning. Only recommended for small, high-power drones in tight spaces.

### Use Case Recommendations
*   **Large Scale / Heavy Planes:** **Increase to 20m.** Heavy planes have more momentum and take longer to stabilize; keeping the wings level longer prevents tip-stalls.
*   **Windy Sites:** **Increase to 15m.** Prevents a gust from flipping the plane into the ground before it has enough altitude to recover.
*   **Standard build:** **Keep at 10m.**