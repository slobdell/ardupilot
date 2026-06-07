# System Identification Configuration (SID)

## Overview
The **SID** parameter group configures the **System Identification** flight mode. This mode is used by engineers to mathematically model the vehicle's dynamics by injecting specific frequency sweeps (chirps) or step inputs into the control loops.

The data gathered during a SysID flight is used to calculate precise inertia, motor time constants, and aerodynamic coefficients, which can then be used to tune the PID controllers to a "Gold Standard" level of performance.

## Key Concepts

### 1. Excitation Signals
*   **`SID_AXIS`**: Selects which axis to test (Roll, Pitch, Yaw, Throttle).
*   **`SID_MAGNITUDE`**: The strength of the injected signal (e.g., deg/s for rate sweeps).
*   **`SID_F_START_HZ` / `STOP_HZ`**: The frequency range of the chirp signal.

### 2. Time Constants
*   **`SID_T_REC`**: Total duration of the test recording.
*   **`SID_T_FADE_IN / OUT`**: Smoothly ramps the signal to prevent sudden jerks.

## Parameter Breakdown

*   **`SID_AXIS`**: Axis selector.
*   **`SID_MAGNITUDE`**: Signal amplitude.
*   **`SID_XY_CTRL_MUL`**: Safety multiplier to detune the position controller during the test.

## Integration Guide
*   **Preparation:** System ID should only be performed after a basic manual tune is established.
*   **Safety:** Ensure you have plenty of altitude. The vehicle will twitch and vibrate aggressively during the sweep.
*   **Analysis:** Use tools like **UAVVID** or Matlab/Octave to process the DataFlash logs and generate a Bode plot.

## Developer Notes
*   **Library:** `libraries/AC_SystemID`.
*   **Mode:** Triggered by switching to `SYSTEM_ID` (Mode 25).