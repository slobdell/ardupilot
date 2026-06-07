# GPS SBP Configuration (GPSSBP)

## Overview
The **GPSSBP** parameter group configures the **Swift Binary Protocol (SBP)** driver, used for **Swift Navigation** GPS receivers (like the Piksi Multi).

## Key Concepts

### 1. SBP Logging
Configures the verbosity of raw data logging for Swift Navigation specific data structures, essential for debugging RTK convergence and signal quality on those specific receivers.

## Developer Notes
*   **Library:** `libraries/AP_GPS/AP_GPS_SBP.cpp`.