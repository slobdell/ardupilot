---
layout: parameter
title: RTC_TZ_MIN
name: Timezone offset from UTC
group: RTC
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_RTC/AP_RTC.cpp#L47
---

# RTC_TZ_MIN: Timezone offset from UTC

## Description
Adds offset in +- minutes from UTC to calculate local time.

## Values
- **Range:** -720 to +840 (minutes)
- **Increment:** 1
- **Default:** 0

## Description
This parameter adjusts the autopilot's internal clock to match your local time zone.

- **Usage:** Set this if you want the logs or the On-Screen Display (OSD) to show local time instead of UTC.
- **Example:** For Eastern Standard Time (EST, UTC-5), set this to **-300**. For Central European Summer Time (CEST, UTC+2), set this to **120**.
- **Effect:** Primarily affects the `SYSTEM_TIME` MAVLink message and the time displayed on OSD widgets. It does NOT affect the EKF or navigation, which always use UTC.

