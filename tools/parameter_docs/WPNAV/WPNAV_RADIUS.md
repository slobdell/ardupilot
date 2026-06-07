---
layout: parameter
name: WPNAV_RADIUS
display_name: Waypoint Hit Radius
description: Defines the distance from a waypoint (in cm) that the drone must reach before it considers the waypoint "Hit" and continues to the next mission item.
default_value: 200
range: 10 1000
units: cm
group: WPNAV
visual_asset_id: wpnav_radius_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L34
---

# Waypoint Hit Radius (WPNAV_RADIUS)

## Description
`WPNAV_RADIUS` defines the "bullseye" size for your autonomous missions. It tells the drone exactly how close it needs to get to a waypoint before it can move on to the next one.

*   **Small Radius (e.g. 50cm):** The drone will be extremely precise. It will slow down almost to a hover to ensure it crosses the exact coordinate. This makes the mission very accurate but "jerky" as the drone stops at every point.
*   **Large Radius (e.g. 500cm):** The drone will "fly past" the waypoints in a smooth, flowing curve. It doesn't need to reach the exact center, so it can maintain its speed. This is known as **Corner Cutting**.

**Recommendation:** For standard mapping, a radius of **200 (2 meters)** is ideal. For precision delivery or drop-off, reduce to **50 - 100**.

## The Mathematics
The path planner constantly monitors the 2D distance ($d$) between the current EKF position and the waypoint coordinate:

$$ d = \sqrt{(X_{target} - X_{actual})^2 + (Y_{target} - Y_{actual})^2} $$

A waypoint transition is triggered when:
$$ d < \text{WPNAV\_RADIUS} $$

**Spline Interaction:** If you are using "Spline" waypoints, this parameter is less critical because the drone follows a pre-calculated curve. However, for standard "Waypoints," this parameter determines the smoothness of the turns.

## The Engineer's View
This parameter is the `_wp_radius_cm` member in `AC_WPNav`.

It is used in `AC_WPNav::check_wp_hit()`. A critical engineering detail is that **higher speeds require larger radii**. If the drone is flying at 15 m/s, it may physically be unable to turn tight enough to stay within a 2-meter radius. In this case, the drone will circle the waypoint (Toilet Bowling) trying to get inside the radius.

```cpp
// AC_WPNav.cpp
// Logic for waypoint transition based on _wp_radius_cm.
```

## Tuning & Behavior
*   **Default Value:** 200 cm (2 meters)
*   **Range:** 10 - 1000 cm
*   **Effect of Increasing:** Smoother mission flight. Higher average speed. Drone "rounds off" the corners of the path.
*   **Effect of Decreasing:** More precise path tracking. Drone "stops and turns" at each waypoint.

### Use Case Recommendations
*   **Aerial Mapping (Photogrammetry):** **Set to 200 - 300.** You want smooth flight to avoid motion blur in the photos, and a 2-3 meter error is usually acceptable for the photo center.
*   **Precision Spraying (Agriculture):** **Decrease to 100.** You need to ensure the chemicals are applied exactly to the edge of the field.
*   **Search and Rescue:** **Set to 500.** Speed and coverage area are more important than hitting the exact center of a search grid.

### Troubleshooting
*   **Scenario:** Drone reaches a waypoint but then starts doing wide circles around it instead of going to the next one.
    *   **Diagnosis:** `WPNAV_RADIUS` is too small for the current `WPNAV_SPEED`. The drone's turn radius is larger than the hit radius.
    *   **Fix:** Increase `WPNAV_RADIUS` or reduce `WPNAV_SPEED`.