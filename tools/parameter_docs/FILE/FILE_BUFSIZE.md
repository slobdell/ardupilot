---
layout: parameter
name: FILE_BUFSIZE
display_name: Logging File buffer size
description: The size of the memory buffer allocated for file-based logging. Higher values reduce "gaps" in logs during slow SD card writes.
default_value: 200
range: 4 256
units: kB
group: FILE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L97
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Logging File buffer size (FILE_BUFSIZE)

## Description
This parameter defines the size of the memory buffer (in kilobytes) allocated for the file-based logging system. This buffer acts as a "waiting room" for data being written to the microSD card.

If the SD card is slow or busy (e.g., during high vibration or when the card is nearly full), this buffer allows ArduPilot to continue collecting sensor data without losing ("dropping") any log messages. A larger buffer provides more protection against "gaps" in your logs.

## The Mathematics
The buffer size is a direct allocation of RAM. 

$$ RAM_{logging} = FILE\_BUFSIZE \times 1024 \text{ bytes} $$

If the incoming data rate (bytes per second) exceeds the SD card's write speed for a duration $t$, the buffer fills at a rate:
$$ \Delta Buffer = \int_0^t (Rate_{in} - Rate_{out}) \, dt $$

If $\Delta Buffer > FILE\_BUFSIZE$, data is lost.

## The Engineer's View
In `AP_Logger.cpp`, this parameter is defined as `_FILE_BUFSIZE`.
*   **High Performance Boards:** Default is often **200kB**.
*   **Limited RAM Boards:** Default can be as low as **16kB**.
*   **Replay Mode:** When `LOG_REPLAY` is enabled (for EKF diagnostic testing), the data volume increases significantly. In these cases, it is highly recommended to increase `FILE_BUFSIZE` (to 100-200kB) to ensure the high-frequency sensor data required for a successful replay is not dropped.

## Tuning & Behavior
*   **Default Value:** Varies by board (usually 200 on H7/F7, 16 on F4).
*   **Range:** 4 to 256 kB.
*   **When to Increase:** If you see "Log Drop" or "Missing Data" warnings in your Ground Control Station, or if you are using high-rate logging for research or EKF Replay.
*   **When to Decrease:** Almost never, unless you are critically low on RAM for Lua scripts or other features.
*   **Reboot Required:** Yes. RAM allocation happens at startup.

