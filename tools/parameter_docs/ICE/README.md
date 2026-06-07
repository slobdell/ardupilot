# Internal Combustion Engine (ICE)

## Overview
The **ICE** parameter group configures the management of **Internal Combustion Engines** (Gas/Nitro). This library automates the starting sequence, idle control, and health monitoring of liquid-fueled engines.

In ArduPilot, an engine is managed via a dedicated "Starter" output and an "Ignition/Throttle" output.

## Key Concepts

### 1. Automated Starting
The autopilot can manage the electric starter motor to crank the engine until a sustained RPM is detected.
*   **`ICE_STARTER_TIME`**: How long to run the starter motor per attempt.
*   **`ICE_STRT_MX_RTRY`**: Number of attempts before giving up.
*   **`ICE_START_PCT`**: Throttle percentage applied during cranking.

### 2. Idle Management
Once started, the engine must maintain an "Idle" state without stalling.
*   **`ICE_IDLE_RPM`**: The target RPM for idling on the ground.
*   **`ICE_IDLE_PCT`**: The baseline throttle percentage to maintain idle.

### 3. RPM Monitoring
Requires an RPM sensor (Hall Effect or Optical) to be configured.
*   **`ICE_RPM_CHAN`**: Maps which RPM sensor instance (1 or 2) corresponds to the engine.

## Parameter Breakdown

*   **`ICE_ENABLE`**: Master switch.
*   **`ICE_START_DELAY`**: Delay between enabling ignition and cranking the starter.
*   **`ICE_REDLINE_RPM`**: Maximum safe RPM (used for warnings/governor).

## Integration Guide
1.  **Outputs:** Map a servo to `Ignition` (Function 67) and `Starter` (Function 68).
2.  **Sensors:** Ensure `RPM_TYPE` is set and providing a valid signal.
3.  **Tuning:** Adjust `ICE_IDLE_PCT` so the engine stays running reliably but the drone/plane doesn't creep forward on the ground.

## Developer Notes
*   **Library:** `libraries/AP_ICEngine`.
*   **State Machine:** Transitions through `IDLE`, `STARTING`, `RUNNING`, and `STOPPING`.