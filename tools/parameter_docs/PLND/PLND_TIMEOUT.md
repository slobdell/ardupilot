---
default_value: 4
description: Time for which vehicle continues descend even if target is lost before attempting a retry.
display_name: PrecLand retry timeout
group: PLND
investigation_status: complete
layout: parameter
name: PLND_TIMEOUT
range: 0 20
source_code_urls:
- https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PrecLand/AC_PrecLand.cpp#L149
units: s
visual_asset_id: null
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# PrecLand retry timeout (PLND_TIMEOUT)

## Description
This parameter sets the "Grace Period" for target loss during a precision landing. It defines how many seconds the vehicle is allowed to continue its descent after it stops seeing the landing target.

If the target reappears within this window, the landing continues normally. If the timeout expires and the target is still missing, the vehicle will take action based on `PLND_STRICT` (usually climbing back up for a retry or switching to a standard land).

## The Mathematics
The system maintains a timer ($t_{lost}$) that resets whenever a valid target measurement is received.

$$ \text{IF } (t_{now} - t_{last\_seen} > PLND\_TIMEOUT) \rightarrow \text{Trigger Retry Action} $$

This duration allows the vehicle to "fly through" brief sensor outages caused by sun glare, dust, or momentary signal blockage.

## The Engineer's View
In `AC_PrecLand.cpp`, this maps to `_retry_timeout_sec`. 
The `TargetState` transitions from `TARGET_FOUND` to `TARGET_RECENTLY_LOST` as soon as the sensor data stops. The landing state machine (often implemented in the vehicle's `mode_land.cpp`) checks this timeout.
*   Note that `AC_PrecLand` also has a hardcoded `LANDING_TARGET_TIMEOUT_MS` (2000ms) which controls the "Healthy" status of the sensor itself, but `PLND_TIMEOUT` is the user-tunable delay for the physical landing behavior.

## Tuning & Behavior
*   **Default Value:** 4 seconds.
*   **Agile Aircraft:** Can use a shorter timeout (e.g., 2s) to initiate retries faster.
*   **High Dust/Shadow Environments:** Increase to **5-8 seconds** to allow the vehicle to drop through the obscuration and hope the target reappears at a lower altitude.
*   **0:** Disables the grace period; a retry is triggered as soon as the sensor misses a frame.
