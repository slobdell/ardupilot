# Avatar Zoh Altus VTOL — Handoff
**Date:** June 2026  
**FC:** MicoAir H743 (`AHRS_ORIENTATION=6`)  
**Branch:** `slobdell_base`  
**Golden params:** `params/avatar_t1ranger_micoair.param` (source of truth)

---

## Hardware Config (Current)
- **Props:** 6-inch 4.5-pitch (recently swapped from 3-blade standard)
- **Notch filter:** `INS_HNTCH_FREQ=361.27 Hz` (re-tuned for new props via RC8 auto-setup)
- **Hover throttle:** `Q_M_THST_HOVER=0.35` — aircraft works hard to hover; margins are tight

---

## Roll PID — Tuned to Physical Authority Limit (June 21, 2026)

### Final Values
```
Q_A_RAT_RLL_P  = 0.200
Q_A_RAT_RLL_I  = 0.200
Q_A_RAT_RLL_D  = 0.004
Q_A_RAT_RLL_FF = 0.180
```

### Tuning Journey
| Round | P | I | D | FF | Result |
|-------|---|---|---|----|--------|
| Original | 0.45 | 0.25 | 0.004 | - | ~21 Hz opposing oscillation, hot motors |
| Round 2 | 0.30 | 0.10 | 0.008 | - | Better but oscillation persisted |
| Round 3 | 0.25 | 0.10 | 0.012 | - | Same — D too high was the real problem |
| Round 4 | 0.20 | 0.10 | 0.012 | - | No improvement — confirmed D not P |
| Round 5 | 0.20 | 0.10 | 0.006 | - | Much better — D was the issue |
| Round 6 | 0.25 | 0.20 | 0.006 | 0.15 | Clean — phase lag and gritty motors |
| Round 7 | 0.20 | 0.20 | 0.006 | 0.18 | Phase lag cleared, high-freq grit on motors |
| **Final** | **0.20** | **0.20** | **0.004** | **0.18** | **Software tune maxed out — see below** |

**Key lesson learned:** D was the primary driver of the 21 Hz oscillation, NOT P. D was reduced (0.012 → 0.006 → 0.004) to resolve it.

### Physical Authority Limit Reached
C1 and C4 hover at ~1700–1750 µs mean with a ceiling of 1949 µs. During aggressive roll maneuvers both motors still clip at ~1890–1894 µs. The integrator and rate loop are optimized — residual clipping is a prop/weight constraint.

**Further PID changes will not help.** The tracking profile is tight, low-frequency hunting is gone, and D-term noise is mitigated.

---

## Yaw PID — Tuned to Physical Authority Limit (June 21, 2026)

### Final Values
```
Q_A_RAT_YAW_P    = 0.22
Q_A_RAT_YAW_I    = 0.08
Q_A_RAT_YAW_D    = 0.006
Q_A_RAT_YAW_FF   = 0.40
Q_A_RAT_YAW_IMAX = 0.5
Q_A_RAT_YAW_FLTE = 2.5  (verified, not a source of lag)
```

### Tuning Journey
| Round | P | I | D | FF | Result |
|-------|---|---|---|----|--------|
| Original | 0.20 | 0.005 | 0.006 | 0.35 | Sluggish response, 25° steady-state error |
| Round 2 | 0.25 | 0.020 | 0.006 | 0.45 | Dynamic tracking improved, but 25° offset remained |
| Round 3 | 0.25 | 0.080 | 0.006 | 0.45 | Offset gone, but P+FF caused motor saturation oscillation |
| Round 4 | 0.22 | 0.080 | 0.006 | 0.40 | Clean dynamic tracking, oscillation eliminated |
| **Final** | **0.22** | **0.08** | **0.006** | **0.40** | **Software tune maxed out — see below** |

### Physical Authority Limit Reached
Even at final values, RCOU.C2 and C3 ride near 1949 µs continuously during QLOITER, and a ~10° steady-state gap reopens under sustained yaw load. The integrator (I=0.08) cannot close it because the actuators have no remaining headroom.

**Further PID increases will not help** — they will only reintroduce saturation oscillation without adding real authority.

### Hardware Fix Required
To recover yaw authority, one of:
1. **Increase rear motor cant angle by 2–5°** — scales up the yaw torque vector geometrically without costing more throttle
2. **Reduce airframe weight** — reclaims hover throttle margin
3. **Higher-pitch or larger prop on rear motors** — lowers base hover PWM, freeing headroom for yaw corrections

---

## How to Read Logs for PID Diagnosis

### Motor Layout → RCOU Channels
| RCOU | Motor | Role |
|------|-------|------|
| C1 | Left wing | Roll/throttle |
| C2 | Left rear | Yaw/throttle |
| C3 | Right rear | Yaw/throttle |
| C4 | Right wing | Roll/throttle |

