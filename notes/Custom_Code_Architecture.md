# Custom Code Architecture & History

This document records the key architectural decisions made while building our custom TVC (Thrust Vectoring Controller) logic into the ArduPilot codebase, and the current structure of that code. It reflects both where the code is now and how it got there.

---

## 1. Current Architecture: Humble Object Pattern

The core TVC algorithm is isolated from the ArduPilot HAL using the **Humble Object** pattern. This keeps the flight-critical logic testable without compiling and flashing firmware.

### Two layers

**Pure logic layer** (`libraries/AP_Motors/TVC_Core.*`, `TVC_PID.*`, `TVC_Filters.*`):
- Entry point: `tvc_run_main_logic(TVC_Inputs, TVC_CoreState, TVC_Config) → TVC_Outputs`
- No ArduPilot types, no HAL calls, no side effects
- Platform-independent types (`TVC_Vector3f`, etc.) instead of ArduPilot's `Vector3f`
- Unit-testable standalone — a test harness can call it directly with mock inputs

**HAL interface layer** (`libraries/AP_Motors/AP_Motors6DOF_BlimpMixer.*`, `AP_Motors6DOF_AvatarMixer.*`):
- Called from `AP_Motors6DOF::output_armed_stabilizing()` each loop
- Reads ArduPilot state (RC channels, AHRS, spool state) → populates `MixerInputs`
- Calls `tvc_run_main_logic()` for copter-mode tilt control
- Writes results to `MixerOutputs` → drives servos and motors via `output_to_motors()`

### Data contracts

Defined in `libraries/AP_Motors/AP_Motors6DOF_Mixer.h`:

| Struct | Purpose |
|--------|---------|
| `MixerInputs` | All perception data for one loop cycle (RC, AHRS, spool state, plane state) |
| `MixerOutputs` | Motor thrusts, tilt angle, surface outputs, saturation limits |
| `MixerState` | Persistent state across loops (PID objects, filters, current tilt deg) |

Defined in `libraries/AP_Motors/TVC_Core.h`:

| Struct | Purpose |
|--------|---------|
| `TVC_Inputs` | Inputs to pure logic (RC PWM values, AHRS angles, gyro, timestamp) |
| `TVC_Outputs` | Outputs from pure logic (normalized tilt angle, throttle, health, debug data) |
| `TVC_CoreState` | PID and filter state passed into and out of the pure function |
| `TVC_Config` | Gain schedule tune points and angle PID gains |

`MixerState::get_tvc_state()` bridges the two layers — it projects the mixer's persistent state into the `TVC_CoreState` expected by `tvc_run_main_logic`.

### Shared gain schedule

Both `BlimpMixer` and `AvatarMixer` call `tvc_run_main_logic(tvc_in, tvc_s, tvc_config)` with the same `tvc_config` instance defined in `TVC_Core.cpp`. There is no per-aircraft gain schedule — blimp and avatar fly with identical pitch/roll rate PIDs and angle PIDs. If the two aircraft need to be tuned independently, a per-aircraft `TVC_Config` branch would need to be added to the mixer dispatch.

---

## 2. Lineage: How We Got Here

### Phase 1: Standalone TVC prototype
The original TVC logic lived in `custom_main.cpp` — a standalone `.ino` project (Arduino-style) with raw SBUS I/O, custom PID and filter libraries, and direct IMU reads via Madgwick. This was the proof of concept for vectored thrust control.

### Phase 2: Ported into ArduPilot as `custom_main.cpp`
The prototype logic was ported into ArduPilot as a `newMain()` function running alongside the standard ArduPilot loop. At this stage:
- IMU replaced with ArduPilot EKF (`AP::vehicle()->get_osd_roll_pitch_rad()`)
- SBUS I/O replaced with `RC_Channels` and `SRV_Channels` APIs
- Custom PID and filter libraries preserved as-is and added to the ArduPilot build

**Build system lesson:** `ardupilotwaf` does not recursively scan subdirectories in `libraries/`. Source files must be in the library root (e.g., `libraries/AP_Motors/`). Moving files into subdirectories causes linker errors (`undefined reference`).

