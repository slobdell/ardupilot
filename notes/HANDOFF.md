# Avatar Zoh Altus VTOL — Handoff

**Date:** June 2026
**Airframe:** Zoh Altus VTOL
**FC:** MicoAir H743 (`AHRS_ORIENTATION=6`)
**Branch:** `slobdell_base`
**Golden params:** `params/avatar_t1ranger_micoair.param` (source of truth — always dump after param changes)

---

## Current State: What's Working

- **QSTABILIZE:** stable hover, all axes tuned and flight-tested
- **QLOITER:** confirmed working — holds position and altitude well; buttery smooth
- **Weathervaning:** `Q_WVANE_GAIN=1.0` set; active in QLOITER
- **STABILIZE (plane mode):** extensively updated this session (see below). Backflip bug fixed. Awaiting re-flight.
- **FBWA:** bench + plane-mode tested; elevator holds level, TVC tilt responds to TECS. Awaiting real flight test.
- **Past-horizontal tilt:** implemented; `SERVO5_MIN=700`, `forward_flight_physical_angle_deg=95`
- **FFT + notch filter:** `FFT_ENABLE=1`, `INS_HNTCH_ENABLE=1`, `INS_HNTCH_FREQ=258.88 Hz`

---

## Next Task: Roll Control Loss — Log Analysis

### What Happened
During a STABILIZE flight test with backward tilt (braking), the aircraft lost roll control and did a backflip.

### Root Cause (Fixed)
**The `cos_tilt_b` bug.** Old code computed:
```cpp
float tilt_deg_b = outputs.tilt_angle * g_config.forward_flight_physical_angle_deg;
float cos_tilt_b = fmaxf(0.0f, cosf(radians(tilt_deg_b)));
```
After adding piecewise tilt normalization (negative half maps to -1.0), at -15° backward tilt: `outputs.tilt_angle = -1.0`, so `tilt_deg_b = -1.0 × 95 = -95°`, and `cos_tilt_b = fmaxf(0, cos(-95°)) = 0`.

This zeroed out:
- `roll_delta = inputs.roll * cos_tilt_b = 0` → **zero roll authority**
- `rear_demand = (throttle - pitch) * cos_tilt_b = 0` → **zero pitch stabilization on rear motors**

Result: backflip + roll loss.

**Fix applied:** `float cos_tilt_b = fmaxf(0.0f, cosf(radians(state.current_tilt_deg)));` — at -15°, `cos(-15°) = 0.966`. All motor authority preserved.

### Log Analysis Task
Even with the root cause known, analyze the logs to:
1. Confirm the timeline — when did backward tilt start and when did roll diverge?
2. Check if any other factors contributed (yaw PID instability, dampening interference, etc.)
3. Verify Q_DAMP_VERT = 0.35 behavior in the log (is dampening too aggressive?)

**Log download:**
```bash
python3 tools/mavlink/log_download.py          # USB serial
python3 tools/mavlink/log_download.py --elrs   # ELRS WiFi
python3 tools/mavlink/log_analyze.py logs/flight.BIN
python3 tools/mavlink/analyze_stabilize.py logs/flight.BIN
```

**Key fields:**
| Field | Meaning |
|-------|---------|
| `RCIN.C1` | Pilot roll stick |
| `RCIN.C2` | Pilot pitch stick (tilt demand) |
| `ATT.Roll` / `ATT.DesRoll` | Roll tracking — look for divergence |
| `RCOU.C1` / `RCOU.C4` | Wing motors (SERVO1/4 = left/right wing) |
| `RCOU.C5` | Tilt servo PWM |
| `AVSD.PilotTilt` | pilot_tilt_deg — what pilot commanded |
| `AVSD.CurrTilt` | current_tilt_deg — actual servo angle |
| `AVSD.DampThrust` | Dampening output — was Q_DAMP_VERT = 0.35 too aggressive? |
| `XKF1.VD` | EKF vertical velocity (sink rate source) |

---

## Recently Completed This Session

### 1. Tilt-Scaled Minimum Throttle Guard (`[AV-INVAR:min-thr-tilt]`)
Prevents TECS from cutting motors to 0% when rotors are vertical (no aerodynamic lift). Floor = `Q_M_SPIN_MIN × cos(tilt_deg) × 100%`. Gated by `plane.is_flying()` (no ground spin-up). In `quadplane.cpp` plane_inputs block.

### 2. Sink Dampening Fixes (`[AV-INVAR:sink-damp]`)
- Added `plane.is_flying()` gate — was triggering on bench (EKF noise at zero throttle → atan2(0,0) → always vertical)
- Added `LowPassFilter2p<float>` at 400Hz/0.5Hz cutoff on raw EKF velocity — eliminates high-frequency noise tilt oscillation
- Q_DAMP_VERT code default now 0.05 (aircraft currently running 0.35 — not yet validated)

