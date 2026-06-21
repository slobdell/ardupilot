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

## Outstanding Items

1. **Dump golden params** — `python3 tools/mavlink/param_dump.py -v -o params/avatar_t1ranger_micoair.param`
2. **Yaw hardware fix** — cant rear motors out 2–5° to recover yaw authority (software maxed)
3. **Motor heat** — fundamental thrust-to-weight issue with 2-blade props; monitor in extended hover
4. **Transition testing** — roll and yaw software tunes are locked, aircraft is ready

---

## Connectivity

```bash
python3 tools/mavlink/monitor.py              # USB serial with battery voltage
python3 tools/mavlink/monitor.py --elrs | grep TILT   # ELRS + filter
python3 tools/mavlink/param_set.py --elrs PARAM VALUE
python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
./micoair_flash.sh --flash                   # build + OTA flash
```
