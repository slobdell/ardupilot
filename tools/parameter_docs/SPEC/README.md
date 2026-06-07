# Specific Gravity Configuration (SPEC)

## Overview
The **SPEC** parameter group (specifically `SPEC_GRAV` or `BARO_SPEC_GRAV`) configures the density of the medium for **ArduSub**.

## Key Concepts

### 1. Water Density
Depth calculation for ROVs depends on the weight of the water above the sensor. Fresh water and salt water have different densities.
*   **`SPEC_GRAV`**: The specific gravity of the liquid.
    *   **1.00:** Pure Fresh Water.
    *   **1.025:** Standard Seawater.

## Developer Notes
*   **Library:** `libraries/AP_Baro`.
*   **Accuracy:** Setting this correctly is essential for precise depth hold in different environments (e.g., Lake vs. Ocean).