---
layout: parameter
name: ATC_RAT_PIT_ILMI
display_name: Pitch Axis Rate I-Leak Minimum
description: Specifically for Helicopters. Controls the minimum rate at which the pitch integrator (I-term) "leaks" back to zero. Prevents longitudinal attitude memory from staying "stuck."
default_value: 0.02
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_pit_ilmi_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L42
---

# Pitch Axis Rate I-Leak Minimum (ATC_RAT_PIT_ILMI)

## Description
`ATC_RAT_PIT_ILMI` is a "memory management" feature for the pitch axis of **Traditional Helicopters**.

Helicopter pitch control is complex because the rotor disc acts like a giant gyroscope. When you command the heli to tilt forward, the I-term builds up authority to achieve that tilt. On the ground or during slow takeoff, the I-term can build up "false" corrections. 

"Leakiness" allows this software memory to slowly fade away over time. `ATC_RAT_PIT_ILMI` determines the speed of this fade. It ensures the helicopter always has a "fresh" sense of level and doesn't get stuck leaning forward or backward because of a correction that happened several seconds ago.

*   **Higher Value:** The pitch memory clears faster. The heli feels more reactive and "natural."
*   **Lower Value:** The pitch memory persists longer. Better for maintaining exact pitch angles during long, fast forward flight.

**Note:** This is an `AC_HELI_PID` specific parameter and is not used on standard Quads or Octocopters.

## The Mathematics
The pitch integrator ($\text{Int}$) is decayed every time step ($dt$):

$$ \text{Int}_{new} = \text{Int}_{prev} \cdot (1.0 - \text{LeakRate} \cdot dt) $$

Where the Leak Rate is set by `ATC_RAT_PIT_ILMI`.

**Physical Meaning:** This acts as a "forgetting factor." It prevents the integrator from "stalling" at a fixed value, which is critical for the rotating physics of a mechanical rotor head.

## The Engineer's View
This parameter is the `_leak_min` member in the `AC_HELI_PID` class.

Longitudinal (pitch) leakiness is especially important for helicopters because they are often physically nose-heavy or tail-heavy. The leak ensures that the software-learned "trim" doesn't become dangerous if the airframe's balance shifts (e.g., during high-speed forward flight).

## Tuning & Behavior
*   **Default Value:** 0.02 (2% decay per second)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** The helicopter becomes more forgiving during "punchy" pitch moves. Less risk of the nose "jumping" after you center the stick.
*   **Effect of Decreasing:** Tighter pitch authority. Better for heavy helis that need constant correction to stay level.

### Use Case Recommendations
*   **3D Smack Flight:** **Increase to 0.05.** Prevents "longitudinal memory" from ruining rapid vertical/pitch transitions.
*   **Heavy Cargo Heli:** **Decrease to 0.01.** Ensures the heli stays perfectly level even with an off-center payload.
*   **Scale Heli:** **Keep at 0.02.**

### Troubleshooting
*   **Scenario:** After stopping forward flight, the helicopter's nose "bobs" up and then stays slightly elevated for several seconds.
    *   **Diagnosis:** Stale I-term memory (Windup).
    *   **Fix:** Increase `ATC_RAT_PIT_ILMI` to 0.04.