### Roll Diagnosis: C1 vs C4
- **C1 and C4 moving together (correlated):** normal — throttle/altitude corrections
- **C1 and C4 opposing (one up, other down):** roll corrections — expected during actual roll events, a problem if continuous at fixed frequency
- **Continuous opposing oscillation at fixed frequency:** rate loop PID issue

### Yaw Diagnosis: C2 vs C3
- Same logic — opposing oscillation between rear motors = yaw rate loop issue
- Correlated = normal throttle

### Attitude Tracking Overlay
Always overlay **ATT.Roll vs ATT.DesRoll** against motor opposition:
- Motors opposing + attitude diverging = correct response to real disturbance ✓
- Motors opposing + attitude rock solid = rate loop oscillating ✗ (PID needs tuning)

### What "Good" Looks Like
- Slow, smooth correlated movement on all motors (following altitude/throttle)
- Small, gentle opposing movements that correlate with actual attitude changes
- Opposing deviations that settle quickly (not sustained at a fixed frequency)
- **NOT a flat line** — some variation is expected and healthy

### Oscillation Frequency → What It Means
| Frequency | Likely Cause |
|-----------|-------------|
| >15 Hz | D amplifying noise, or P too high |
| 5–15 Hz | P too high in rate loop |
| 2–5 Hz | Could be normal flight dynamics — check if attitude oscillates too |
| <2 Hz | Outer loop (angle P) or altitude controller |

### Diagnosing D vs P
- **Lower P, oscillation unchanged** → D is the problem (or noise/FF)
- **Lower P, oscillation improves** → P was the cause
- **Lower D, oscillation improves** → D was amplifying noise
- **Raise D, oscillation worsens** → noise-driven, D is making it worse

---

## PID Tuning Workflow

### Roll / Yaw Rate Loop
1. Start with conservative P, low I (temporary), moderate D
2. Identify oscillation frequency from RCOU logs
3. **Test P and D independently** — don't change both simultaneously
4. Confirm with ATT.Roll vs ATT.DesRoll overlay (is attitude tracking or oscillating?)
5. Once stable: restore I toward 0.20, check for slow drift
6. Dump params when done: `python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param`

### Setting Params
```bash
# Single or multiple params
python3 tools/mavlink/param_set.py Q_A_RAT_RLL_P 0.25 Q_A_RAT_RLL_D 0.006
python3 tools/mavlink/param_set.py --elrs Q_A_RAT_RLL_P 0.25   # via ELRS
```

### Downloading Logs
```bash
python3 tools/mavlink/log_download.py              # latest
python3 tools/mavlink/log_download.py --id 48      # specific log
python3 tools/mavlink/log_download.py --elrs        # via ELRS
```

---

## Key Param Values for Context

```
INS_HNTCH_FREQ  = 361.27 Hz   (notch filter, tuned for 6-inch 4.5-pitch props)
INS_HNTCH_BW    = 180.63 Hz
INS_HNTCH_MODE  = 1           (throttle-scaled)
Q_M_THST_HOVER  = 0.35        (learned hover throttle — fairly high, motors work hard)
Q_DAMP_VERT     = 0.60        (vertical sink dampening — working well)
Q_DAMP_LONG     = 0.20        (longitudinal acceleration dampening — working well)
Q_STAB_PTCH_DEG = 3.0         (3° nose-up target in STABILIZE for aero efficiency)
Q_WVANE_GAIN    = 1.0         (weathervaning active in QLOITER)
```

---

## STABILIZE Dampening — Q_DAMP_VEL (June 21, 2026)

Custom velocity-hold dampener for STABILIZE plane mode. Replaces the oscillation-prone acceleration-based `Q_DAMP_LONG` (now set to 0).

### How it works
P controller on body-frame forward velocity error. When the pitch stick returns to neutral, the controller snapshots the current forward speed as the hold target. Correction = `-(vel_bf_x - hold_target) × Q_DAMP_VEL × fade`. When the stick is active, the hold target slews toward current velocity (rate-limited to 0.5 m/s²) so release always anchors near the current speed. Same stick-fade logic as Q_DAMP_LONG (100ms fade-out, 500ms recovery). **Throttle stick activity is also detected** (rate-of-change, 200ms latch) — throttle changes also trigger fade-out and target slewing.

