---
layout: parameter
name: OSD_MSG_TIME
display_name: OSD Message Duration
description: The time (in seconds) that status messages and warnings remain visible on the screen.
default_value: 10
range: 0 60
units: s
group: OSD
visual_asset_id: osd_msg_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_OSD/AP_OSD.cpp#L100
---

# OSD Message Duration (OSD_MSG_TIME)

## Description
`OSD_MSG_TIME` controls how long text notifications (like "Flight Mode: Loiter" or "Bad Compass Health") stay on screen.

*   **10 (Default):** 10 seconds. Good for ensuring you see the message.
*   **3:** Short duration. Good for experts who want a clean feed.

## Tuning & Behavior
*   **Default Value:** 10s.
*   **Recommendation:** Reduce to **5** if you find the text covers up important video details for too long.
