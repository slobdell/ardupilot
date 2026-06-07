---
layout: parameter
name: BARO_ALTERR_MAX
display_name: "Altitude error maximum"
description: "Maximum allowed discrepancy between GPS altitude and barometric pressure altitude for arming."
default_value: 2000
range: 0 5000
units: "m"
group: BARO
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Baro/AP_Baro.cpp#L247
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Altitude error maximum (BARO_ALTERR_MAX)

## Description
This parameter is a pre-arm safety check that compares the altitude reported by the GPS to the altitude calculated from the barometer. It is designed to catch "Hardware Substitutions" or faulty sensors before you take off.

A common issue in the hardware market is vendors substituting one barometer model (like the MS5607) for another (like the MS5611) without updating the firmware settings. This causes the altitude to be calculated incorrectly (often off by thousands of meters). This check prevents the vehicle from arming if such a massive discrepancy is detected.

## The Mathematics
The autopilot compares the GPS altitude ($Alt_{AMSL}$) to the barometric pressure altitude calculated against the Standard Sea Level (SSL) atmosphere.

$$ Error = |Alt_{GPS} - Alt_{Baro\_SSL}| $$

If $Error > BARO\_ALTERR\_MAX$, the arming check fails.

## The Engineer's View
In `AP_Baro::arming_checks()` (`libraries/AP_Baro/AP_Baro.cpp`):
1.  The code verifies a valid 3D GPS fix is available.
2.  It calculates `alt_pressure = get_altitude_difference(SSL_AIR_PRESSURE, get_pressure())`.
3.  It compares this to `gps.location().alt`.
4.  If the gap is too large, it returns the error message: `"GPS alt error [X]m (see BARO_ALTERR_MAX)"`.

## Tuning & Behavior
*   **Default Value:** 2000 meters.
*   **Usage:** You should not typically need to tune this. If you are getting this error, it is a strong signal that your barometer is either faulty or misconfigured.
*   **0:** Disables this safety check.
*   **Hardware Fix:** If you are certain your hardware is an MS5607 being treated as an MS5611, refer to the `BARO_OPTIONS` parameter to force the correct driver behavior.

