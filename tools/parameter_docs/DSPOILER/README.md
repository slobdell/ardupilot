# Differential Spoiler Configuration (DSPOILER)

## Overview
The **DSPOILER** parameter group configures **Differential Spoilers**, also known as **Split Ailerons**, **Decelerons**, or **Drag Rudders**.

This control surface configuration is common on flying wings (like the B-2 Spirit) where there is no vertical stabilizer. Yaw control is achieved by splitting the aileron on one wing (opening it like a clam shell) to create drag on that side.

## Key Concepts

### 1. Drag for Yaw
*   **Yaw Left:** Open Left Spoiler (Left Upper Surface Up, Left Lower Surface Down).
*   **Yaw Right:** Open Right Spoiler.

### 2. Crow Braking
Both spoilers can be opened simultaneously to act as airbrakes, increasing drag for steep descents without increasing airspeed.
*   **`DSPOILER_CROW_W1` / `W2`**: Weighting for how much inner/outer surfaces move during braking.

### 3. Aileron Match (`DSPOILER_AILMTCH`)
Ensures that the roll authority is maintained even when spoilers are deployed.

## Parameter Breakdown

*   **`DSPOILER_OPTS`**: Options bitmask.
*   **`DSPOILER_CROW_W1`**: Weighting for inner control surface.
*   **`DSPOILER_CROW_W2`**: Weighting for outer control surface.

## Integration Guide
1.  **Outputs:** Map 4 servo outputs: Left Outer, Left Inner, Right Inner, Right Outer.
2.  **Functions:** Use `24` (Left Elevon) and `77` (Right Elevon) or specific spoiler functions depending on the mix.
3.  **Tune:** Adjust rudder mixing to get sufficient yaw authority without inducing adverse roll.

## Developer Notes
*   **Library:** `ArduPlane/servos.cpp`
*   **Complexity:** Requires careful mixing to handle Roll (Aileron), Pitch (Elevator), and Yaw (Drag) simultaneously on the same surfaces.