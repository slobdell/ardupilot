# Follow Mode Configuration (FOLL)

## Overview
The **FOLL** parameter group configures the **Follow Mode**. This allows the vehicle to autonomously follow a "Lead" target (another MAVLink-enabled vehicle or a Ground Control Station).

The follower receives the Lead's position via telemetry (MAVLink `GLOBAL_POSITION_INT` or `FOLLOW_TARGET` messages) and calculates the necessary maneuvers to maintain a constant offset.

## Key Concepts

### 1. Relative Offsets (`FOLL_OFS_...`)
Defines the distance (meters) the follower should keep from the leader.
*   **X (Forward):** Positive = ahead of leader, Negative = behind.
*   **Y (Right):** Positive = to the right, Negative = to the left.
*   **Z (Down):** Positive = below the leader, Negative = above.

### 2. Offsets Type (`FOLL_OFS_TYPE`)
How are the offsets interpreted?
*   **0 (North-East-Down):** Follower maintains fixed cardinal directions (e.g., always 5m North).
*   **1 (Relative to Heading):** Follower maintains position relative to the Leader's nose (e.g., always 5m behind the tail).

### 3. Target Identification (`FOLL_SYSID`)
Specifies the MAVLink System ID of the target to follow.
*   **0:** Follow the first GCS that sends a follow command.

## Parameter Breakdown

*   **`FOLL_ENABLE`**: Master switch.
*   **`FOLL_DIST_MAX`**: Maximum distance (meters) to the leader before giving up (failsafe).
*   **`FOLL_POS_P`**: Proportional gain for position correction.
*   **`FOLL_ACCEL_D`**: Damping for acceleration (smoothes movements).

## Integration Guide
1.  **Requirement:** A stable telemetry link between the two vehicles or vehicle-to-GCS.
2.  **Enable:** Set `FOLL_ENABLE = 1`.
3.  **Mode:** Switch the follower vehicle to `FOLLOW` flight mode.
4.  **Initiate:** Use the GCS to send a "Follow Me" command.

## Developer Notes
*   **Library:** `libraries/AP_Follow`.
*   **Precision:** Follow performance depends heavily on the update rate of the telemetry link. 10Hz+ is recommended for close formation flight.