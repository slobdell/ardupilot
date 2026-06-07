---
layout: parameter
name: LEAK1_TYPE
display_name: Leak Detector Type (Sensor 1)
description: Enables the primary leak detector and selects the signal type (Analog or Digital).
default_value: 0
range: 0 1
units: 
group: LEAK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_LeakDetector/AP_LeakDetector.cpp#L28
---

# Leak Detector Type (LEAK1_TYPE)

## Description
`LEAK1_TYPE` enables the first leak detection sensor. This is a critical safety feature for ROVs (ArduSub) and boats to detect water ingress before it causes a short circuit or catastrophic failure.

*   **0: Disabled.**
*   **1: Analog.** For sensors that output a varying voltage (common for simple resistive probes).
*   **2: Digital.** For sensors that output a simple HIGH/LOW signal.

## Tuning & Behavior
*   **Reboot Required:** Yes.
*   **Integration:** Once enabled, you must also set the physical pin number using [LEAK1_PIN](LEAK1_PIN.html).
*   **Safety:** When a leak is detected, ArduPilot will trigger a GCS warning and can be configured to perform a failsafe action (like surfacing or stopping).