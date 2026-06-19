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
- **Weathervaning:** `Q_WVANE_GAIN=1.0` set; active in QLOITER (light wind test, seemed fine)
- **Altitude control:** fixed blimp-era params; `Q_PILOT_SPD_UP=2.5`, `Q_PILOT_ACCEL_Z=1.0` — climb rate now responsive, `Q_PILOT_ACCEL_Z` may need further tuning
- **STABILIZE (plane mode):** fully implemented and bench-validated
- **FBWA:** bench + plane-mode tested; elevator holds level, TVC tilt responds to TECS
- **Past-horizontal tilt:** implemented; `SERVO5_MIN=700`, `forward_flight_physical_angle_deg=95`

---

## Next Task: FFT Tuning and Notch Filtering

> See `notes/fft_tuning.md` for the full procedure.


### Goal
Enable the in-flight FFT engine to identify motor noise frequencies, then configure the harmonic notch filter to suppress that noise. This improves attitude control loop performance by reducing gyro noise fed to the PIDs.

### Current param state
```
FFT_ENABLE       = 0    # not yet enabled
INS_HNTCH_ENABLE = 0    # notch filter disabled
INS_HNTC2_ENABLE = 0    # second notch disabled
INS_GYRO_FILTER  = 20   # gyro LPF at 20 Hz
```

### Step 1 — Enable FFT and do an analysis flight

```bash
python3 tools/mavlink/param_set.py --elrs FFT_ENABLE 1
# Then reboot the FC — FFT_ENABLE requires a reboot to activate
```

After reboot, other `FFT_*` params will appear in GCS. Defaults are appropriate — no further FFT params need changing for the initial analysis flight.

**Analysis flight procedure:**
1. Hover in QSTABILIZE or QLOITER for ~2 minutes at normal cruise throttle
2. Download the log: `python3 tools/mavlink/log_download.py --elrs`
3. Analyze: `python3 tools/mavlink/log_analyze.py logs/flight.BIN`
4. Look for `FTN` messages in the log — these contain the FFT-detected noise peak frequency (`PkAvg` field). This is the frequency the notch should target.

### Step 2 — Configure the harmonic notch

Once the dominant noise frequency is known from the log, set:

```bash
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_ENABLE 1
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_MODE 4      # 4 = FFT-driven frequency
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_REF 1       # 1 = no scaling (correct for FFT mode)
python3 tools/mavlink/param_set.py --elrs INS_HNTCH_FREQ <Hz>   # set to the observed peak from FTN log
```

`INS_HNTCH_FREQ` in FFT mode sets the minimum tracked frequency (a floor), not a fixed center — the FFT will dynamically adjust above it.

### Step 3 — Verify and tune bandwidth

Default `INS_HNTCH_BW` is `INS_HNTCH_FREQ / 2`. After enabling, do another flight and check:
- Attitude control feels the same or better (no oscillation)
- CPU load is acceptable (check `PERF` messages in log)
- `FTN` messages show the notch tracking the noise peak

Use the ArduPilot Filter Tool (`firmware.ardupilot.org/Tools/FilterTool/`) to check phase lag if tuning bandwidth.

### Key tradeoffs to know
- FFT mode can lag throttle-based notch since FFT computation takes time — acceptable for this airframe since rotor frequency is fairly stable
- Enabling `INS_HNTCH_OPTS` bit 1 (multi-peak tracking) adds phase lag; only use if single-peak filter leaves residual noise — if used, reduce BW to `FREQ/4` ratio instead of default `FREQ/2`
- Only 1 FFT-driven notch is supported; `INS_HNTC2` can be set to a different mode if a second notch is needed

### Auto-setup option (alternative to manual)

RC8 (3-position switch) is assigned to option 162. To set it:

```bash
python3 tools/mavlink/param_set.py --elrs RC8_OPTION 162
```

**Procedure:** Hover in QSTABILIZE or QLOITER at normal cruise throttle → flip RC8 to HIGH for ~30s → flip back to LOW → land. Parameters are auto-configured on landing.

**Do not use in firmware 4.3** (known bug). Verify firmware version first (`python3 tools/mavlink/log_analyze.py` prints FW version, or check QGC).

After auto-setup completes, dump params immediately:
```bash
python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
```

Then verify `INS_HNTCH_*` values were written before the next flight.

---

## Altitude Tuning — May Need Further Work

`Q_PILOT_ACCEL_Z = 1.0` was set after `2.5` caused oscillation on climb. The Z velocity PID was tuned at the old `0.5` value. If climb still feels sluggish, can try stepping up to `1.5`. If oscillation returns, the real fix is re-tuning `Q_P_VELZ_P` (currently `5`) alongside the accel.

