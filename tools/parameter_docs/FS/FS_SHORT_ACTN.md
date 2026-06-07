---
layout: parameter
name: FS_SHORT_ACTN
display_name: Short Failsafe Action (Plane)
description: Defines the action taken when radio control is lost for a brief period.
default_value: 0
range: 0 2
units: 
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduPlane/Parameters.cpp#L465
---

# Short Failsafe Action (FS_SHORT_ACTN)

## Description
`FS_SHORT_ACTN` defines the immediate response to a radio signal loss. It triggers after [FS_SHORT_TIMEOUT](FS_SHORT_TIMEOUT.html) (typically 1.5 seconds).

*   **0: Circle (Standard).** The plane enters Circle mode and holds its current location.
*   **1: RTL.** The plane starts returning home immediately.
*   **2: FBWA.** Fallback to level flight.

## Tuning & Behavior
*   **Default:** 0.
*   **Best Practice:** Leave at **0 (Circle)** to allow the link a few seconds to recover before committing to a full RTL return.