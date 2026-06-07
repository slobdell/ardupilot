---
layout: parameter
name: ATC_RAT_RLL_ILMI
display_name: Roll Axis Rate I-Leak Minimum
description: Specifically for Helicopters. Controls the minimum rate at which the roll integrator (I-term) "leaks" or decays back to zero. Prevents the I-term from staying "stuck" after a maneuver.
default_value: 0.02
range: 0 1.0
units: 
group: ATC
visual_asset_id: atc_rat_rll_ilmi_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.cpp#L42
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_PID/AC_HELI_PID.h#L34
---

# Roll Axis Rate I-Leak Minimum (ATC_RAT_RLL_ILMI)

## Description
`ATC_RAT_RLL_ILMI` is a specialized "memory cleanup" feature for **Traditional Helicopters**. 

In PID control, the **Integral (I) term** has a "memory"—it remembers past errors and builds up authority to fix them. On helicopters, this memory can be problematic. Because helis have complex mechanical linkagess and ground interactions, the I-term can build up "fake" authority while the heli is sitting on the ground or during a slow takeoff. 

"Leakiness" allows this memory to slowly evaporate over time. `ATC_RAT_RLL_ILMI` sets the minimum speed of that evaporation. It ensures that the helicopter's attitude memory is always "fresh" and doesn't contain stale corrections from a maneuver you finished several seconds ago.

*   **Higher Value:** The I-term decays faster. The heli feels more "natural" and less "locked-in" by software memory.
*   **Lower Value:** The I-term stays around longer. Better for holding exact angles in steady-state hover.

**Note:** This parameter is unique to the `AC_HELI_PID` library and is not used by standard multirotors (Quads/Octos).

## The Mathematics
The integrator ($\text{Int}$) is modified by a decay factor every time step ($dt$):

$$ \text{Int}_{new} = \text{Int}_{prev} \cdot (1.0 - \text{LeakRate} \cdot dt) $$ 

Where the Leak Rate is determined by `ATC_RAT_RLL_ILMI`. 

This effectively acts as a "High-Pass Filter" on the integrator, ensuring that it only focuses on recent errors and ignores errors from the distant past.

## The Engineer's View
This parameter is the `_leak_min` member in the `AC_HELI_PID` class.

Helicopters use a "Leaky PID" architecture because of the unique way their swashplates interact with the rotor head. Without a leak, the integrator would constantly fight the mechanical gyroscopic precession of the rotor, leading to "I-term stall" where the heli becomes unresponsive to small stick movements.

## Tuning & Behavior
*   **Default Value:** 0.02 (2% decay per second)
*   **Range:** 0.0 - 1.0
*   **Effect of Increasing:** The helicopter feels more "loose." It will be less prone to "I-term kickback" after a hard stop.
*   **Effect of Decreasing:** Tighter attitude hold. The helicopter will hold its tilt angle more accurately in wind.

### Use Case Recommendations
*   **3D Aerobatics:** **Increase to 0.05 - 0.10.** Prevents the integrator from building up during rapid, repeating flips and rolls.
*   **Scale / Civilian Helicopter:** **Keep at 0.02.** Provides the best balance between stability and mechanical safety.
*   **Large Gas Helicopters:** **Set to 0.01.** Heavy rotor heads have massive inertia and need a very stable I-term to maintain level flight.

### Troubleshooting
*   **Scenario:** After performing a sharp roll and stopping, the helicopter slowly "drifts" back a few degrees in the opposite direction.
    *   **Diagnosis:** I-term Windup. The "memory" of the maneuver is still pushing the heli.
    *   **Fix:** Increase `ATC_RAT_RLL_ILMI` to 0.04.