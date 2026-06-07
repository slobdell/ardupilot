# Magnetic Anomaly Configuration (MAG)

## Overview
The **MAG** parameter group (specifically `MAG_ALY`) is a **SITL-only** tool used to simulate magnetic interference.

**Note:** For physical compass calibration and setup, please refer to the [COMPASS](../COMPASS/README.md) group.

## Key Concepts

### 1. Simulated Interference
In the Software-In-The-Loop (SITL) simulator, developers can inject a "Magnetic Anomaly" to see how the EKF and navigation algorithms handle incorrect heading data.
*   **`MAG_ALY`**: A 3D vector (X, Y, Z) in Gauss that is added to the simulated world's magnetic field.
*   **Purpose:** Testing the "Compass Variance" failsafe logic and "Compass-less" flight algorithms.

## Developer Notes
*   **Library:** `libraries/SITL`.
*   **Units:** Gauss (Magnetic field strength).