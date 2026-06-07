---
layout: parameter
name: PLND_RET_MAX
display_name: Precision Land Maximum Retries
description: The maximum number of times the vehicle will attempt to re-acquire the target if it is lost during the landing.
default_value: 4
range: 0 10
units: 
group: PLND
visual_asset_id: precland_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L112
---

# Precision Land Maximum Retries (PLND_RET_MAX)

## Description
`PLND_RET_MAX` limits how many "Bail-Outs" the drone is allowed to perform.

If the drone loses the target while landing (due to glare, blockage, etc.), and `PLND_STRICT` is set to **1 (Retry)**, the drone will climb back up to its staging altitude and try again. This parameter ensures the drone doesn't do this forever and waste its battery. 

*   **Default Value:** 4 retries.
*   **0:** Disable retries. The drone will follow the `PLND_STRICT` fallback on the first loss.

## Tuning & Behavior
*   **Default Value:** 4.
*   **Recommendation:** Leave at **4**. If the drone hasn't found the target after 4 tries, it's statistically unlikely to find it on the 5th, and it's better to land or RTL.