# QuadPlane Configuration (Q)

## Overview
The **Q** parameter group is the primary configuration set for **QuadPlanes** (VTOL Fixed-Wing aircraft). A QuadPlane is a hybrid vehicle that uses multicopter motors for vertical takeoff and landing (VTOL) and a standard forward motor for efficient winged flight.

Because QuadPlanes are essentially two vehicles in one, the `Q` group mirrors many parameters found in the `ATC_`, `PSC_`, `MOT_`, and `WPNAV_` groups, but specifically for the VTOL phases of flight.

## Key Concepts

### 1. The VTOL "Shadow" Parameters
Almost every multicopter parameter has a `Q_` equivalent:
*   **`Q_A_RAT_...`**: Attitude PID gains for VTOL mode (equivalent to `ATC_RAT_`).
*   **`Q_P_POS...`**: Position control gains for VTOL (equivalent to `PSC_POS...`).
*   **`Q_M_...`**: Motor and mixer settings for the lift motors (equivalent to `MOT_`).

### 2. Transitions
The most complex part of QuadPlane flight is the transition between VTOL and Fixed-Wing.
*   **Forward Transition:** The VTOL motors hold altitude while the forward motor pushes the plane to flying speed. Once `ARSPD_FBW_MIN` is reached, the VTOL motors shut off.
*   **Back Transition:** The plane slows down, and as it approaches stall speed, the VTOL motors spin up to take over the weight of the aircraft.
*   **`Q_TRANSITION_MS`**: The duration of the transition phase.

### 3. Assisted Flight (`Q_ASSIST_...`)
A safety feature where the VTOL motors automatically spin up to "save" the plane if it stalls or loses attitude control during fixed-wing flight.

### 4. Tailsitters and Tilt-Rotors
The `Q` group also handles specialized VTOL mechanics:
*   **`Q_TAILSIT_...`**: For aircraft that sit on their tails and rotate 90 degrees for forward flight.
*   **`Q_TILT_...`**: For vehicles that tilt their motors forward (like the Osprey).

## Parameter Breakdown

*   **`Q_ENABLE`**: Master switch to enable VTOL support in ArduPlane.
*   **`Q_FRAME_CLASS`**: Lift motor layout (Quad, Hexa, etc.).
*   **`Q_TRANS_FAIL`**: Action to take if the transition takes too long (e.g., Q_RTL).

## Integration Guide
1.  **Frame Setup:** Set `Q_ENABLE = 1` and configure `Q_FRAME_CLASS` / `TYPE`.
2.  **Tuning:** Use **Q_AUTOTUNE** to tune the VTOL attitude controllers.
3.  **Transition Test:** Perform high-altitude transitions to verify the aircraft reaches flying speed before the lift motors disarm.

## Developer Notes
*   **Library:** `ArduPlane/QuadPlane.cpp`.
*   **Architecture:** The QuadPlane code acts as a bridge, handing control between the `AP_Motors` multicopter library and the standard fixed-wing flight code.