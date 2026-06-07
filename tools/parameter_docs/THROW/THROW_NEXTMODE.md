---
layout: parameter
name: THROW_NEXTMODE
display_name: Throw Mode Target Mode
description: Selects the flight mode the drone transitions to after a successful launch.
default_value: 18
range: 0 25
units: 
group: THROW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L757
---

# Throw Mode Target Mode (THROW_NEXTMODE)

## Description
`THROW_NEXTMODE` defines what the drone does after it successfully "catches itself" in the air.

*   **18 (Default):** Stay in Throw Mode. The drone will hover in place and wait for further commands.
*   **5: Loiter.** Transition immediately to GPS-based position hold.
*   **10: Auto.** Start the pre-programmed mission immediately after the toss.

## Tuning & Behavior
*   **Default:** 18.
*   **Recommendation:** Set to **5 (Loiter)** if you want the drone to hold its position perfectly after you throw it.
*   **Significance:** Allows for fully autonomous "toss and go" mission starts.