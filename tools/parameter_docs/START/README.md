# Startup Origin Configuration (START)

## Overview
The **START** parameter group (specifically `START_LATITUDE` and `START_LONGITUDE`) configures the default starting location for the **SITL** simulator.

## Key Concepts

### 1. Simulated World Origin
When you launch the SITL binary without a specific location flag, it defaults to the coordinates defined here.
*   **Purpose:** Allows developers to always start their simulation at a specific airfield or test track.

## Developer Notes
*   **Library:** `libraries/SITL`.
*   **SITL Only:** These parameters do not exist on real flight controller hardware.