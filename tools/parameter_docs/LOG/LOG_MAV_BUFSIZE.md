---
layout: parameter
name: LOG_MAV_BUFSIZE
display_name: "MAVLink Logging Buffer Size"
description: "The maximum amount of RAM (in kilobytes) allocated for the MAVLink logging backend."
default_value: 8
range: 1 100
units: "kB"
group: LOG
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L126
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# MAVLink Logging Buffer Size (LOG_MAV_BUFSIZE)

## Description
This parameter sets the size of the memory buffer (in kilobytes) dedicated to "MAVLink Logging." Unlike standard logging which writes to an SD card, MAVLink logging streams the log data over your telemetry link (WiFi or Radio) directly to the Ground Control Station (GCS).

This is extremely useful for vehicles without SD cards (like some small racing drones) or for real-time analysis of flight data while the aircraft is still in the air. The buffer ensures that brief interruptions in the radio link don't cause gaps in the telemetry log.

## The Mathematics
The system allocates a static block of RAM based on this value. 

$$ \text{RAM}_{MAV\_Log} = LOG\_MAV\_BUFSIZE \times 1024 \text{ bytes} $$

Because MAVLink logging is sent in small chunks, the internal code calculates how many "Blocks" can fit into this RAM:
$$ \text{BlockCount} = \frac{\text{RAM}_{MAV\_Log}}{\text{sizeof}(\text{dm\_block})} $$
*(where dm_block is typically 92 bytes).*

## The Engineer's View
In `AP_Logger_MAVLink.cpp`, this parameter determines the capacity of the outgoing message queue. 
*   **Bandwidth Sensitivity:** MAVLink logging consumes significant telemetry bandwidth. Even with a large buffer, if your radio link is slow (e.g., a 915MHz SiK radio at 57600 baud), the buffer will fill up quickly and data will be dropped.
*   **Recommendation:** Only use this feature on high-speed links (WiFi, Ethernet, or high-speed SIYI/Herelink telemetry). On standard slow radios, this feature should typically be disabled or set to a very low rate.

## Tuning & Behavior
*   **Default Value:** 8 kB.
*   **Range:** 1 to 100 kB.
*   **When to Increase:** If you are using real-time GCS logging over a fast link and notice "Data Missing" or "Gaps" in your live telemetry charts.
*   **When to Decrease:** If you are tight on RAM and not using the MAVLink logging feature.
*   **Reboot Required:** Yes. Memory allocation for the logging backend happens at startup.

