---
layout: parameter
name: TECS_SPDWEIGHT
display_name: Speed vs Altitude Weight
description: Determines how the autopilot balances pitch and throttle to control airspeed versus altitude.
default_value: 1.0
range: 0 2.0
units: 
group: TECS
visual_asset_id: tecs_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_TECS/AP_TECS.cpp#L100
---

# Speed vs Altitude Weight (TECS_SPDWEIGHT)

## Description
`TECS_SPDWEIGHT` is the "Priority Slider" for Plane flight control.

TECS (Total Energy Control System) views the plane as a battery. Altitude is "Potential Energy" and Airspeed is "Kinetic Energy." This parameter tells the autopilot which one is more important to maintain.

*   **1.0 (Balanced):** The autopilot treats speed and altitude errors equally. It will use both pitch and throttle to fix errors.
*   **2.0 (Speed Priority):** The autopilot will prioritize maintaining airspeed at all costs. If the plane slows down, it will immediately trade altitude (pitch down) to regain speed. (Safest for preventing stalls).
*   **0.0 (Altitude Priority):** The autopilot will prioritize holding its height. It will trade airspeed to stay at the target altitude. (Riskier, as it could lead to a stall if the motor is weak).

## Tuning & Behavior
*   **Default Value:** 1.0.
*   **Recommendation:** Use **2.0** for takeoffs and landings to ensure you never stall near the ground. Use **1.0** for general cruising.
*   **Physics:**
    *   $$ \text{Total Energy} = \text{Height} + \frac{\text{Velocity}^2}{2g} $$
    *   `SPDWEIGHT` adjusts the weighting of the Kinetic Energy term in the pitch and throttle demand calculations.
