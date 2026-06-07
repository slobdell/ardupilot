# Velocity Estimator Configuration (VEL)

## Overview
The **VEL** parameter group (specifically `VEL_M_NSE`) configures the expected noise level of the velocity measurements within the **EKF**.

## Key Concepts

### 1. Velocity Noise
*   **`VEL_M_NSE`**: Measurement noise for the velocity sensors (typically GPS).
    *   **Higher values:** Tells the EKF to trust the GPS velocity less (good for noisy environments).
    *   **Lower values:** Trusts the GPS velocity more (crisper position response but more susceptible to glitches).

## Developer Notes
*   **Library:** `libraries/AP_NavEKF3`.