### Phase 3: Humble Object refactoring
The monolithic `newMain()` was split into the two layers described above:
- Pure logic extracted into `tvc_run_main_logic()` with `TVC_Inputs/Outputs/CoreState` contracts
- HAL layer retained in what became `BlimpMixer` / `AvatarMixer`
- All ArduPilot types (`Vector3f`) replaced with platform-independent equivalents in the pure layer

This enables a standalone C++ test harness: copy `TVC_Core.*`, `TVC_PID.*`, `TVC_Filters.*` into an empty project, write a `main_test.cpp` that populates `TVC_Inputs` and calls `tvc_run_main_logic()`, assert on `TVC_Outputs`.

### Phase 4: SFC firmware (separate repo)
The SFCs (Secondary Flight Controllers, ESP32-S3) run firmware from a separate repository. Key architecture from that phase:

**Three-Point Contract (TVC → SFC command protocol):**
- TVC normalizes target physical angle using piecewise normalization: positive angles divide by `forward_flight_physical_angle_deg`, negative angles divide by `|reverse_flight_physical_angle_deg|`
- Result: `0.0` = vertical, `1.0` = max forward, `-1.0` = max reverse — physically meaningful regardless of servo geometry
- SFC de-normalizes using its own configured mechanical limits

**SFC Cross-Fade Motor Model (validated architecture for VTOL transition):**
- PFC broadcasts raw unblended state: `pfc_base_throttle` (hover controller output) + `plane_throttle_cmd` (fixed-wing controller output) + `transition_progress`
- SFC performs the one and only blend: `final_thrust = (1 - t) * (pfc_base_throttle * hover_thrust_factor) + t * plane_throttle_cmd`
- TVC manages servo angles only — no thrust calculation
- `Q_ASSIST_SPEED` must be set to 0: if re-activated during tilt-rotor forward flight, the multicopter controller would increase thrust to correct roll, but motors are tilted forward and increased thrust produces yaw, not roll correction — loss of control

---

## 3. Unit Test History

A standalone test harness lives in `tests/tvc_core_test/`. It validated:

- Helper functions (`sbus_pwm_to_float`, `float_to_sbus_pwm`, scaling)
- Failsafe: outputs return to neutral on failsafe
- Saturation: `clip_vectors_for_saturation()` clamps correctly and sets saturation flags
- Zero input: neutral stick → zero vectoring, `thrust_factor = 1.0`
- Forward/lateral: stick inputs produce correct pitch/roll vector commands
- Thrust compensation: `thrust_factor` calculation validated across 2D spectrum of commands
- Dynamic stability: sine-wave stick input integration test confirms PIDs remain stable

**Bug found and fixed during testing:** Original `thrust_factor` calculation used the clamped physical angle instead of the pilot's true commanded angle. Fixed to use the unclamped angle for compensation, ensuring correct total thrust during aggressive maneuvers.

---

## 4. Caterpillar H-Frame (Dormant)

The Caterpillar H-Frame was a 24-motor aircraft design that also used the TVC vectoring brain. It is **not the current active project** but the config option is preserved.

In `AP_CustomConfig`:
- `caterpillar_h_frame_6dof` field exists in `CustomConfig` struct
- Set to `false` in both `blimpConfig` and `avatarConfig`

In `AP_Motors6DOF.cpp`:
- `if (g_config.caterpillar_h_frame_6dof) wantMotors = 9;` — 9-motor count for this frame
- PID tuning channel passthrough code at line ~428 is gated behind this flag

**Known issue (still in code, untriggered):** In-flight PID tuning for the Caterpillar H-frame is non-functional. The tuning values are written to `_thrust_rpyt_out[12]` and `_thrust_rpyt_out[13]`, but no motors are enabled at those indices, so `output_to_motors()` skips them. Fix: add dummy motors at indices 12 and 13 with all factors set to zero.

---

## 5. SBUS Validation

End-to-end SBUS input and output was validated on MicoAir H743 using a hardware loopback rig (two ESP32-S3s — one generating, one parsing). Confirmed scaling formulas:

```
Input:  PWM = (RAW_SBUS × 0.625) + 875
Output: RAW_SBUS = (PWM − 875) × 1.6
```

See `SBUS_Reference.md` for the full validation data and bus channel maps.
