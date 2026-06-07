---
layout: parameter
name: BCN_TYPE
display_name: "Beacon based position estimation device type"
description: "What type of beacon based position estimation device is connected"
default_value: 0
range: 0 10
units: "Option"
group: BCN
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.cpp#L37
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Beacon/AP_Beacon.h#L126
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Beacon based position estimation device type (BCN_TYPE)

## Description
This parameter enables the Beacon driver and selects the specific hardware vendor connected to the autopilot. Beacon systems (often called Indoor GPS) provide high-precision position data (X, Y, Z) for environments where standard GPS is unavailable, such as indoors or under heavy canopy.

Setting this parameter allocates the necessary driver memory and starts the communication backend.

## The Mathematics
The value maps directly to a driver backend instantiation factory:

*   **0:** None (Disabled)
*   **1:** Pozyx (UWB)
*   **2:** Marvelmind (Ultrasound)
*   **3:** Nooploop (UWB)
*   **10:** SITL (Software In The Loop simulation)

## The Engineer's View
In `AP_Beacon::init()`, this parameter is read to switch-case the construction of `_driver`.
*   `Type::Pozyx` -> `AP_Beacon_Pozyx`
*   `Type::Marvelmind` -> `AP_Beacon_Marvelmind`
*   etc.

If set to **0**, `AP_Beacon::enabled()` returns `false`, effectively bypassing the entire library.

## Tuning & Behavior
*   **Reboot Required:** Yes. Changing this parameter requires a reboot to initialize the correct driver and allocate resources.
*   **Dependencies:** Enabling this is the first step. You must also configure the beacon's Origin (`BCN_LATITUDE`, etc.) if you want the vehicle to report global coordinates, or use `EK3_SRCx` parameters to tell the EKF to use Beacons as a position source.

