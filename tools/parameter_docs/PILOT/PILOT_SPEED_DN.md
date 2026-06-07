---
layout: parameter
name: PILOT_SPEED_DN
display_name: Pilot maximum vertical speed descending
description: The maximum vertical velocity (in cm/s) the pilot can request while descending in semi-autonomous modes.
default_value: 0
range: 0 500
units: cm/s
group: PILOT
visual_asset_id: pilot_speed_dn_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L869
---

# Pilot maximum vertical speed descending (PILOT_SPEED_DN)

## Description
`PILOT_SPEED_DN` determines how fast your drone descends when you pull the throttle stick down in modes like **AltHold** or **Loiter**.

*   **0 (Default):** Use the same value as `PILOT_SPEED_UP` (usually 250 cm/s).
*   **Custom Value:** Sets a specific limit for descent.

**Warning:** Rapid descents can be dangerous for multicopters. If you descend too fast through your own propeller wash, the drone can enter **Vortex Ring State (VRS)**, causing it to wobble violently and potentially flip or crash.

## Tuning & Behavior
*   **Default Value:** 0
*   **Recommendation:** Set to **150 or 200** if you want safer, slower descents. Never set this higher than 500 unless you have a high-speed racing drone and know how to recover from a stall.