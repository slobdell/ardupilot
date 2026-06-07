# Autonomous Autorotation (AROT)

## Overview
The **AROT** parameter group configures the **Autonomous Autorotation** capability, primarily for **Traditional Helicopters**.

If the engine fails (low RPM), this system automatically takes control to manage the collective pitch and cyclic to maintain rotor energy and guide the helicopter to a safe touchdown, performing a flare maneuver at the bottom.

## Key Concepts

### 1. Entry Criteria
The system monitors the main rotor RPM (via `RPM` sensor). If it drops below a threshold while in flight, Autorotation is triggered.

### 2. Glide Phase
The autopilot pitches for optimal airspeed (`AROT_FW_V_P` gain) to maximize glide distance or rotor energy preservation.

### 3. Flare and Touchdown
Near the ground, the system pitches up (Flare) to convert forward airspeed into rotor RPM, slowing the descent for a soft landing.

## Parameter Breakdown

*   **`AROT_ENABLE`**: Master switch.
*   **`AROT_HS_P`**: Head Speed (RPM) P gain (controls Collective).
*   **`AROT_FW_V_P`**: Forward Velocity P gain (controls Pitch).
*   **`AROT_RAMP`**: Time to ramp collective back in if power is restored (Bail-out).

## Developer Notes
*   **Library:** `libraries/AC_Autorotation`
*   **Vehicle:** **ArduCopter** (Heli frame).