### 3. AVSD Dataflash Log
`AP::logger().WriteStreaming("AVSD", ...)` — fields: RawVZ, FiltVZ, SinkRate, DampThrust, PilotTilt, CurrTilt.
Also: real-time GCS message at 2Hz (TILT pilot/curr/demand) for `monitor.py` use. **Remove before production.**

### 4. Yaw PID in STABILIZE (`[AV-INVAR:stabilize-yaw-pid]`)
STABILIZE now calls `attitude_control->rate_bf_yaw_target(get_pilot_input_yaw_rate_cds())`. Mixer uses `inputs.yaw` (PID output) via `use_pid_yaw` flag. Previously: raw rudder stick passthrough with no closed-loop control. Gated to STABILIZE only — FBWA/CRUISE/FBWB unchanged (use `rudder_input / 4500`).

### 5. Pilot Tilt Decoupling (`pilot_tilt_deg`)
`MixerState` now has `pilot_tilt_deg` (stick intent) separate from `current_tilt_deg` (actual servo). Sink dampening only modifies `current_tilt_deg`. When dampening releases, `current_tilt_deg` recovers toward `pilot_tilt_deg` at 225°/s. Previously: dampening permanently shifted the pilot's reference position.

### 6. Backward Tilt / Braking
- `reverse_flight_physical_angle_deg = -15.0f` in `avatarConfig` (was always there, now used)
- Rate-mode constrain changed from `[0, 95]` to `[-15, 95]`
- Piecewise normalization: negative tilt divides by `|reverse_flight_physical_angle_deg|` (15) so -15° → -1.0 (full servo travel). Positive tilt unchanged (divides by 95).

### 7. Pitch Stick Expo (`Q_TILT_EXPO`)
`AP_Float _tilt_expo` (index 42, default 0.3) registered as `Q_TILT_EXPO`. Applied via `input_expo(norm_input_dz(), _tilt_expo)` in STABILIZE. Deadzone already handled by `RC2_DZ`. FBWA/CRUISE unaffected.

### 8. `cos_tilt_b` Fix (CRITICAL — caused the backflip)
See "Root Cause" above. `cos_tilt_b` now uses `state.current_tilt_deg` directly.

---

## Architecture — How STABILIZE Mode Works

**The FC maintains copter and plane mode logic simultaneously.** `transition_progress` is binary: `in_vtol_mode() ? 0.0 : 1.0`.

In STABILIZE (plane mode, `transition_progress=1.0`), the `AvatarMixer::mix()` plane branch runs:

1. **Tilt control:** `pilot_tilt_deg` updated from `pitch_tilt_demand` (expo-mapped pitch stick, rate-mode). `current_tilt_deg` tracks `pilot_tilt_deg` at `Q_TILT_RATE_UP`. Range: `[-15°, 95°]`.
2. **Sink dampening:** force-vector decomposition in mixer tilts rotors back and boosts throttle proportional to `damp_vert_thrust`. Only when `is_flying()`.
3. **Pitch stabilisation:** copter attitude PID targeting 0° pitch. Written via `rate_bf_pitch_target()` — **do not use** `input_euler_angle_*`.
4. **Yaw stabilisation:** `rate_bf_yaw_target(get_pilot_input_yaw_rate_cds())` — same PIDs as copter mode.
5. **Elevator out:** `outputs.elevator_out = inputs.pitch` (rear motor + elevator surface).
6. **Wing motors:** `throttle_pct ± roll_delta`. Roll fades with `cos_tilt_b`.
7. **Rear motors:** `(throttle_pct - inputs.pitch) * cos_tilt_b` ± yaw differential.
8. **`cos_tilt_b`**: `fmaxf(0, cos(state.current_tilt_deg))` — **uses actual angle directly, NOT denormalized output**.

**Critical: `ATT.DesPitch` is always 0 in STABILIZE.** Use `RCIN.C2` for pilot stick position in logs.

---

## Key Code Files

