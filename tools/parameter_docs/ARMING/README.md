# Arming Checks (ARMING)

## Overview
The **ARMING** parameter group configures the **Pre-Arm Safety Checks**. ArduPilot performs a comprehensive system health check before allowing the motors to spin (Arming). This prevents taking off with bad sensors, no GPS lock, or unsafe configurations.

## Key Concepts

### 1. The Arming Check Bitmask (`ARMING_CHECK`)
This is the master configuration for what to check.
*   **1 (All):** Performs all standard checks (Barometer, Compass, GPS, Battery, RC, Board Voltage, Safety Switch, Logging). **Recommended.**
*   **0 (None):** Disables all checks. **Dangerous.**
*   **Specific Bits:** You can disable individual checks (e.g., disable GPS check for indoor flight) by summing the bitmask values.

### 2. Rudder Arming (`ARMING_RUDDER`)
Configures whether holding the rudder stick (Yaw) to the bottom-right corner arms the vehicle.
*   **1 (ArmOrDisarm):** Standard for Copters.
*   **2 (ArmOnly):** Cannot disarm via stick (requires GCS or Switch). Safer for flight.
*   **0 (Disabled):** Must use GCS or Switch to arm.

### 3. Required Accuracy
Parameters like `ARMING_ACCTHRESH` (Accelerometer error) and `ARMING_MAGTHRESH` (Compass error) set the strictness of the sensor health checks.

## Parameter Breakdown

*   **`ARMING_CHECK`**: Bitmask of enabled checks.
*   **`ARMING_RUDDER`**: Enable/Disable stick arming.
*   **`ARMING_ACCTHRESH`**: Max acccelometer inconsistency.
*   **`ARMING_MAGTHRESH`**: Max magnetic field inconsistency.

## Integration Guide

### Troubleshooting "Pre-Arm: Check ..."
1.  **Read the Message:** The HUD will tell you exactly what failed (e.g., "Pre-Arm: Compass not calibrated").
2.  **Fix the Root Cause:** Calibrate the sensor or move away from magnetic interference.
3.  **Last Resort:** Disable the specific check in `ARMING_CHECK` only if you understand the risk.

## Developer Notes
*   **Library:** `AP_Arming` (Vehicle specific implementations in `ArduCopter/AP_Arming.cpp`, etc.).
*   **Safety:** These checks are the last line of defense against configuration errors.