# Lead Filter Configuration (LEAD)

## Overview
The **LEAD** parameter group (specifically `LEAD_RLL` and `LEAD_PTCH`) configures the legacy **Lead Filter**.

## Key Concepts

### 1. GPS Lag Compensation
Before the invention of high-frequency GPS (10Hz+) and modern EKF (Kalman Filters), ArduPilot used a "Lead Filter" to project the vehicle's position forward in time. This compensated for the inherent 1-second lag found in old NMEA GPS receivers.

## Developer Notes
*   **Status:** **Legacy.** These parameters have essentially no effect when using modern EKF2 or EKF3 estimators, as the EKF handles sensor delay compensation internally with much higher precision.