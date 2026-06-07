---
layout: parameter
name: QWIK_Y_PI_RATIO
display_name: "Quicktune Yaw PI ratio"
description: "Ratio between P and I gains for the yaw axis. Determines how the yaw integral gain scales during tuning."
default_value: 10.0
range: 1.0 20
units: "Ratio"
group: QWIK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L92
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Quicktune Yaw PI ratio (QWIK_Y_PI_RATIO)

## Description
This parameter defines the fixed relationship (ratio) between the Proportional (P) and Integral (I) gains for the **Yaw** axis during the Quicktune process. 

Because yaw dynamics are typically much slower and less sensitive than roll or pitch, the integrator gain ($K_i$) is usually set much lower than the proportional gain. Maintaining this ratio ensures that Quicktune doesn't over-power the yaw integrator, which could lead to slow, oscillating "wagging" of the tail.

## The Mathematics
During the tuning process, whenever Quicktune adjusts the Yaw P gain ($K_{p\_yaw}$), it automatically calculates the new Yaw I gain ($K_{i\_yaw}$) using this ratio ($\gamma_{yaw}$):

$$ K_{i\_yaw} = \frac{K_{p\_yaw}}{\gamma_{yaw}} $$

Where $\gamma_{yaw}$ is `QWIK_Y_PI_RATIO`. 

For example, with the default ratio of **10.0**, if Quicktune finds an optimal Yaw P of 0.5, it will automatically set the Yaw I to 0.05.

## The Engineer's View
In `AP_Quicktune::adjust_gain()` (`libraries/AP_Quicktune/AP_Quicktune.cpp`):
1.  The code identifies when the Yaw axis P gain is being modified.
2.  It checks for FeedForward (`FF`). If `FF > 0`, the integrator is typically handled independently of P, and this ratio is bypassed.
3.  Otherwise, it applies the `y_pi_ratio` specifically. 
4.  This high default value (10.0 vs 1.0 for roll/pitch) reflects the engineering reality that Yaw requires a much wider gap between instantaneous response (P) and long-term error correction (I) to remain stable on most airframes.

## Tuning & Behavior
*   **Default Value:** 10.0.
*   **Range:** 1.0 to 20.0.
*   **Effect of Increasing:** Results in a much lower relative I gain for yaw. Recommended for vehicles that "tail-wag" or feel nervous in the yaw axis.
*   **Effect of Decreasing:** Results in a higher relative I gain. Only recommended if the vehicle fails to hold its heading against constant torque or wind.

