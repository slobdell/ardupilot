---
layout: parameter
name: Q_TAILSIT_ENABLE
display_name: Tailsitter Enable
description: Master switch to enable Tailsitter VTOL logic.
default_value: 0
range: 0 1
units: 
group: Q
visual_asset_id: vtol_tailsitter_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduPlane/quadplane.cpp#L100
---

# Tailsitter Enable (Q_TAILSIT_ENABLE)

## Description
`Q_TAILSIT_ENABLE` activates the specialized physics and control models for **Tailsitter** aircraft. 

A Tailsitter is a VTOL plane that sits on its tail for takeoff and landing. Unlike a standard QuadPlane (which stays horizontal), a Tailsitter must rotate its entire body by 90 degrees to transition between hover and forward flight.

## Tuning & Behavior
*   **0:** Disabled. Standard QuadPlane/Fixed-Wing logic.
*   **1:** Enabled. Activates 90-degree frame rotation and tailsitter-specific mixing.
*   **Reboot Required:** Yes.