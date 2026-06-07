---
layout: parameter
name: FILE_TIMEOUT
display_name: Timeout before giving up on file writes
description: The maximum time allowed for failing SD card writes before the log file is closed to prevent system lag.
default_value: 5
range: 1 30
units: s
group: FILE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L134
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Timeout before giving up on file writes (FILE_TIMEOUT)

## Description
This parameter sets a "Safety Watchdog" for SD card operations. If the autopilot attempts to write to the microSD card and the operation hangs or fails repeatedly for a period longer than this timeout, the autopilot will give up and close the log file.

This is a critical safety feature: it prevents a faulty or slow SD card from "locking up" the main flight control loop, which could cause the aircraft to crash. It is better to lose the log than to lose the aircraft.

## The Mathematics
The logging backend tracks the last successful write timestamp ($t_{success}$).

$$ \text{IF } (t_{now} - t_{success} > FILE\_TIMEOUT) \text{ AND } \text{WriteFailureActive} \rightarrow \text{Abort Logging} $$

The default value is **5 seconds**.

## The Engineer's View
In `AP_Logger_File.cpp`, this parameter maps to `_params.file_timeout`. 
*   It is used in the `AP_Logger_File::periodic` task.
*   If a write failure persists beyond the threshold, the file handle is invalidated (`_fd = -1`).
*   The system will then wait for a separate "Re-open" period (typically 5 seconds) before trying to initialize a new log file, ensuring the system doesn't enter a tight loop of failing I/O.

## Tuning & Behavior
*   **Default Value:** 5 seconds.
*   **Recommendation:** Leave at **5s**.
*   **Increasing:** May be necessary for extremely high-volume logging on slower industrial cards, but increases the risk of "CPU Hang" during write retries.
*   **Decreasing:** Makes the system more aggressive at cutting off logging if the card is slow. 
*   **Symptom of Timeout:** If your logging stops mid-flight but the aircraft continues to fly normally, your SD card likely exceeded this timeout due to write latency.
    *   **Fix:** Format the card, use a Class 10/U3 card, or increase `FILE_BUFSIZE`.

