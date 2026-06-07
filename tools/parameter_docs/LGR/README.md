# Landing Gear Configuration (LGR)

## Overview
The **LGR** parameter group configures the **Retractable Landing Gear** management system.

ArduPilot can autonomously manage the deployment and retraction of landing gear to improve aerodynamics in flight and ensure safety during landing.

## Key Concepts

### 1. Automatic Deployment (`LGR_DEPLOY_ALT`)
The landing gear will automatically deploy (descend) when the vehicle descends below this altitude (meters) above ground.

### 2. Automatic Retraction (`LGR_RETRACT_ALT`)
The landing gear will automatically retract (lift) when the vehicle climbs above this altitude after takeoff.

### 3. Weight on Wheels (WOW)
Some advanced airframes use a sensor (`LGR_WOW_PIN`) to detect when the aircraft is actually touching the ground, preventing the gear from retracting while the vehicle's weight is on it.

## Parameter Breakdown

*   **`LGR_ENABLE`**: Master switch.
*   **`LGR_STARTUP`**: Behavior at boot (Deploy, Retract, or No Change).
*   **`LGR_OPTIONS`**: Bitmask for behavior (e.g., override deployment during emergency landing).

## Integration Guide
1.  **Pin:** Map a servo output to `Landing Gear` (Function 29).
2.  **Enable:** Set `LGR_ENABLE = 1`.
3.  **Config:** Set the deploy/retract altitudes based on your operational needs.
4.  **RC:** Map an RC channel to `Landing Gear` (RC Option 29) to allow manual override.

## Developer Notes
*   **Library:** `libraries/AP_LandingGear`.