### Safety guards (all in `ArduPlane/quadplane.cpp`)
- **Slew rate limit** (`VEL_HOLD_TARGET_SLEW_MS2 = 0.5 m/s²`): hold target can't teleport on brief stick touch → prevents backward lurch
- **Error cap** (`VEL_DAMP_ERROR_CAP_MS = 1.5 m/s`): clamps error fed to gain → backstop against violent tilt snap
- **Saturation guard** (`throttle >= 0.95`): freezes hold target when motors are maxed → prevents runaway target corruption
- **Throttle deadband** (`THROTTLE_DELTA_THRESHOLD = 0.02`, `THROTTLE_ACTIVE_LATCH_S = 0.2s`): ignores RC jitter on throttle channel

### Current values
```
Q_DAMP_VEL       = 0.20   (tuned — was 0.05 initial)
Q_DAMP_LONG      = 0      (disabled)
Q_DAMP_LONG_FILT = 5      (unused but left set)
Q_DAMP_VERT      = 0.35   (validated)
Q_TILT_EXPO      = 0.5    (raised from 0.3 — less sensitive near centre)
```

### Log signals (AVSD message)
| Field | Description |
|-------|-------------|
| `VxBf` | Body-frame forward velocity — controlled signal |
| `VxHld` | Hold target — should freeze on stick release |
| `DmpH` | Total horizontal damp output |
| `Fade` | Combined pitch+throttle activity fade (1=active, 0=suppressed) |
| `TTgt` | Force-vector tilt target — diverges from PTilt when correction active |

### Design doc
Full invariant: `Avatar_Design.md § 9 [AV-INVAR:vel-damp]`

---

## Outstanding Items

1. **Weathervaning investigation** — see next section
2. **Dump golden params** — `python3 tools/mavlink/param_dump.py -v -o params/avatar_t1ranger_micoair.param`
3. **Yaw hardware fix** — cant rear motors out 2–5° to recover yaw authority (software maxed)
4. **Motor heat** — fundamental thrust-to-weight issue with 2-blade props; monitor in extended hover
5. **Pre-production cleanup** — disable `AVATAR_DEBUG_LOG` flag and remove TILT GCS debug message

---

## NEXT TASK: Weathervaning Investigation

### Problem statement
In STABILIZE (Avatar plane mode) and QSTABILIZE, there is no effective weathervaning — the aircraft does not align its nose to the wind. The pilot reported this; `Q_WVANE_GAIN=1.0` is set but appears inactive.

### Why it's not working — code analysis

**Built-in ArduPilot weathervaning** (`QuadPlane::get_weathervane_yaw_rate_cds`, `quadplane.cpp:4175`):
- First guard: `!in_vtol_mode()` — returns `false` in STABILIZE (plane mode), so the function immediately returns 0
- Explicitly also excluded from QSTABILIZE (`plane.control_mode == &plane.mode_qstabilize`, line 4184) and QHOVER
- So `Q_WVANE_GAIN` is set but the function never executes in the modes we fly

**Custom weathervaning** (`g_config.custom_weathervane`, `ArduCopter/mode_loiter.cpp`):
- This is feature-flagged custom code in the **ArduCopter binary** only
- Uses `attitude_control->input_thrust_vector_heading()` instead of `input_thrust_vector_rate_heading()` — targets a compass heading rather than a yaw rate
- Does NOT exist in the ArduPlane binary that Avatar runs

### Investigation steps for next agent
1. **Confirm via logs**: Plot `ATT.Yaw` and `ATT.DesYaw` during a windy hover — if they both drift with wind (no heading correction), weathervaning is confirmed absent
2. **Read the AC_WeatherVane library**: `libraries/AC_AttitudeControl/AC_WeatherVane.h/.cpp` — understand what inputs it needs and what it outputs
3. **Decide architecture**: Should weathervaning in STABILIZE use:
   - The existing `AC_WeatherVane` controller (add a call in the STABILIZE yaw path)?
   - A simpler custom implementation (e.g., feed wind-direction error into the yaw PID)?
4. **Compare built-in vs custom**: The custom `input_thrust_vector_heading()` approach (ArduCopter LOITER) is more tightly integrated with the attitude controller than the rate-addition approach. Understand the tradeoff before choosing.

### Key files
- `ArduPlane/quadplane.cpp:4175` — `get_weathervane_yaw_rate_cds()` (built-in, gated out)
- `ArduCopter/mode_loiter.cpp:106` — custom weathervane flag usage
- `ArduPlane/quadplane.cpp:1415` — `get_desired_yaw_rate_cds()` (where weathervane yaw is added in VTOL modes)
- `libraries/AC_AttitudeControl/AC_WeatherVane.h` — the controller itself

---

## Connectivity

```bash
python3 tools/mavlink/monitor.py              # USB serial with battery voltage
python3 tools/mavlink/monitor.py --elrs | grep TILT   # ELRS + filter
python3 tools/mavlink/param_set.py --elrs PARAM VALUE
python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
./micoair_flash.sh --flash                   # build + OTA flash
```
