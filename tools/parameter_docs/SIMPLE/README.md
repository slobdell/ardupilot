# Simple Mode Configuration (SIMPLE)

## Overview
The **SIMPLE** parameter group (specifically `SIMPLE`) configures the **Simple and Super Simple** pilot assistance modes for ArduCopter.

These modes decouple the drone's movement from its heading, making it much easier for beginners to fly or for experts to maintain orientation at long distances.

## Key Concepts

### 1. Simple Mode
In standard flight, pushing the stick "Forward" moves the drone towards its own nose. If the drone rotates 180°, "Forward" on the stick moves the drone toward the pilot.
*   **Simple Mode Fix:** When enabled, "Forward" on the stick always moves the drone away from the pilot (based on the heading when it was armed), regardless of the drone's current rotation.

### 2. Super Simple Mode
*   **Super Simple Mode Fix:** Decouples movement from both heading and initial arming orientation. "Forward" on the stick always moves the drone away from the **Home position** (GPS based). Even if the drone flies behind the pilot, pushing "Away" still moves it further away.

## Parameter Breakdown

*   **`SIMPLE`**: Bitmask of which flight mode switch positions have Simple mode enabled.

## Integration Guide
*   **Setup:** Use the "Flight Modes" screen in Mission Planner to check the "Simple" or "SSimple" boxes for specific switch positions.
*   **Prerequisite:** Super Simple mode requires a valid GPS lock.

## Developer Notes
*   **Library:** `ArduCopter/control_simple.cpp`.