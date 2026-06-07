---
layout: parameter
name: ADSB_RF_SELECT
display_name: Transceiver RF selection
description: Transceiver RF selection for Rx enable and/or Tx enable. This only effects devices that can Tx and/or Rx. Rx-only devices should override this to always be Rx-only.
default_value: 1
range: 
units: 
group: ADSB
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_ADSB/AP_ADSB.cpp
---

# Transceiver RF selection (ADSB_RF_SELECT)

## Description
Selection of Rx/Tx modes for the ADSB transceiver.

## Tuning & Behavior
*   **Default Value:** 1 (Rx Enabled)
*   **Bitmask:** 0:Rx, 1:Tx