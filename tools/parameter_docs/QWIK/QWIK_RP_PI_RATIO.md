---
layout: parameter
name: QWIK_RP_PI_RATIO
display_name: "Quicktune roll/pitch PI ratio"
description: "Ratio between P and I gains for roll and pitch. Determines how the integral gain scales with proportional gain during tuning."
default_value: 1.0
range: 1.0 2.0
units: "Ratio"
group: QWIK
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Quicktune/AP_Quicktune.cpp#L85
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Quicktune roll/pitch PI ratio (QWIK_RP_PI_RATIO)

## Description
This parameter defines the fixed relationship (ratio) between the Proportional (P) and Integral (I) gains that Quicktune maintains while it searches for the optimal tune for Roll and Pitch. 

In many flight control systems, the P and I gains are "coupled"—as you increase the responsiveness (P), you must also increase the "correction force over time" (I) to maintain a balanced feel and prevent drift. This parameter automates that coupling, ensuring that as Quicktune pushes for higher performance, it keeps the integrator balanced.

## The Mathematics
During the tuning process, whenever Quicktune adjusts the P gain ($K_p$), it automatically calculates the new I gain ($K_i$) using this ratio ($\gamma$):

$$ K_i = \frac{K_p}{\gamma} $$

Where $\gamma$ is `QWIK_RP_PI_RATIO`. 

For example, if the ratio is **1.0**, the I gain will always equal the P gain. If the ratio is **2.0**, the I gain will be exactly half of the P gain.

## The Engineer's View
In `AP_Quicktune::adjust_gain()` (`libraries/AP_Quicktune/AP_Quicktune.cpp`):
1.  The code identifies when a P gain is being modified.
2.  It checks if FeedForward (`FF`) is present. If `FF > 0`, the system assumes a more advanced control model where `I` is matched to `FF` for a 1-second time constant, and this ratio is ignored.
3.  If no FF is used, it reads `rp_pi_ratio` and performs the division: `set_param_value(iname, value/pi_ratio)`.
4.  This ensures that the "Integrator Time Constant" remains consistent throughout the entire automated tuning session, preventing the aircraft from becoming sluggish or "drifty" while the P gain is being swept.

## Tuning & Behavior
*   **Default Value:** 1.0 (Balanced).
*   **Range:** 1.0 to 2.0.
*   **Effect of Increasing:** Results in a lower relative I gain. This can make the vehicle feel less "locked-in" but reduces the risk of low-frequency oscillations.
*   **Effect of Decreasing:** Results in a higher relative I gain, providing stronger resistance to external disturbances (like wind) but potentially causing slow "wandering" if set too low.

