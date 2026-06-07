---
layout: parameter
name: FOLL_OFS_TYPE
display_name: Follow Offset Type
description: Selects the frame of reference for the follow distance and angle (North-East-Down or Relative to Target Heading).
default_value: 0
range: 0 1
units: 
group: FOLL
visual_asset_id: follow_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Follow/AP_Follow.cpp#L105
---

# Follow Offset Type (FOLL_OFS_TYPE)

## Description
`FOLL_OFS_TYPE` determines how the drone calculates where to sit in relation to the target.

*   **0: North-East-Down.** The drone stays at a fixed compass offset (e.g., 5m North and 5m East). Even if the target turns, the drone stays on the North side.
*   **1: Relative to Target.** The drone stays at a fixed offset relative to the target's nose (e.g., 5m behind and 5m to the right). If the target turns, the drone "Orbits" around to stay in the same spot relative to the target's view. (Best for filming vehicles).