---
layout: parameter
name: SCR_DEBUG_OPTS
display_name: "Scripting Debug Options"
description: "Bitmask for controlling debugging messages, logging, and safety checks for Lua scripts."
default_value: 0
range: null
units: "Bitmask"
group: SCR
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Scripting/AP_Scripting.cpp#L99
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Scripting Debug Options (SCR_DEBUG_OPTS)

## Description
This parameter is a bitmask used to control various debugging and maintenance features of the Lua scripting engine. It allows developers to monitor performance, manage security checksums, and suppress or enable specific status messages.

## The Mathematics
The value is treated as a set of individual binary flags:

*   **Bit 0 (1): Suppress "No Scripts" message.** Disables the GCS notification if the system finds zero scripts to run.
*   **Bit 1 (2): Runtime telemetry messages.** Periodically sends GCS text messages showing current RAM usage and execution time for each running script.
*   **Bit 2 (4): Suppress Log Writing.** Prevents scripts from being written to the `.BIN` log file (saves SD card space).
*   **Bit 3 (8): Continuous Data Logging.** Enables high-frequency logging of script performance metrics to the DataFlash log.
*   **Bit 4 (16): Disable Pre-Arm Check.** Allows the vehicle to arm even if a script has an error or is missing. **(Caution: Safety Risk)**.
*   **Bit 5 (32): Auto-save Checksums.** A "one-shot" command. When set, the system calculates the current script CRCs, saves them to `SCR_LD_CHECKSUM` and `SCR_RUN_CHECKSUM`, and then automatically clears this bit.
*   **Bit 6 (64): Disable Heap Expansion.** Prevents the Lua VM from trying to grow its memory pool if a script runs out of space.

## The Engineer's View
In `AP_Scripting.cpp`:
*   **Checkpoints:** The `arming_checks()` function respects Bit 4.
*   **One-Shot Logic:** The `save_checksum()` function checks Bit 5 at 1Hz. If active, it performs the XOR-CRC calculations and immediately calls `option_clear(DebugOption::SAVE_CHECKSUM)` to prevent accidental overwrites.
*   **Performance Tracking:** Bit 1 and 3 are handled inside the Lua executor loop (`lua_scripts.cpp`) to inject timing probes around the VM execution window.

## Tuning & Behavior
*   **Development Stage:** Set to **2 (Bit 1)** to get constant feedback on your script's memory footprint and efficiency.
*   **Production Stage:** Set to **0** for a clean GCS experience.
*   **Security Stage:** Use **32 (Bit 5)** to "lock in" your verified script set, ensuring that any unauthorized modification to the scripts on the SD card prevents the vehicle from arming.

