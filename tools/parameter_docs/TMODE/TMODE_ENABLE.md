---
layout: parameter
name: TMODE_ENABLE
display_name: Toy Mode Enable
description: Enables the simplified "Toy Mode" user interface, designed for mass-market consumer drones like the SkyViper.
default_value: 0
range: 0 2
units: 
group: TMODE
visual_asset_id: tmode_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/toy_mode.cpp#L21
---

# Toy Mode Enable (TMODE_ENABLE)

## Description
`TMODE_ENABLE` activates a simplified control scheme often used in consumer drones. 

Instead of the standard ArduPilot stick behaviors and button mappings, Toy Mode reconfigures the flight controller to respond to specific button layouts (like those found on SkyViper transmitters) and enables "easy" features like auto-takeoff on high throttle.

*   **0: Disabled (Default).** Standard ArduPilot behavior.
*   **1: Version 1 (SkyViper V2450GPS).**
*   **2: Version 2 (F412-based boards).**

## Tuning & Behavior
*   **Default Value:** 0.
*   **Warning:** Do not enable this on a custom-built drone unless you are specifically using a SkyViper transmitter, as it will drastically change how your sticks and buttons work.
*   **Reboot Required:** Yes.
