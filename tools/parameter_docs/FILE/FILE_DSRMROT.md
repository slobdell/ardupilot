---
layout: parameter
name: FILE_DSRMROT
display_name: Stop logging to current file on disarm
description: When enabled, the current log file is closed on disarm. If LOG_DISARMED is set, a new file is opened immediately.
default_value: 0
range: 0 1
units: Option
group: FILE
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Logger/AP_Logger.cpp#L118
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Stop logging to current file on disarm (FILE_DSRMROT)

## Description
This parameter controls how ArduPilot handles log file rotation when the vehicle disarms. It allows you to decide if multiple flights on the same battery should be saved in one large file or split into separate, distinct files.

*   **0 (Default):** Keeps the same log file open until the system is rebooted. This results in one log file containing all activities (even across several arm/disarm cycles).
*   **1 (Enabled):** Closes the current log file immediately upon disarming. If `LOG_DISARMED` is enabled, it will then start a brand-new log file for the next session.

## The Mathematics
This parameter functions as a boolean gate in the state machine logic:

$$ \text{IF } (\text{Disarmed} \text{ AND } FILE\_DSRMROT == 1) \rightarrow \text{Close current handle} $$

## The Engineer's View
In `AP_Logger.cpp`, this parameter maps to `_params.file_disarm_rot`.
When the vehicle state changes to disarmed, the logging backend checks this flag. 
*   If set, `AP_Logger_File::stop_logging()` is called. 
*   This is useful for professional operators who want a clean 1-to-1 mapping between a flight mission and a `.bin` log file, making data analysis much more organized.

## Tuning & Behavior
*   **0:** Preferred for casual flying or if you are troubleshooting ground issues and want a continuous record.
*   **1:** Recommended for commercial mapping, inspections, or competition flights. It ensures that if one flight is successful and the next crashes, the logs are already segmented and easier to manage.
*   **Dependencies:** Works most effectively when `LOG_DISARMED` is also set to 1 or 2, ensuring that the "pre-arm" period for the next flight is captured in its own new file.

