---
layout: parameter
name: SCR_RUN_CHECKSUM
display_name: "Running script checksum"
description: "The required XOR-CRC32 checksum of all scripts currently executing. Prevents arming if scripts crash or fail to start."
default_value: -1
range: null
units: "Hex"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L155
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Running script checksum (SCR_RUN_CHECKSUM)

## Description
This parameter provides a dynamic layer of safety for Lua scripting by verifying that the correct set of scripts is not only present but is actually **running**. 

While `SCR_LD_CHECKSUM` verifies that scripts exist and compiled correctly, `SCR_RUN_CHECKSUM` ensures that every intended script has successfully entered its execution loop and hasn't crashed or been manually stopped. If the "Running Checksum" calculated by the autopilot doesn't match this parameter, the vehicle will refuse to arm.

## The Mathematics
The system calculates a bitwise XOR accumulation of the CRC32 values ($C_n$) for all scripts that are currently in the `running` state within the Lua VM.

$$ C_{running} = C_1 \oplus C_2 \oplus \dots \oplus C_{running\_n} $$

The value is masked with `0x7FFFFFFF` to ensure compatibility with standard GCS parameter displays.

## The Engineer's View
In `AP_Scripting::arming_checks()` (`libraries/AP_Scripting/AP_Scripting.cpp`):
1.  The system identifies which scripts are active in the Lua scheduler.
2.  It calculates the current aggregate CRC.
3.  If this fails to match `_required_running_checksum` (and it's not -1), the pre-arm check fails with the message: `"Scripting: running CRC incorrect"`.
4.  This is a critical distinction from the "Loaded" check: a script that has a syntax error will fail the "Loaded" check, but a script that compiles but then crashes (e.g., due to an infinite loop or memory limit) will fail the "Running" check.

## Tuning & Behavior
*   **Default Value:** -1 (Check disabled).
*   **How to Set:** Set `SCR_DEBUG_OPTS` Bit 5 (Value 32) while all your desired scripts are running healthy. ArduPilot will save the current running CRC to this parameter automatically.
*   **Reliability:** This parameter is essential for missions that depend on Lua scripts for safety (e.g., custom fail-safes or terrain-following logic). It guarantees that the vehicle won't arm if the safety-critical script is not active.

