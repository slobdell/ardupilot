---
layout: parameter
name: USE_REV_THRUST
display_name: "Bitmask for when to allow negative reverse thrust"
description: "Controls flight stages where reverse thrust is permitted"
default_value: 2
range: 0 8191
units: "Bitmask"
group: USE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/Parameters.cpp#L236
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Bitmask for when to allow negative reverse thrust (USE_REV_THRUST)

## Description
This bitmask controls exactly when the autopilot is allowed to use reverse thrust (negative throttle) during autonomous flight modes. Reverse thrust is a powerful tool for steep descents and shortening landing rolls, but it can cause stalls or loss of control if engaged inappropriately (e.g., during normal cruise or loiter).

## The Mathematics
The parameter is a bitmask where each bit represents a flight condition:
*   **Bit 0:** Auto Always
*   **Bit 1:** Auto Land Approach (Most Common)
*   **Bit 2:** Auto Loiter to Alt
*   **Bit 3:** Auto Loiter All
*   **Bit 4:** Auto Waypoint
*   **Bit 5:** Loiter
*   **Bit 6:** RTL
*   **Bit 7:** Circle
*   **Bit 8:** Cruise
*   **Bit 9:** FBWB
*   **Bit 10:** Guided
*   **Bit 11:** Auto Landing Pattern
*   **Bit 12:** FBWA

## The Engineer's View
Defined in `ArduPlane/Parameters.cpp` and used throughout the flight mode logic (e.g., `ArduPlane/reverse_thrust.cpp`).
*   **Safeguards:** Reverse thrust usually requires `THR_MIN` to be negative.
*   **Default (2):** `USE_REVERSE_THRUST_AUTO_LAND_APPROACH`. This is the safest default, allowing braking only when committed to a landing.

## Tuning & Behavior
*   **Default Value:** 2 (Auto Land Approach Only)
*   **0:** Never use reverse thrust in auto modes.
*   **2 (Bit 1):** Allow only during the landing sequence.
*   **65 (Bit 0 + Bit 6):** Allow in all Auto modes + RTL.
*   **Warning:** Enabling reverse thrust in modes like `FBWA` or `CRUISE` can lead to mid-air stops if the pilot pulls back on the throttle stick. Use with caution.