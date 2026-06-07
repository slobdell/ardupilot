---
default_value: 1.0
description: Used to decouple pitch from forward/vertical motion. 0 to disable, 1.2
  normal
display_name: Forward/vertical to pitch decoupling factor
group: FV
investigation_status: complete
layout: parameter
name: FV_CPLNG_K
range: 0.0 1.5
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_Motors6DOF.cpp#L91
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_Motors6DOF.h#L68
units: null
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Forward/vertical to pitch decoupling factor (FV_CPLNG_K)

## Description
This parameter is specific to **Vectored ROVs** (like the BlueROV2) running the Sub firmware. It compensates for the physical tendency of some ROV frames to pitch up/down when applying forward or vertical thrust due to drag and center-of-mass offsets.

By adjusting this factor, the mixer limits the output of specific thrusters to prevent the vehicle from pitching destabilizingly during high-speed maneuvers.

## The Mathematics
The parameter sets a dynamic limit on the `Forward` thrust component based on the current `Throttle` (Vertical) demand.

$$ Limit = 1.0 - (FV\_CPLNG\_K \times |Throttle|) $$
$$ Thrust_{Forward\_Limited} = \text{constrain}(Thrust_{Forward}, -Limit, Limit) $$

This logic essentially says: "If you are applying full vertical power, reduce the allowed forward power to prevent hydrodynamic instability."

## The Engineer's View
In `AP_Motors6DOF::output_armed_stabilizing_vectored()`, this parameter is read into `_forwardVerticalCouplingFactor`.

It is used to calculate `forward_coupling_limit`. This limit is then applied selectively to the rear thrusters (depending on direction of travel) to decouple the forward/vertical hydrodynamic coupling.
*   The logic checks `forward_coupling_direction` to identify which thrusters need limiting.

## Tuning & Behavior
*   **Default Value:** 1.0
*   **Range:** 0.0 to 1.5
*   **Value 0.0:** Disabled. Full forward thrust allowed regardless of vertical thrust.
*   **Value 1.0:** Standard decoupling.
*   **Effect of Increasing:** Increases the "safety margin," restricting forward speed more aggressively when vertical thrusters are active.
*   **Symptom:** If your ROV does a backflip or pitches violently when you apply full throttle + full forward, **increase** this value.