| File | Purpose |
|------|---------|
| `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` | Motor mixing — plane/copter branch, tilt, roll/yaw, sink dampening, `cos_tilt_b` |
| `libraries/AP_Motors/AP_Motors6DOF_Mixer.h` | `MixerInputs` struct, `MixerState` with `pilot_tilt_deg` |
| `libraries/AP_Motors/AP_Motors6DOF.h` | `PlaneInputs` struct, `get_tilt_deg()`, `get_pilot_tilt_deg()` |
| `libraries/AP_Motors/AP_Motors6DOF.cpp` | Copies PlaneInputs → MixerInputs; tilt rates from Q_TILT_RATE_UP/DN |
| `ArduPlane/quadplane.cpp` | `set_plane_inputs()` — tilt demand, throttle floor, dampening, yaw PID, AVSD log |
| `ArduPlane/quadplane.h` | `damp_vert_gain`, `_tilt_expo`, `_damp_vert_vel_filter` |
| `libraries/AP_CustomConfig/AP_CustomConfig.cpp` | `avatarConfig` — `forward_flight_physical_angle_deg=95`, `reverse_flight_physical_angle_deg=-15` |
| `params/avatar_t1ranger_micoair.param` | Golden param file |
| `notes/Avatar_Design.md` | Full architecture reference with `[AV-INVAR:*]` invariants (§9) |

---

## RC Channel Mapping (STABILIZE)

| Channel | Function | Low (1300) | High (1700) |
|---------|----------|-----------|------------|
| RCIN.C2 | Pitch stick / tilt demand | Tilt FORWARD (toward horizontal) | Tilt BACKWARD (toward vertical/braking) |
| RCIN.C3 | Throttle | Zero/min | Full |

**RC2:** `RC2_TRIM=1505, RC2_MIN=997, RC2_MAX=2011, RC2_DZ=30, RC2_REVERSED=0`

---

## Current PID Values (golden param file)

```
Q_A_RAT_RLL_P  = 0.45    Q_A_RAT_YAW_P    = 0.2
Q_A_RAT_RLL_I  = 0.25    Q_A_RAT_YAW_I    = 0.005
Q_A_RAT_RLL_D  = 0.004   Q_A_RAT_YAW_D    = 0.006
Q_A_RAT_RLL_FF = 0.15    Q_A_RAT_YAW_FF   = 0.35
Q_TILT_RATE_UP = 225 °/s  Q_TILT_RATE_DN = 30 °/s
Q_DAMP_VERT    = 0.35  (live on aircraft — not yet validated; code default = 0.05)
Q_TILT_EXPO    = 0.3
```

---

## Connectivity

### ELRS TX Backpack (preferred)
```bash
python3 tools/mavlink/param_set.py --elrs PARAM_NAME VALUE
python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
```

### USB Serial (fallback)
```bash
python3 tools/mavlink/param_set.py PARAM_NAME VALUE
python3 tools/mavlink/param_dump.py -v -o params/avatar_t1ranger_micoair.param
```

### Flash firmware
```bash
./micoair_flash.sh --flash
# Build: ./waf configure --board MicoAir743 --disable-scripting && ./waf plane
```

---

## Log Tooling

```bash
python3 tools/mavlink/log_download.py            # download latest log (serial)
python3 tools/mavlink/log_download.py --elrs     # download latest log (ELRS WiFi)
python3 tools/mavlink/log_analyze.py logs/flight.BIN
python3 tools/mavlink/analyze_stabilize.py logs/flight.BIN
```

---

## Motor Layout

| Index | Define | Physical | SERVO | SERVO_FUNCTION |
|-------|--------|----------|-------|----------------|
| 0 | `AVATAR_MOT_WING_LEFT` | Left wing motor | SERVO1 | 33 |
| 1 | `AVATAR_MOT_WING_RIGHT` | Right wing motor | SERVO4 | 34 |
| 2 | `AVATAR_MOT_YAW_RIGHT` | Right rear yaw motor | SERVO3 | 35 |
| 3 | `AVATAR_MOT_YAW_LEFT` | Left rear yaw motor | SERVO2 | 36 |

Tilt servo: **SERVO5** (`RCOU.C5` in logs). `SERVO5_MIN=700`, `SERVO5_TRIM=1827`, `SERVO5_MAX≈2100`, `SERVO5_REVERSED=1`.

---

## Known Outstanding Items

1. **Roll control loss log analysis** — confirm cos_tilt_b was the cause; check Q_DAMP_VERT=0.35 behavior
2. **Re-flight after cos_tilt_b fix** — verify backward tilt now works without roll loss
3. **Q_DAMP_VERT=0.35 validation** — may be too aggressive; tune from 0.05 upward if needed
4. **`AVATAR_DEBUG_LOG=1`** — disable before production
5. **GCS tilt debug message** — remove before production
6. **Param file hygiene** — dump fresh params after next flash (stale Q_DAMP_TILT/Q_DAMP_THR entries)
7. **FBWA real flight** — bench-validated only
8. **Notch filter verification** — check FTN messages at ~258 Hz in flight logs
