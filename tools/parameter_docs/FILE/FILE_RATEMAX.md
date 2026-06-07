---
layout: parameter
name: FILE_RATEMAX
display_name: Maximum logging rate for file backend
description: Limits the frequency of log message updates to the SD card. Useful for preventing SD card bandwidth saturation.
default_value: 0
range: 0 1000
units: Hz
group: FILE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L151
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Maximum logging rate for file backend (FILE_RATEMAX)

## Description
This parameter acts as a "Data Governor" for the logging system. It sets a global cap on how frequently (in Hz) streaming log messages can be written to the SD card.

By setting a limit, you can prevent the autopilot from overwhelming a slow microSD card with too much data, which can cause lag or CPU spikes. This is particularly useful on vehicles with many high-frequency sensors or complex Lua scripts that generate a lot of custom logging.

## The Mathematics
The logging backend tracks the last time a message of a specific type was written.

$$ \Delta T_{min} = \frac{1}{FILE\_RATEMAX} $$

If the time elapsed since the last log write is less than $\Delta T_{min}$, the current message is skipped.

## The Engineer's View
In `AP_Logger_File.cpp`, the streaming write logic checks `_params.file_ratemax`.
*   **0:** Unlimited rate. The system logs every message as soon as it arrives (subject to buffer space).
*   **Non-Zero:** Applies a per-instance throttle.
*   Note that this only affects "streaming" messages (periodic sensor updates); critical events (errors, mode changes, parameters) are always logged immediately to ensure they are never missed.

## Tuning & Behavior
*   **Default Value:** 0 (Rate limiting disabled).
*   **Range:** 0 to 1000 Hz.
*   **When to Use:** If you see "High CPU" or "IO Performance" warnings in your logs, or if your `.BIN` files are becoming unnecessarily large for long endurance flights.
*   **Typical Value:** Setting this to **50Hz** or **100Hz** is often sufficient for standard flight analysis while significantly reducing the load on the SD card interface.

