---
layout: parameter
name: AVOID_ENABLE
display_name: Avoidance control enable/disable
description: Bitmask that enables different sources for obstacle avoidance (Fence, Proximity Sensors, Beacons).
default_value: 3
range: 0 7
units: 
group: AVOID
visual_asset_id: avoid_enable_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_Avoidance/AC_Avoid.cpp#L45
---

# Avoidance control enable/disable (AVOID_ENABLE)

## Description
`AVOID_ENABLE` activates the logic that prevents the drone from hitting things. While `FENCE` prevents the drone from leaving a large area, `AVOID` handles "Local Obstacles" detected by sensors (like Lidars) or boundaries (like the Fence).

**Key Bits:**
*   **Bit 0 (1): Use Fence.** The drone will treat the geofence as a solid wall it cannot fly into.
*   **Bit 1 (2): Use Proximity Sensor.** Enables avoidance using 360-degree Lidars or rangefinders.
*   **Bit 2 (4): Use Beacon Fence.** Treat beacon-defined boundaries as obstacles.

## The Engineer's View
Used in `AC_Avoid::adjust_velocity()`. 
When enabled, the avoidance library intercepts the pilot's velocity commands and "pushes back" if they lead toward an obstacle. It effectively creates a virtual "Repulsive Field" around the drone.

## Tuning & Behavior
*   **Default Value:** 3 (Use Fence + Proximity) on most systems.
*   **Recommendation:** Keep at **3** if you have any avoidance hardware installed.
*   **Safety:** This logic is active in **Loiter**, **Circle**, and **Auto** modes. In **Stabilize** or **Acro**, the drone will NOT automatically stop for obstacles.