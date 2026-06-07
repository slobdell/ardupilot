# Feedforward Mixing (KFF)

## Overview
The **KFF** parameter group (often appearing as `KFF_` or `MIX_`) configures **Feedforward** mixing for ArduPlane.

Feedforward provides an immediate control surface movement proportional to the pilot's stick input (or another control axis), bypassing the slower PID error-correction loops.

## Key Concepts

### 1. Rudder Mixing (`KFF_RDDRMIX`)
Used on aircraft without ailerons ("Rudder Only").
*   **Function:** It mixes the Roll controller output into the Rudder servo. This allows the autopilot to turn the plane using only the rudder.

### 2. Pitch Mixing (`KFF_THR2PTCH`)
Mixes throttle into the pitch axis.
*   **Function:** If your plane pitches up when you add power (due to motor thrust line), this parameter can automatically add down-elevator to compensate.

## Parameter Breakdown

*   **`KFF_RDDRMIX`**: Roll to Rudder feedforward gain.
*   **`KFF_THR2PTCH`**: Throttle to Pitch feedforward gain.

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.