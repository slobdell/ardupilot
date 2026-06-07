---
layout: parameter
name: ATC_RAT_YAW_ILMI
display_name: Yaw Axis Rate I-Leak Minimum
description: Specifically for Helicopters. Controls the minimum rate at which the yaw integrator (I-term) "leaks" back to zero. Prevents tail heading memory from staying "stuck."
default_value: 0.02
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_yaw_ilmi_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L42
---

# Yaw Axis Rate I-Leak Minimum (ATC_RAT_YAW_ILMI)

## Description
`ATC_RAT_YAW_ILMI` is a specialized "memory cleanup" feature for the tail (yaw axis) of **Traditional Helicopters**.

Most helicopters use a mechanical tail rotor or a servo-driven system to control heading. These systems often experience "Tail Stiction" or ground interaction. The I-term learns to fight these forces to keep the tail straight. However, if the tail "sticks" and then suddenly releases, a wound-up I-term can cause the heli to spin violently.

"Leakiness" allows the tail controller to "forget" its old corrections over time. `ATC_RAT_YAW_ILMI` determines the minimum speed of this forgetting process. It ensures the tail always feels "current" and doesn't hold onto stale motor authority.

*   **Higher Value:** The tail memory clears faster. The heli feels more reactive.
*   **Lower Value:** The tail memory persists longer. Better for maintaining a rock-solid heading during long, slow maneuvers.

**Note:** This is an `AC_HELI_PID` specific parameter and is not used on standard Multirotors.

## The Mathematics
The yaw integrator ($\text{Int}$) is decayed every time step ($dt$):

$$ \text{Int}_{new} = \text{Int}_{prev} \cdot (1.0 - \text{LeakRate} \cdot dt) $$

Where the Leak Rate is determined by `ATC_RAT_YAW_ILMI`.

This provides a "High-Pass" effect, filtering out the DC-offset (permanent bias) of the integrator so that it doesn't become a hard mechanical limit.

## The Engineer's View
This parameter is the `_leak_min` member in the `AC_HELI_PID` class.

Yaw leakiness is particularly important for helicopters because as the main rotor RPM changes, the required tail rotor torque changes instantly. A leaky integrator allows the software to quickly "forget" the old torque requirement and adapt to the new one, preventing the tail from "jumping" during throttle changes.

## Tuning & Behavior
*   **Default Value:** 0.02 (2% decay per second)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** Tail becomes more "relaxed." Better for learning scale-like turns.
*   **Effect of Decreasing:** Tighter tail authority. The nose stays exactly where it is pointed, even if you are changing throttle rapidly.

### Use Case Recommendations
*   **Scale Flying (Realism):** **Increase to 0.05.** Allows the tail to drift slightly in a realistic way, requiring more pilot coordination.
*   **Precision Industrial Mapping:** **Decrease to 0.01.** Heading accuracy is the priority; the I-term must be as persistent as possible.
*   **General Hobby Flight:** **Keep at 0.02.**

### Troubleshooting
*   **Scenario:** After finishing a yaw turn, the tail "overshoots" and then slowly (over 2-3 seconds) moves back to the target heading.
    *   **Diagnosis:** Yaw I-term windup.
    *   **Fix:** Increase `ATC_RAT_YAW_ILMI` to 0.05.