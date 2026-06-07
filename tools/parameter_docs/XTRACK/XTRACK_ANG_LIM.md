---
layout: parameter
name: XTRACK_ANG_LIM
display_name: "Crosstrack correction angle limit"
description: "Maximum allowed angle (in degrees) between current track and desired heading during waypoint navigation"
default_value: 45
range: 10 90
units: "deg"
group: Uncategorized
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduSub/Parameters.cpp#L151
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Crosstrack correction angle limit (XTRACK_ANG_LIM)

## Description
This parameter sets the maximum angle the vehicle (Submarine) is allowed to turn towards the track line to correct for crosstrack error. A higher value allows for more aggressive course corrections to return to the path quickly, while a lower value results in smoother, shallower intercept trajectories. This is crucial for towed systems or vehicles with high inertia to prevent oscillation around the track.

## The Mathematics
The navigation controller limits the heading error correction demand:

$$ \theta_{error} = \text{Target Bearing} - \text{Current Heading} $$
$$ |\theta_{correction}| \le \text{XTRACK_ANG_LIM} $$

## The Engineer's View
Defined in `ArduSub/Parameters.cpp`. This value is used by the WPNav library (specifically the crosstrack error controller) to clamp the output angle. It prevents the vehicle from turning 90 degrees to the track, which can be undesirable for ROVs with tethers.

## Tuning & Behavior
*   **Default Value:** 45 deg
*   **Range:** 10 - 90
*   **Effect of Increasing:** Faster return to track, potential for "S-turning" or oscillation.
*   **Effect of Decreasing:** Smoother, slower return to track. Better for stability.