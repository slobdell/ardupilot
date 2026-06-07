# Surface Tracking Configuration (SURFTRAK)

## Overview
The **SURFTRAK** parameter group configures the **Surface Tracking** mode for **ArduSub**.

In this mode, the ROV maintains a constant distance from either the surface of the water or the seafloor (if a downward-facing rangefinder is used).

## Key Concepts

### 1. Relative Depth Control
*   **`SURFTRAK_DEPTH`**: The target distance (cm) to maintain from the reference (surface or bottom).
*   **`SURFTRAK_MODE`**: Selects between Tracking the Surface or Tracking the Bottom.

## Developer Notes
*   **Library:** `ArduSub/Parameters.cpp`.
*   **Requirement:** Requires a valid external pressure sensor or rangefinder.