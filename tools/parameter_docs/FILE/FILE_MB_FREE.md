---
layout: parameter
name: FILE_MB_FREE
display_name: Logging Minimum Free Space
description: The logging system will delete the oldest log files to ensure at least this many megabytes remain free on the SD card.
default_value: 500
range: 10 5000
units: MB
group: FILE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L142
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Logging Minimum Free Space (FILE_MB_FREE)

## Description
This parameter manages the "Automatic Cleanup" of your microSD card. It sets a minimum threshold for free space (in megabytes). If the card fills up and the free space drops below this value, ArduPilot will automatically delete the **oldest** log files to make room for new data.

This ensures that you always have enough space for your current flight and prevents the logging system from crashing or hanging due to a full filesystem.

## The Mathematics
The logging backend monitors the available space on the disk.

$$ \text{IF } (\text{DiskFreeMB} < FILE\_MB\_FREE) \rightarrow \text{Delete oldest .BIN file} $$

This loop continues until the condition is no longer met or no more logs can be deleted.

## The Engineer's View
In `AP_Logger_File.cpp`, the cleanup logic is part of the maintenance task. 
*   It uses `AP::FS().get_disk_free()` to check remaining capacity.
*   It iterates through the existing log list (starting from `last_log_num` backwards) to identify targets for deletion.
*   By maintaining a significant buffer (default 500MB), it avoids file fragmentation issues and ensures the filesystem has overhead for metadata updates and other temporary files.

## Tuning & Behavior
*   **Default Value:** 500 MB.
*   **Recommendation:** Set this to a value larger than your longest expected flight log (e.g., if a 1-hour flight produces a 100MB log, 500MB is a very safe buffer).
*   **Agile Development:** If you fly many short missions and don't want to manually clear your card, this parameter is your best friend.
*   **Critical Data:** If you cannot afford to lose old logs, you should set this lower and monitor your card manually, or better yet, increase the SD card size.

