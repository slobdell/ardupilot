---
layout: parameter
name: LOG_RAW
display_name: "Proximity Raw Logging Enable"
description: "Enables logging of raw, unfiltered distance measurements from proximity sensors (Obstacle Avoidance)."
default_value: 0
range: 0 1
units: "Option"
group: LOG
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Proximity/AP_Proximity.cpp#L61
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Proximity Raw Logging Enable (LOG_RAW)

## Description
This parameter enables the recording of raw, unfiltered distance data from Proximity sensors (like LiDAR or Ultrasound 360-degree scanners) to the autopilot's data log. 

Proximity sensors are the "Eyes" of the drone's obstacle avoidance system. Normally, ArduPilot only logs the processed "Object Locations." Enabling `LOG_RAW` allows you to see every individual distance measurement the sensor reports, which is essential for diagnosing why an avoidance system might be failing, detecting "phantom" obstacles caused by sunlight or dust, and verifying the physical performance of your sensors.

## The Mathematics
This is a binary boolean gate ($G_{log}$):

$$ \text{IF } LOG\_RAW == 1 \rightarrow \text{Execute } Write\_Proximity\_Raw\_Message() $$

When enabled, the system generates high-frequency `PRX` log packets containing distance and angle pairs for every detection.

## The Engineer's View
In `AP_Proximity.cpp`, this parameter maps to `_raw_log_enable`.
*   **Logging Backend:** When enabled, the `AP_Proximity::update()` loop triggers the message creation in the `Log_Write()` function. 
*   **SD Card Load:** Warning: Raw proximity data can be very high-volume (hundreds of points per second). Enabling this will significantly increase the size of your `.BIN` log files and the load on your SD card. 
*   **Data Integrity:** This logs the data *before* any of ArduPilot's internal filtering or "Persistence" checks are applied, providing a "Truth" view of the sensor output.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled).
*   **When to Enable:** Specifically during troubleshooting of Obstacle Avoidance or when integrating a new Proximity sensor model.
*   **When to Disable:** Standard flight operations. Keep disabled to save log space and reduce CPU overhead.
*   **Dependencies:** Requires `PRX_TYPE` to be non-zero and a healthy proximity sensor to be connected.

