# Developer Options (DEV)

## Overview
The **DEV** parameter group (specifically `DEV_OPTIONS`) contains flags for enabling experimental or developer-only features in **ArduCopter**.

These features are often unstable, untested, or intended for deep debugging of internal state.

## Key Concepts

### 1. Developer Flags
Bitmask options that toggle specific internal behaviors.
*   **Bit 0:** Enable ADS-B simulation (SITL).
*   **Bit 1:** Enable debug logging for certain subsystems.
*   (Options vary significantly between firmware versions).

## Parameter Breakdown

*   **`DEV_OPTIONS`**: Bitmask.

## Integration Guide
*   **Warning:** Do not enable these unless you are an ArduPilot developer or strictly following instructions from one. They can alter flight behavior unexpectedly.

## Developer Notes
*   **Library:** `ArduCopter/Parameters.cpp`