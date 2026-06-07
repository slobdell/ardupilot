# SITL Simulation Configuration (SIM)

## Overview
The **SIM** parameter group configures the **Software-In-The-Loop (SITL)** simulator environment. These parameters allow developers to simulate hardware failures, environmental conditions (wind/tides), and sensor noise without risking a physical vehicle.

**Note:** These parameters only exist when running the SITL binary; they are not present in physical flight controller hardware.

## Key Concepts

### 1. Sensor Failures (`SIM_..._FAIL`)
Developers can simulate a sensor "dying" in mid-air to test failsafe logic.
*   **`SIM_GPS_DISABLE`**: Turns off GPS signal.
*   **`SIM_ACCEL_FAIL`**: Simulates an accelerometer failure.

### 2. Environmental Conditions
*   **`SIM_WIND_SPD` / `DIR`**: Injects constant wind.
*   **`SIM_WIND_TURB`**: Adds turbulence to the wind model.
*   **`SIM_WAVE_AMP`**: (Rover/Boat) Simulates water waves affecting the hull.

### 3. Sensor Noise and Bias
Allows for adding realistic imperfections to the simulated sensors to test EKF resilience.
*   **`SIM_GYR_RND`**: Random noise on the gyros.
*   **`SIM_MAG_ALY`**: Simulated magnetic anomaly.

## Parameter Breakdown

*   **`SIM_SPEEDUP`**: Multiplier for simulation speed (e.g., 5.0 runs the sim at 5x real-time).
*   **`SIM_RATE_HZ`**: Update frequency of the physics engine.
*   **`SIM_VICON_...`**: Configures simulated Motion Capture (Vicon/Optitrack) indoor positioning.

## Integration Guide
*   **Safety Testing:** Use `SIM_GPS_JAM = 1` while in an autonomous mission to verify the vehicle correctly switches to non-GPS modes or triggers RTL.

## Developer Notes
*   **Library:** `libraries/SITL`.
*   **Frontends:** SITL can be viewed in 3D using Gazebo, AirSim, or RealFlight.