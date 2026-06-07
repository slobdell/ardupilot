---
layout: parameter
title: PLDP_THRESH
name: Payload Place thrust ratio threshold
group: PLDP
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/ArduCopter/Parameters.cpp#L1177
---

# PLDP_THRESH: Payload Place thrust ratio threshold

## Description
Ratio of vertical thrust during descent below which payload touchdown will trigger.

## Values
- **Range:** 0.5 to 0.9
- **Default:** 0.9

## Description
This parameter sets the sensitivity for detecting when the payload has touched the ground.

- **Mechanism:** As the drone lowers the payload, the weight on the motors decreases. When the throttle output drops to this percentage of the average hover throttle (while descending), the autopilot assumes the load is now supported by the ground.
- **Example:** If hover throttle is 50% and `PLDP_THRESH` is 0.9, detection triggers when throttle drops to 45% (0.9 * 50%).
- **Lower Value:** Harder to trigger. Requires more weight off-loading (slacker line) before release.
- **Higher Value:** Easier to trigger. Risk of premature release if the drone descends quickly.

