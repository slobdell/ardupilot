# Toy Mode Configuration (TMODE)

## Overview
The **TMODE** parameter group configures the **Toy Mode** engine. This is a specialized simplified interface used for consumer drones (like the SkyViper) or for integrating ArduPilot with cheap gamepad-style controllers.

Toy Mode simplifies flight control and abstracts many complex settings into easy-to-use button mappings.

## Key Concepts

### 1. Button Mapping (`TMODE_ACTIONx`)
Maps specific gamepad buttons to ArduPilot actions.
*   **Actions:** Flip, Take Photo, Change Mode, Land.

### 2. Simplified Tuning (`TMODE_TMAX` / `VMAX`)
Toy Mode often uses simplified limits for speed and tilt to make the drone easier for children or beginners to fly.

## Parameter Breakdown

*   **`TMODE_ENABLE`**: Master switch.
*   **`TMODE_TRIM_AUTO`**: Automatically calculates trim from stick positions.

## Developer Notes
*   **Library:** `ArduCopter/toy_mode.cpp`.