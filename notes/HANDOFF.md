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
- **STABILIZE (plane mode):** flight-tested June 2026. Tilt rate control works as designed.
- **FBWA:** bench + plane-mode tested; elevator holds level, TVC tilt responds to TECS. Awaiting real flight test.
- **Past-horizontal tilt:** implemented; `SERVO5_MIN=700`, `forward_flight_physical_angle_deg=95`
- **FFT + notch filter:** `FFT_ENABLE=1`, `INS_HNTCH_ENABLE=1`, `INS_HNTCH_FREQ=258.88 Hz`
- **Sink dampening (Q_DAMP_VERT):** implemented June 2026; see below and `[AV-INVAR:sink-damp]` in `notes/Avatar_Design.md § 9`

---

## Recently Completed: Sink Dampening (`Q_DAMP_VERT`)

A vertical thrust damper was implemented to arrest STABILIZE-mode crashes caused by tilting the rotors forward faster than the wings can build aerodynamic lift.

**Architecture:** When `avatar_sink_rate > 0` in STABILIZE (gated to `tilt_deg < 90°`), `plane_inputs.damp_vert_thrust = avatar_sink_rate × damp_vert_gain` is passed to the AvatarMixer. The mixer uses force-vector decomposition: it adds the vertical demand to the existing thrust vector, then recomposes via `atan2`/`sqrt` to get a new tilt angle (tilted back toward vertical) and new throttle. When saturated at max throttle, vertical is prioritized and forward thrust is sacrificed. Tilt-back is rate-capped at `Q_TILT_RATE_UP × dt`. FBWA is unaffected (TECS handles altitude there).

**Parameters:**
- `Q_DAMP_VERT` (default 0.15, range 0–0.3): vertical thrust demand per m/s of sink rate. At 0.15, a 2 m/s sink adds 0.30 vertical thrust units.

**Files changed:** `ArduPlane/quadplane.h`, `ArduPlane/quadplane.cpp`, `libraries/AP_Motors/AP_Motors6DOF.h`, `libraries/AP_Motors/AP_Motors6DOF_Mixer.h`, `libraries/AP_Motors/AP_Motors6DOF.cpp`, `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp`

---

## Next Task: Tilt-Scaled Minimum Throttle Guard

### Problem

In auto-throttle plane modes (CRUISE, FBWB), TECS manages altitude by adjusting throttle. When the pilot commands hover (low speed, rotors vertical), TECS may reduce throttle toward `THR_MIN` (typically 0%) during a descent. With rotors vertical there is **zero aerodynamic lift** — motor thrust is the only thing keeping the aircraft up. If TECS cuts motors to 0%, the aircraft loses all stabilization authority and the ESCs take 1–2 seconds to spool back up on re-throttle. This causes a severe drop or crash.

### Accepted Solution: Tilt-Scaled Minimum Throttle Floor

Apply a cosine-scaled minimum throttle floor in the `plane_inputs.throttle_pct` assignment in `quadplane.cpp`:

```
min_throttle_limit_pct = (Q_M_SPIN_MIN × cos(tilt_deg)) × 100
```

- **Vertical rotors (0°):** floor = `Q_M_SPIN_MIN` (typically 15%) — motors always spinning
- **Horizontal rotors (90°):** floor = 0% — normal aerodynamic glide allowed
- **Transition angles:** smooth linear blend via cosine