QSTABILIZE→QLOITER mode switch jerk: inherent when throttle is high in QSTAB. Reduced accel softens it; no param fully eliminates it — just enter QLOITER near hover throttle.

---

## Key Code Files

| File | Purpose |
|------|---------|
| `libraries/AP_Motors/AP_Motors6DOF_AvatarMixer.cpp` | Motor mixing — plane/copter branch, tilt angle, roll/yaw differential |
| `libraries/AP_Motors/AP_Motors6DOF.cpp` | Thrust linearization; `MixerInputs` population; AV6 debug log |
| `libraries/AP_CustomConfig/AP_CustomConfig.cpp` | `avatarConfig` — `forward_flight_physical_angle_deg=95`, `cruise_physical_angle_deg=90` |
| `ArduPlane/quadplane.cpp` | VTOL mode logic; `get_weathervane_yaw_rate_cds()` at line 3931 |
| `ArduPlane/Attitude.cpp` | STABILIZE elevator stick mixing suppression; surface I-decay |
| `ArduPlane/mode_qloiter.cpp` | QLOITER mode — calls `get_desired_yaw_rate_cds()` (weathervane included by default) |
| `libraries/AC_AttitudeControl/AC_WeatherVane.cpp` | Weathervane controller |
| `params/avatar_t1ranger_micoair.param` | Golden param file — source of truth |
| `notes/Avatar_Design.md` | Full architecture reference with design invariants `[AV-INVAR:*]` |
| `notes/TODO.md` | Outstanding items |

---

## Motor Layout

| Index | Define | Physical | SERVO | SERVO_FUNCTION |
|-------|--------|----------|-------|----------------|
| 0 | `AVATAR_MOT_WING_LEFT` | Left wing motor | SERVO1 | 33 |
| 1 | `AVATAR_MOT_WING_RIGHT` | Right wing motor | SERVO4 | 34 |
| 2 | `AVATAR_MOT_YAW_RIGHT` | Right rear yaw motor | SERVO3 | 35 |
| 3 | `AVATAR_MOT_YAW_LEFT` | Left rear yaw motor | SERVO2 | 36 |

---

## Current PID Values (golden param file)

### Roll
```
Q_A_RAT_RLL_P  = 0.45
Q_A_RAT_RLL_I  = 0.25
Q_A_RAT_RLL_D  = 0.004
Q_A_RAT_RLL_FF = 0.15
Q_A_RATE_R_MAX = 150
Q_A_ACCEL_R_MAX = 40000
```

### Yaw
```
Q_A_RAT_YAW_FF   = 0.5
Q_A_RAT_YAW_P    = 0.03
Q_A_RAT_YAW_I    = 0.01
Q_A_RAT_YAW_D    = 0.0
Q_A_RATE_Y_MAX   = 150
Q_A_ACCEL_Y_MAX  = 4000
```

### Vertical position controller
```
Q_P_VELZ_P      = 5
Q_PILOT_SPD_UP  = 2.5   (m/s)
Q_PILOT_SPD_DN  = 0     (uses SPD_UP when 0)
Q_PILOT_ACCEL_Z = 1.0   (m/s²) — tuned this session; was 0.5 (blimp artifact)
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
```

### Flash firmware
```bash
./micoair_flash.sh --flash
# Build: ./waf configure --board MicoAir743 && ./waf plane
```

---

## Log Tooling

```bash
python3 tools/mavlink/log_download.py --elrs
python3 tools/mavlink/log_analyze.py logs/flight.BIN
python3 tools/mavlink/log_analyze.py logs/flight.BIN --mode QLOITER
```

---

## Known Outstanding Items

1. **FFT + notch filtering** — next task (see above)
2. **`AVATAR_DEBUG_LOG=1`** in `AP_Motors6DOF_AvatarMixer.cpp` — AVB/AVC messages log every 1–3s. Disable before production flights (`#define AVATAR_DEBUG_LOG 0`)
3. **KFF_RDDRMIX** — aileron-rudder mix feeds rear motor yaw differential via `k_rudder`. May cause roll→yaw coupling in slow flight. Set `KFF_RDDRMIX=0` if observed
4. **Q_TILT_RATE_UP** — currently 600°/s (confirmed in golden params)
5. **Yaw PID D-term** — `Q_A_RAT_YAW_D=0`; add in small increments (start 0.001) to damp oscillation if needed
6. **Rear motor gain tuning** and **elevator gain/slew** — see `TODO.md`

---

## Yaw Mechanism Note

Spring-lever differential: higher-thrust side swings outward for yaw. Current criss-cross geometry inverts natural yaw direction — `YAW_LEFT = rear + yaw_delta`, `YAW_RIGHT = rear - yaw_delta` (signs swapped from intuition). Will need reverting when mechanism is rebuilt with outward-facing geometry. All gains will need re-tuning from scratch after that rebuild.
