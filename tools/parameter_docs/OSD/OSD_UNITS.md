---
layout: parameter
name: OSD_UNITS
display_name: OSD Display Units
description: Sets the unit system used for displaying altitude, speed, and distance on the OSD.
default_value: 0
range: 0 3
units: 
group: OSD
visual_asset_id: osd_units_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.h#L765
---

# OSD Display Units (OSD_UNITS)

## Description
`OSD_UNITS` sets the measurement system for your HUD.

*   **0: Metric (Default).** Meters (m), Kilometers per hour (km/h).
*   **1: Imperial.** Feet (ft), Miles per hour (mph).
*   **2: SI.** Meters (m), Meters per second (m/s).
*   **3: Aviation.** Feet (ft), Knots (kn).

## Tuning & Behavior
*   **Default Value:** 0.
*   **Recommendation:**
    *   **Science/Engineering:** Use **2 (SI)**.
    *   **General Aviation:** Use **3 (Aviation)**.
