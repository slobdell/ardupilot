# Filter Configuration (FLTR)

## Overview
The **FLTR** parameter group (specifically `FLTR_RNG` or `BARO_FLTR_RNG`) defines the "Sanity Check" range for the barometer filter.

## Key Concepts

### 1. Filter Range (`FLTR_RNG`)
This parameter sets the maximum allowable change in altitude reading between successive samples that the filter will accept.
*   **Purpose:** Rejects extreme, non-physical pressure spikes (e.g., from an electrical glitch or a door slamming in an indoor environment) before they are passed to the altitude controller.

## Parameter Breakdown

*   **`FLTR_RNG`**: Range in meters.

## Developer Notes
*   **Library:** `libraries/AP_Baro`.
*   **Relationship:** Part of the robustness layer of the `AP_Baro` library.