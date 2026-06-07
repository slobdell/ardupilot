---
layout: parameter
name: WPNAV_TER_MARGIN
display_name: Terrain Following Margin
description: Defines the safety buffer (in meters) when using the internal Terrain Database for altitude control. Prevents the drone from flying too close to trees or buildings that aren't perfectly represented in the map data.
default_value: 10.0
range: 1 100
units: m
group: WPNAV
visual_asset_id: wpnav_ter_margin_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L93
---

# Terrain Following Margin (WPNAV_TER_MARGIN)

## Description
`WPNAV_TER_MARGIN` is the "safety cushion" for drones using a digital map to stay away from the ground.

ArduPilot can maintain its altitude by downloading a **Terrain Database** (SRTM data) which contains the elevation of the entire earth. However, this data is often low-resolution (typically 30-90 meters per pixel) and does not include objects like tall trees, power lines, or new buildings. 

`WPNAV_TER_MARGIN` adds a fixed vertical offset to your mission altitude to ensure you clear these unknown obstacles.

*   **Low Value (e.g. 2m):** Extremely risky. The drone will follow the ground map precisely, but even a small tree or a mistake in the map data will cause a crash.
*   **High Value (e.g. 20m):** Very safe. The drone stays well above any potential unmapped obstacles.
*   **Default (10m):** A robust setting for most cross-country autonomous missions.

## The Mathematics
The target altitude ($Z_{target}$) is calculated by summing the Terrain Elevation ($E$), the Mission Altitude ($A$), and the Margin ($M$):

$$ Z_{target} = E_{database} + A_{mission} + \text{WPNAV\_TER\_MARGIN} $$

**Example:** If you set a mission altitude of 50 meters, and the map says the hill is 100 meters high, the drone will fly at an absolute height of 160 meters ($100 + 50 + 10$).

## The Engineer's View
This parameter is the `_terrain_margin` member in `AC_WPNav`.

It is applied in the altitude calculation logic. One critical technical detail is that **Terrain Margin is only used when the Rangefinder is NOT available or is out of range**. If you have a Lidar sensor and it sees the ground, ArduPilot will prioritize the real sensor data and ignore the `WPNAV_TER_MARGIN`.

## Tuning & Behavior
*   **Default Value:** 10.0 m
*   **Range:** 1.0 - 100.0 m
*   **Effect of Increasing:** Safer autonomous missions. Drone stays higher above potential obstacles.
*   **Effect of Decreasing:** Drone flies closer to the terrain. Better for low-level tactical or inspection flight.

### Use Case Recommendations
*   **Long-Distance BVLOS:** **Increase to 20m.** You cannot see the drone, so you must assume the map data might be old or inaccurate.
*   **Copter Mapping (Flat Area):** **Keep Default (10m).** 
*   **Precision Low-Level Flight:** **Decrease to 5m.** Only do this if you have visually confirmed there are no unmapped obstacles in the path.

### Troubleshooting
*   **Scenario:** Drone "climbs" unexpectedly during a mission over a flat desert.
    *   **Diagnosis:** The terrain database thinks the ground is higher than it actually is.
    *   **Fix:** Reduce `WPNAV_TER_MARGIN` or switch to a high-accuracy custom terrain map.