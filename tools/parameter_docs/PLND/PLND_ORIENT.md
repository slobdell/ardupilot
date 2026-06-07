---
layout: parameter
name: PLND_ORIENT
display_name: "Camera Orientation"
description: "Orientation of the precision landing sensor on the vehicle body."
default_value: 25
range: null
units: "Rotation"
group: PLND
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L176
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Camera Orientation (PLND_ORIENT)

## Description
This parameter defines the physical mounting orientation of the camera or IR sensor used for precision landing. It tells the autopilot which direction the sensor is "looking" relative to the front of the aircraft. 

Correct orientation is vital for the navigation math to work. If the sensor is pointing down but the software thinks it's pointing forward, the drone will attempt to fly in the wrong direction to center the target.

## The Mathematics
The autopilot uses this rotation matrix ($R_{orient}$) to transform the raw vector reported by the sensor ($V_{raw}$) into the body-frame coordinate system ($V_{body}$).

$$ V_{body} = R_{orient} \times V_{raw} $$

This ensures that regardless of how the sensor is mounted, the "Error X" and "Error Y" inputs to the landing controller are always relative to the vehicle's Forward and Right axes.

## The Engineer's View
In `AC_PrecLand::retrieve_los_meas()` (`libraries/AC_PrecLand/AC_PrecLand.cpp`):
1.  The code retrieves the unit vector from the sensor backend.
2.  If the orientation is not the default `PITCH_270` (Down), it performs a multi-step rotation:
    *   First, it rotates by `PITCH_90` to bring the vector from a default "downward" assumption to "forward."
    *   Then, it applies the user-configured `_orient` rotation.
3.  This internal normalization allows the backend drivers to report vectors in a consistent frame while the user has the flexibility to mount hardware in various configurations.

## Tuning & Behavior
*   **Default Value:** 25 (Rotation_Pitch_270 - Looking Down).
*   **Rover Default:** 0 (Rotation_None - Looking Forward).
*   **Common Values:**
    *   **25:** Downward (Standard for Copter/QuadPlane).
    *   **0:** Forward (Looking ahead, common for Rover or Plane-approach).
    *   **4:** Backward (Looking behind).
*   **Reboot Required:** Yes.

