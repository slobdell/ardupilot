# Generic Custom Parameters (PARAM)

## Overview
The **PARAM** parameter group (specifically `PARAM1`...`PARAM3`) provides generic placeholders for **Custom Control** backends.

## Key Concepts

### 1. Extensibility
To support developers who are writing custom C++ algorithms or Lua scripts, ArduPilot provides these generic floating-point parameters. This allows a developer to expose tunable gains or thresholds to the Ground Control Station without having to modify the core parameter definitions or recompile the entire firmware.

## Developer Notes
*   **Library:** `libraries/AC_CustomControl`.
*   **Usage:** Only relevant if a custom backend (`CC_TYPE > 0`) is active.
