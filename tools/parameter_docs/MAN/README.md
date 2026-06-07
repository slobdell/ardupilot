# Manual Input Configuration (MAN)

## Overview
The **MAN** parameter group configures the "Exponential" (Expo) curves for **ArduPlane** when flying in manual and stabilized modes.

Expo softens the response of the control surfaces around the center of the sticks. This allows the pilot to make tiny, precise corrections for level flight while still having full control authority at the stick limits.

## Key Concepts

### 1. Manual Expo (`MAN_EXPO_...`)
*   **`MAN_EXPO_ROLL` / `PITCH` / `RUDDER`**: Sets the amount of curve for each axis.
    *   **0:** Linear (direct mapping).
    *   **100:** Maximum softness at center, very aggressive at ends.
    *   **Typical:** 30% to 50% is common for a smooth feel.

## Parameter Breakdown

*   **`MAN_EXPO_ROLL`**: Roll stick expo (%).
*   **`MAN_EXPO_PITCH`**: Pitch stick expo (%).
*   **`MAN_EXPO_RUDDER`**: Rudder stick expo (%).

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`.
*   **Context:** Only applies to **Manual**, **Acro**, and **FBWA/B** modes. Does not affect autonomous navigation.