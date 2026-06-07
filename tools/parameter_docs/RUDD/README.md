# Rudder Configuration (RUDD)

## Overview
The **RUDD** parameter group configures specific behaviors for the **Rudder** control axis on fixed-wing aircraft.

## Key Concepts

### 1. Dual-Tail Gains (`RUDD_DT_GAIN`)
This parameter is specific to aircraft with **Dual Tail** (Twin Rudder) configurations. It allows for independent scaling of the rudder authority when the tails are acting together vs. opposing each other.

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.
*   **See Also:** [RLL](../RLL/README.md) and [PTCH](../PTCH/README.md) for main flight control surfaces.