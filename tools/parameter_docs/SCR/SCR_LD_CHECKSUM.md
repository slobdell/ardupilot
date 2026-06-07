---
layout: parameter
name: SCR_LD_CHECKSUM
display_name: "Loaded script checksum"
description: "The required XOR-CRC32 checksum of all scripts found and compiled. Prevents arming if scripts are modified."
default_value: -1
range: null
units: "Hex"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L149
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Loaded script checksum (SCR_LD_CHECKSUM)

## Description
This parameter is a security and safety feature that ensures the set of Lua scripts on your SD card matches a "Known Good" configuration. It stores an aggregate CRC32 checksum of every script the autopilot has successfully found and compiled during boot.

If you enable this check, ArduPilot will prevent the vehicle from arming if even a single character in any script has been changed, or if a script has been added or removed from the `APM/scripts` folder. This is vital for commercial or industrial operations where script integrity is a requirement for flight certification.

## The Mathematics
The system calculates a standard CRC32 for each individual script file. The total checksum ($C_{total}$) is the bitwise XOR accumulation of all individual script checksums ($C_n$):

$$ C_{total} = C_1 \oplus C_2 \oplus \dots \oplus C_n $$

The resulting 32-bit value is then masked by `0x7FFFFFFF` to fit within the signed integer parameter range.

## The Engineer's View
In `AP_Scripting::arming_checks()` (`libraries/AP_Scripting/AP_Scripting.cpp`):
1.  The code checks if `_required_loaded_checksum` is not -1.
2.  It retrieves the current session's checksum from the Lua compiler backend.
3.  If they do not match, it returns a `false` status with the message: `"Scripting: loaded CRC incorrect"`.
4.  This check ensures that the scripts *on the disk* haven't been tampered with since the last time the "Master" checksum was saved.

## Tuning & Behavior
*   **Default Value:** -1 (Check disabled).
*   **How to Set:** Use `SCR_DEBUG_OPTS` Bit 5 (Value 32) to automatically calculate and save the current checksum to this parameter. 
*   **Usage:** Once your scripts are fully tested and frozen, save the checksum. From that point on, any change to the scripts will block arming until you explicitly update the parameter again.

