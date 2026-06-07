---
layout: parameter
name: WPNAV_RFND_USE
display_name: Waypoint Mission Rangefinder Usage
description: Controls whether the drone uses its rangefinder (Lidar/Sonar) for altitude control during autonomous missions. Enabling this allows for "Terrain Following" relative to the ground.
default_value: 1
range: 0 1
units: 
group: WPNAV
visual_asset_id: wpnav_rfnd_use_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_WPNav/AC_WPNav.cpp#L77
---

# Waypoint Mission Rangefinder Usage (WPNAV_RFND_USE)

## Description
`WPNAV_RFND_USE` is the master switch for **Terrain Following** in autonomous missions. It determines whether the drone's height is measured from where it started (Barometer) or from the surface directly beneath it (Rangefinder).

*   **Enabled (1):** The drone uses its rangefinder (Lidar/Sonar) to maintain its height above the ground. If the drone flies over a hill, it will climb to maintain the requested altitude relative to the slope.
*   **Disabled (0):** The drone uses the Barometer or GPS to maintain a fixed altitude relative to its takeoff point ("Home"). If it flies over a hill, it will stay at the same absolute height, potentially crashing into the terrain.

**Pre-requisite:** You must have a functioning rangefinder configured (`RNGFND1_TYPE` > 0) for this parameter to have any effect.

## The Mathematics
This parameter toggles the **Altitude Reference** in the vertical control loop:

$$ Z_{target} = \begin{cases} \text{Ground\_Level} + \text{Alt\_WP}, & \text{if } \text{RFND\_USE} = 1 \\ \text{Home\_Level} + \text{Alt\_WP}, & \text{if } \text{RFND\_USE} = 0 \end{cases} $$

Where `Alt_WP` is the altitude specified in the mission file (MAVLink `MISSION_ITEM`).

## The Engineer's View
This parameter is the `_rangefinder_use` member in `AC_WPNav`.

It is checked in `AC_WPNav::update_z_controller()`. When enabled, the code continuously queries the rangefinder for the current distance to ground. One critical safety feature is that **ArduPilot will ignore this parameter if the rangefinder health is low**. If the Lidar loses its signal (e.g., flying over water), the system will automatically fall back to Barometric altitude to prevent a crash.

## Tuning & Behavior
*   **Default Value:** 1 (Enabled)
*   **Range:** 0 (Off) or 1 (On)
*   **Effect of Enabling:** Drone follows the contours of the ground. Essential for low-altitude mapping and agriculture.
*   **Effect of Disabling:** Drone stays at a constant barometric height. Safer for high-altitude flight where ground texture may be unreliable.

### Use Case Recommendations
*   **Agricultural Spraying:** **Always Enable (1).** You must maintain a precise distance from the crops regardless of the field's slope.
*   **Power Line Inspection:** **Always Enable (1).** Ensures the drone tracks the vertical profile of the terrain accurately.
*   **High-Altitude Photography (>50m):** **Disable (0).** Most hobbyist rangefinders are unreliable above 30-40 meters. Using the Barometer is safer at these heights.

### Troubleshooting
*   **Scenario:** Drone "bobs" up and down violently during a mission over tall grass.
    *   **Diagnosis:** The rangefinder is getting inconsistent readings from the grass.
    *   **Fix:** Disable `WPNAV_RFND_USE` or increase `EK3_HGT_DELAY`.