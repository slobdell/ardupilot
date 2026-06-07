# Speed Scaling Configuration (SPD)

## Overview
The **SPD** parameter group (specifically `SPD_SCA_BASE` or `MOT_SPD_SCA_BASE`) configures speed-based scaling for the attitude controllers.

## Key Concepts

### 1. Dynamic Scaling
On high-speed vehicles, the effectiveness of the control surfaces (or motor differential) increases with speed. At high speeds, the drone may become "twitchy" or oscillate if the PID gains remain the same as they are at a hover.
*   **`SPD_SCA_BASE`**: Defines the ground speed (m/s) at which the attitude PID gains are at their nominal value. As speed increases above this, the autopilot automatically "detunes" (reduces) the gains to maintain stability.

## Developer Notes
*   **Library:** `libraries/AP_Motors`.
*   **Context:** Most common on Tailsitters and high-speed multirotors.