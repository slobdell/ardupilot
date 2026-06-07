# Guided Mode Configuration (GUID)

## Overview
The **GUID** parameter group configures the behavior of the **Guided** flight mode. Guided mode is primarily used for external control by a Ground Control Station (GCS) or a Companion Computer (e.g., "Click to Fly Here" or ROS navigation).

## Key Concepts

### 1. Guided Options (`GUID_OPTIONS`)
A bitmask that alters Guided mode logic.
*   **Allow Arming:** Whether the vehicle can be armed while in Guided mode.
*   **Ignore Pilot Stick:** If set, moving the RC sticks won't override the Guided mission (Advanced).
*   **Face Next WP:** Controls yaw behavior during guided movement.

### 2. Timeout (`GUID_TIMEOUT`)
Defines how long the autopilot will wait for a new Guided command (e.g., from a script or companion computer) before taking failsafe action (usually Hover or RTL). This is critical for safety in the event of a companion computer crash.

## Parameter Breakdown

*   **`GUID_OPTIONS`**: Bitmask of behaviors.
*   **`GUID_TIMEOUT`**: Command timeout (seconds).

## Integration Guide
*   **Companion Computers:** Set `GUID_TIMEOUT` to a value slightly higher than your navigation loop rate (e.g., if ROS sends targets at 5Hz, set timeout to 0.5s or 1.0s).

## Developer Notes
*   **Library:** `ArduCopter/mode_guided.cpp`, `ArduPlane/mode_guided.cpp`.