# Brake Mode Configuration (BRAKE)

## Overview
The **BRAKE** parameter group configures the braking behavior for specific flight modes, notably **FlowHold** in ArduCopter.

**Note:** The standard "Brake" flight mode uses `LOIT_BRK_` parameters. The parameter here (`BRAKE_RATE`) specifically applies to the **FlowHold** mode, which is an optical-flow-based loiter that allows the vehicle to drift when sticks are released unless braking is engaged.

## Key Concepts

### 1. FlowHold Braking
In FlowHold mode, the vehicle tracks features on the ground. When the pilot releases the sticks:
*   The vehicle attempts to stop its drift.
*   **`BRAKE_RATE`** limits the maximum pitch/roll angle (or rate) used to achieve this stop.

## Parameter Breakdown

*   **`BRAKE_RATE`**: Maximum braking rate (deg/s) for FlowHold. Higher values mean sharper stops (more like Loiter). Lower values mean smoother, driftier stops.

## Integration Guide
*   **FlowHold:** Requires an Optical Flow sensor (e.g., HereFlow, CX-OF).
*   **Tuning:** If the vehicle stops too abruptly in FlowHold, reduce `BRAKE_RATE`.

## Developer Notes
*   **Library:** `ArduCopter/mode_flowhold.cpp`
*   **Context:** Unique to the FlowHold mode state machine.