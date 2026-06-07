---
layout: parameter
name: RTC_TYPES
display_name: "Allowed sources of RTC time"
description: "Bitmask of allowed time sources for updating the system clock"
default_value: 1
range: 0 7
units: "Bitmask"
group: RTC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RTC/AP_RTC.cpp#L40
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RTC/AP_RTC.h#L19
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Allowed sources of RTC time (RTC_TYPES)

## Description
This parameter controls which external sources are trusted to set the autopilot's internal Real Time Clock (RTC). Maintaining accurate UTC time is essential for log timestamping and GNSS operations.

## The Mathematics
Bitmask.

## The Engineer's View
Defined in `libraries/AP_RTC/AP_RTC.cpp`.
*   **Bit 0:** GPS (Preferred).
*   **Bit 1:** MAVLink `SYSTEM_TIME` messages (from GCS).
*   **Bit 2:** Hardware RTC (on-board backup battery).

## Tuning & Behavior
*   **Default Value:** 1 (GPS Only)
*   **Recomendation:** Enable Bit 2 if your board has a backup battery for the RTC. Enable Bit 1 if flying indoors without GPS but connected to a Ground Station.