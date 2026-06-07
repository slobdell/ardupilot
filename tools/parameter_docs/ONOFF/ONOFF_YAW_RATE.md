---
layout: parameter
name: ONOFF_YAW_RATE
display_name: "Yaw rate for on/off servos"
description: "Rate of change of yaw for on/off servos"
default_value: 9.0f
range: 0 50
units: "deg/s"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/AntennaTracker/Parameters.cpp#L112
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Yaw rate for on/off servos (ONOFF_YAW_RATE)

## Description
This parameter defines the estimated angular velocity of the Yaw axis for Antenna Trackers using **On/Off** (Bang-Bang) control mechanisms. It allows the tracker to estimate how long to activate the motor to achieve a specific heading change.

## The Mathematics
$$ \Delta t_{\text{yaw}} = \frac{|\Delta \text{Heading}|}{\text{ONOFF_YAW_RATE}} $$

## The Engineer's View
Defined in `AntennaTracker/Parameters.cpp`. Matches `ONOFF_PITCH_RATE` but for the yaw axis.

## Tuning & Behavior
*   **Default Value:** 9.0 deg/s
*   **Measurement:** Time a 360-degree rotation and calculate the rate: $ 360 / \text{Time} $.