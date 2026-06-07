---
layout: parameter
name: QWIK_OPTIONS
display_name: "Quicktune options"
description: "Bitmask for advanced Quicktune behavior, such as simplified switch logic."
default_value: 0
range: null
units: "Bitmask"
group: QWIK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L137
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Quicktune options (QWIK_OPTIONS)

## Description
This parameter provides additional configuration for the Quicktune automated tuning system. Its primary use is to simplify the control logic for pilots who prefer using a standard 2-position toggle switch rather than the default 3-position behavior.

## The Mathematics
The parameter is a bitmask ($B$):

*   **Bit 0 (Value 1): Use Two-Position Switch.**
    *   **Disabled (0):** Default 3-position logic. 
        *   Low: Abort/Revert.
        *   Mid: Start Tuning.
        *   High: Save Tune.
    *   **Enabled (1):** Simplified 2-position logic.
        *   Low: Disable/Abort.
        *   High: Start Tuning.
        *   *(Note: Requires `QWIK_AUTO_SAVE` to be configured to save the results automatically).*

## The Engineer's View
In `AP_Quicktune::update()` (`libraries/AP_Quicktune/AP_Quicktune.cpp`), the logic branches based on the `OPTIONS_TWO_POSITION` flag.
If Bit 0 is set:
1.  The `sw_pos_tune` target is shifted to `SwitchPos::HIGH`.
2.  The `sw_pos_save` target is set to `SwitchPos::NONE`, meaning the switch itself cannot trigger a save.
3.  The system relies on the `tune_done_time_ms` timer and the `auto_save` parameter to commit the learned gains to EEPROM after the tuning session successfully completes.

## Tuning & Behavior
*   **Default Value:** 0 (Standard 3-position switch logic).
*   **When to Use:** If you are short on auxiliary channels or prefer a simple "Tune ON / Tune OFF" switch.
*   **Safety Hint:** If using the 2-position mode, ensure `QWIK_AUTO_SAVE` is set to a non-zero value (e.g., 10 seconds), otherwise your new tune will be lost the moment you flip the switch back to Low.
