# GPS Blending Configuration (BLEND)

## Overview
The **BLEND** parameter group (specifically `GPS_BLEND_MASK`) configures the **Dual GPS Blending** logic.

When two GPS units are installed, ArduPilot can "blend" their outputs to create a single, smoother, and more robust position solution for the EKF. This is distinct from "GPS Switching" (Best Available).

## Key Concepts

### 1. Weighting Logic
The blended solution is a weighted average of the two sensors. The weights are calculated based on the reported accuracy (uncertainty) of each receiver.
$$ P_{\text{blend}} = \frac{P_1 \cdot W_1 + P_2 \cdot W_2}{W_1 + W_2} $$
where $W = 1 / \text{Accuracy}^2$.

### 2. Blending Mask (`GPS_BLEND_MASK`)
This bitmask determines *which* accuracy metrics are used to calculate the weights.
*   **Bit 0:** Horizontal Position Accuracy.
*   **Bit 1:** Vertical Position Accuracy.
*   **Bit 2:** Speed Accuracy.

## Parameter Breakdown

*   **`GPS_BLEND_MASK`**: Controls weight calculation.
    *   **5 (Default):** Use Horizontal Pos + Speed accuracy. Vertical accuracy is often ignored because GPS altitude is notoriously noisy.

## Integration Guide
*   **Requirement:** Two GPS units (`GPS_TYPE` and `GPS_TYPE2` set).
*   **Activation:** Set `GPS_AUTO_SWITCH = 2` (Blend).
*   **Verification:** Check `GPS2` status in GCS. The "Blended" solution is what the EKF consumes.

## Developer Notes
*   **Library:** `libraries/AP_GPS/AP_GPS_Blended.cpp`
*   **Prefix:** `GPS_BLEND_` (often aliased or grouped here).