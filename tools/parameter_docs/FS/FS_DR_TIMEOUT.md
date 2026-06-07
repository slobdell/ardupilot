---
layout: parameter
name: FS_DR_TIMEOUT
display_name: Dead Reckoning Failsafe Timeout
description: The maximum time (in seconds) the drone will fly using dead-reckoning before it gives up and performs a vertical landing.
default_value: 30
range: 0 120
units: s
group: FS
visual_asset_id: failsafe_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L101
---

# Dead Reckoning Failsafe Timeout (FS_DR_TIMEOUT)

## Description
`FS_DR_TIMEOUT` defines how long you trust your drone to "Guess" its way home.

Dead reckoning becomes more inaccurate the longer it runs. If the drone hasn't found its home or regained GPS within this many seconds, it will stop its horizontal movement and land vertically to prevent drifting miles away into unknown territory.