Gated by `plane.is_flying()` to avoid spinning up on the ground when armed. Also gated by `!g_config.tricopter_is_blimp` (blimps are buoyant and don't need this).

**Why not spool state gating:** In ArduPlane plane modes, motors are unconditionally forced to `THROTTLE_UNLIMITED` when armed — `get_spool_state()` is always `THROTTLE_UNLIMITED` even on the ground, making it useless as a gate.

### Exact Implementation

**Location:** `ArduPlane/quadplane.cpp`, inside the `#if ENABLE_TRICOPTER_VTOL_BACKEND` plane_inputs block, around line 1744. The current code there is:

```cpp
// We must calculate throttle percent manually since we are running before servos_output
plane_inputs.throttle_pct = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);
// [AV-INVAR:sink-damp] — see Avatar_Design.md § 9
plane_inputs.damp_vert_thrust = avatar_sink_rate * damp_vert_gain;
```

Replace with:

```cpp
// We must calculate throttle percent manually since we are running before servos_output
float throttle_pct = SRV_Channels::get_output_scaled(SRV_Channel::k_throttle);
// [AV-INVAR:min-thr-tilt] — see Avatar_Design.md § 9
if (plane.is_flying() && !g_config.tricopter_is_blimp) {
    const float tilt_deg_g = ((AP_Motors6DOF*)motors)->get_tilt_deg();
    const float cos_tilt_g = fmaxf(0.0f, cosf(radians(tilt_deg_g)));
    const float spin_min   = ((AP_Motors6DOF*)motors)->thr_lin.get_spin_min();
    const float min_thr    = (spin_min * cos_tilt_g) * 100.0f;
    if (throttle_pct < min_thr) {
        throttle_pct = min_thr;
    }
}
plane_inputs.throttle_pct = throttle_pct;
// [AV-INVAR:sink-damp] — see Avatar_Design.md § 9
plane_inputs.damp_vert_thrust = avatar_sink_rate * damp_vert_gain;
```

The `damp_vert_thrust` line **must be preserved** exactly as-is after the throttle assignment — it is part of the sink dampening system implemented this session.

**Check:** verify `thr_lin.get_spin_min()` is accessible as a public member on `AP_Motors6DOF*`. It is used internally in `AP_Motors6DOF.cpp` already (feeds `inputs.spin_min` in the mixer). If `thr_lin` is not directly public, use `motors->get_throttle_hover()` as a fallback approximation, or expose a getter.

### Avatar_Design.md

Add a new `[AV-INVAR:min-thr-tilt]` entry in **§ 9** documenting:
- What: cosine-scaled minimum throttle floor on `plane_inputs.throttle_pct`
- Where: `quadplane.cpp` plane_inputs block, gated by `plane.is_flying() && !tricopter_is_blimp`
- Why: TECS can command 0% throttle with vertical rotors — zero aerodynamic lift + no motor thrust = unrecoverable. ESC spool-up lag (1–2s) makes it a crash.
- Why not spool state: always `THROTTLE_UNLIMITED` in plane modes even on ground
- Why `cos(tilt)`: allows normal glide at wings-horizontal; prevents motor cutoff at wings-vertical; smooth blend in between

### Verification Plan (from design doc)

1. **Ground safety:** arm in CRUISE, tilt rotors vertical — motors must NOT spin up (is_flying() = false)
2. **In-flight hover descent:** enter hover via low throttle in CRUISE, descend — throttle must not drop below `Q_M_SPIN_MIN × 100`% while rotors are vertical
3. **Glide check:** in CRUISE at cruise speed, cut throttle — motors should be allowed to go to 0% when rotors are horizontal
4. **Touchdown:** after landing, `is_flying()` returns false, motors allowed to spin down to 0%

### No New Parameters Required

This feature uses the existing `Q_M_SPIN_MIN` parameter. No new param registration needed.

---

## Architecture — How STABILIZE Mode Works

**The FC maintains copter and plane mode logic simultaneously.** `transition_progress` is binary: `in_vtol_mode() ? 0.0 : 1.0`.

In STABILIZE (plane mode, `transition_progress=1.0`), the `AvatarMixer::mix()` plane branch runs:

1. **Tilt control:** `pitch_tilt_demand = channel_pitch->norm_input_dz()` (pilot pitch stick, ±1). Rate-limited via `Q_TILT_RATE_UP`. In-code: `quadplane.cpp ~line 1761`.
2. **Sink dampening:** force-vector decomposition in mixer tilts rotors back and boosts throttle proportional to `damp_vert_thrust`.
3. **Pitch stabilisation:** copter attitude PID targeting 0° pitch. Written via `rate_bf_pitch_target()` — **do not use** `input_euler_angle_*`.
4. **Elevator out:** `outputs.elevator_out = inputs.pitch` (rear motor + elevator surface).
5. **Wing motors:** `throttle_pct ± roll_delta`. Roll fades with `cos_tilt_b`.
6. **Rear motors:** `(throttle_pct - inputs.pitch) * cos_tilt_b` ± yaw differential.

**Critical: `ATT.DesPitch` is always 0 in STABILIZE.** Use `RCIN.C2` for pilot stick position in logs.

---

## Key Code Files

| File | Purpose |
|------|---------|
| `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` | Motor mixing — plane/copter branch, tilt, roll/yaw, sink dampening decomposition |
| `libraries/AP_Motors/AP_Motors6DOF_Mixer.h` | `MixerInputs` struct — `plane.damp_vert_thrust` field |
| `libraries/AP_Motors/AP_Motors6DOF.h` | `PlaneInputs` struct — `damp_vert_thrust` field |
| `libraries/AP_Motors/AP_Motors6DOF.cpp` | Copies `PlaneInputs` → `MixerInputs`; exposes `thr_lin` |
| `ArduPlane/quadplane.cpp` | `set_plane_inputs()` ~line 1730 — tilt demand, throttle, damp_vert_thrust, sink_rate gate |
| `ArduPlane/quadplane.h` | `damp_vert_gain` member |
| `ArduPlane/Attitude.cpp` | STABILIZE elevator stick suppression; surface I-decay |
| `libraries/AP_CustomConfig/AP_CustomConfig.cpp` | `avatarConfig` — `forward_flight_physical_angle_deg=95`, `cruise_physical_angle_deg=90` |
| `params/avatar_t1ranger_micoair.param` | Golden param file — source of truth |
| `notes/Avatar_Design.md` | Full architecture reference with design invariants `[AV-INVAR:*]` |

---

## RC Channel Mapping (STABILIZE)

| Channel | Function | Low (1300) | High (1700) |
|---------|----------|-----------|------------|
| RCIN.C2 | Pitch stick / tilt demand | Tilt FORWARD (toward horizontal) | Tilt BACKWARD (toward vertical) |
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
Q_DAMP_VERT    = 0.15
```

---

## Connectivity

### ELRS TX Backpack (preferred)
Toggle telemetry WiFi off then on in Radiomaster backpack settings. QGC UDP: `udp://0.0.0.0:14550`.

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

**Key log fields for Avatar debugging:**

| Field | Meaning |
|-------|---------|
| `RCIN.C2` | Pilot pitch stick (use this — NOT ATT.DesPitch) |
| `RCIN.C3` | Pilot throttle (raw PWM 1000–2000) |
| `RCOU.C5` | Tilt servo actual output PWM |
| `XKF1.VD` | EKF3 velocity down (m/s, positive = sinking) |
| `CTUN.CRate` | Climb rate cm/s (negate and ÷100 = m/s sink) |
| `ATT.Pitch` | Actual pitch angle |

**`AVATAR_DEBUG_LOG 1`** is currently enabled in `AP_Motors6DOF_AvatarMixer.cpp` line 7. Disable before production.

---

## Motor Layout

| Index | Define | Physical | SERVO | SERVO_FUNCTION |
|-------|--------|----------|-------|----------------|
| 0 | `AVATAR_MOT_WING_LEFT` | Left wing motor | SERVO1 | 33 |
| 1 | `AVATAR_MOT_WING_RIGHT` | Right wing motor | SERVO4 | 34 |
| 2 | `AVATAR_MOT_YAW_RIGHT` | Right rear yaw motor | SERVO3 | 35 |
| 3 | `AVATAR_MOT_YAW_LEFT` | Left rear yaw motor | SERVO2 | 36 |

Tilt servo: **SERVO5** (`RCOU.C5` in logs). `SERVO5_MIN=700`, `SERVO5_TRIM=1827`, `SERVO5_REVERSED=1`.

---

## Known Outstanding Items

1. **Tilt-scaled minimum throttle guard** — next task (see above)
2. **Q_DAMP_VERT first flight validation** — verify 0.15 is appropriate, check no false activations during normal transitions
3. **FBWA real flight** — bench-validated only
4. **Notch filter verification** — needs a flight; check `FTN` messages at ~258 Hz
5. **Yaw PID tuning** — reduce `Q_A_RAT_YAW_I` 0.005→0.0025 if low-freq oscillation observed
6. **`AVATAR_DEBUG_LOG=1`** — disable before production
7. **Param file hygiene** — `Q_DAMP_TILT` and `Q_DAMP_THR` no longer exist; dump fresh params after next flash to clean them from the file
