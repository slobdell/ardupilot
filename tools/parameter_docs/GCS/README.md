# Ground Control Station Interface (GCS)

## Overview
The **GCS** parameter group configures the communication and telemetry behavior between the autopilot and the **Ground Control Station** (e.g., Mission Planner, QGroundControl).

While most MAVLink settings are in the `SERIAL` and `MAV` groups, the `GCS` group handles global telemetry options that affect all active MAVLink links.

## Key Concepts

### 1. PID Tuning Streams (`GCS_PID_MASK`)
To tune a drone effectively, the pilot needs to see what the PID controllers are doing in real-time. This parameter enables the broadcast of `PID_TUNING` MAVLink messages.
*   **Visualization:** When enabled, the GCS can draw real-time graphs of "Target Rate" vs "Actual Rate" and show the contribution of the P, I, and D terms.

## Parameter Breakdown

*   **`GCS_PID_MASK`**: Bitmask of controllers to stream.
    *   **Bit 0:** Roll.
    *   **Bit 1:** Pitch.
    *   **Bit 2:** Yaw.
    *   **Bit 3:** Altitude/Position.

## Integration Guide
*   **Tuning:** Before starting a manual PID tuning session, set `GCS_PID_MASK = 7` (Roll+Pitch+Yaw) to see the performance data on your GCS screen.

## Developer Notes
*   **Library:** `libraries/GCS_MAVLink`.
*   **Performance:** Streaming many PIDs consumes telemetry bandwidth. Turn off when not tuning.