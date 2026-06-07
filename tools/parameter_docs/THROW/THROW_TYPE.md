---
layout: parameter
name: THROW_TYPE
display_name: Throw Mode Launch Type
description: Selects whether the vehicle is being thrown or dropped.
default_value: 0
range: 0 1
units: 
group: THROW
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/ArduCopter/Parameters.cpp#L764
---

# Throw Mode Launch Type (THROW_TYPE)

## Description
`THROW_TYPE` defines the initial motion the drone expects when using **Throw Mode**. 

Throw mode allows a pilot to start the drone without using a transmitter or ground station – the drone senses it is "falling" or "flying" and starts its motors automatically to stabilize.

*   **0: Upward Throw.** The drone expects to be tossed up into the air. It waits for the peak of the arc (near zero vertical velocity) before starting the motors.
*   **1: Drop.** The drone expects to be released from a high point (e.g. from a balloon or a hand held above the head). It starts the motors as soon as it detects free-fall.

## Tuning & Behavior
*   **Default:** 0.
*   **Safety:** **NEVER** use Throw mode indoors. Ensure you toss the drone at least 3-5 meters away from you.