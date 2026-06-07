---
layout: parameter
name: MOT_HOVER_LEARN
display_name: Hover Value Learning
description: Controls whether the hover throttle (MOT_THST_HOVER) is learned automatically.
default_value: 2
range: 0 2
units: 
group: MOT
visual_asset_id: mot_hover_learn_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_Motors/AP_MotorsMulticopter.cpp#L143
---

# Hover Value Learning (MOT_HOVER_LEARN)

## Description
`MOT_HOVER_LEARN` allows the drone to figure out how much throttle is needed to hover and save that value.

*   **0: Disabled.** Uses the manually set `MOT_THST_HOVER` and never changes it.
*   **1: Learn.** Updates the hover estimate in RAM while flying, but **does not save** it to EEPROM on disarm. Good for testing payloads without messing up your base tune.
*   **2: Learn and Save (Default).** Continuously updates the hover estimate and saves it to `MOT_THST_HOVER` when you disarm.

## The Mathematics
The autopilot monitors the average throttle output while in "AltHold" or "Loiter" when the vertical velocity is near zero. It passes this through a slow low-pass filter to update the `MOT_THST_HOVER` value.

## The Engineer's View
Knowing the correct hover throttle is critical for the Altitude Controller (`PSC_ACCZ_P` and `PSC_ACCZ_I`). If the hover throttle is wrong, the drone will jump up or drop down when engaging AltHold, and the altitude hold performance will be "bouncy".

## Tuning & Behavior
*   **Default Value:** 2 (Learn and Save)
*   **Recommendation:** Leave at **2** for most users.
*   **Payload Drones:** If you constantly swap between heavy payloads (camera) and no payload, set to **1** (Learn). This way, the drone learns the weight for the current flight, but reverts to the "base weight" setting when you reboot, preventing it from taking off like a rocket if you remove the payload but it "remembered" the heavy throttle settings.