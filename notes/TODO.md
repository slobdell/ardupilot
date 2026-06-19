# TODO

Outstanding items identified through design, code investigation, and bench testing. Items marked **Needs Aircraft** require the physical airframe to validate.

---

## Avatar — Needs Aircraft

**Past-horizontal tilt for pitch-down descent** *(Avatar_Design.md § 4.4.3)*
Full design documented in § 4.4.3. Summary of changes needed:
- Add `cruise_physical_angle_deg` field to `CustomConfig` (e.g., `90.0f`)
- Change `forward_flight_physical_angle_deg` in `avatarConfig` to the new physical servo max (e.g., `95.0f`)
- `AvatarMixer` plane mode formula: `cruise_norm * (1.0f - pitch_tilt_demand)` instead of `1.0f - pitch_tilt_demand`
- `AvatarMixer` copter mode: clamp TVC output at `cruise_norm` to prevent past-horizontal in copter mode
- Servo calibration: physically set wings to horizontal, read PWM, set `SERVO5_MIN` to that value

**Backward servo range (braking / reverse, copter mode)** *(Avatar_Design.md § 4.6)*
Full design documented in § 4.6. Summary of changes needed:
- Set `avatarConfig.reverse_flight_physical_angle_deg` to a negative value matching the physical backward limit (currently `0.0f`, relies on a `0.1f` division guard)
- Extend `SERVO5_MAX` past `SERVO5_TRIM` (currently both = 1827; `tilt_angle < 0` has no effect until MAX is raised)
- Plane mode is already safe — the formula clamp prevents negative tilt regardless of servo range

**Rear motor gain tuning**
Rear motor contribution in plane mode (`(throttle_pct - inputs.pitch) * cos_tilt`) has not been flight-validated. The `inputs.pitch` gain is currently determined by `att_kP` from the copter attitude controller. May need a separate scaling factor once real flight behavior is observed.

**Elevator gain scalar and slew rate limit**
The elevator in plane mode is driven directly by the copter attitude PID output (`outputs.elevator_out = inputs.pitch`). If the P gain is too high, the servo may hunt continuously to null small pitch errors, risking servo burnout. After first flight, evaluate whether to add: (1) a `g_config.elevator_gain_scale` multiplier to reduce elevator authority independently of motor PID tuning, and (2) a per-loop slew rate cap (`g_config.elevator_slew_rate`) to bound how fast the servo can be commanded to move. Do not add these preemptively — observe actual servo behavior first.

**Calibrate `Q_TILT_RATE_UP` against actual servo speed** *(Avatar_Design.md § 9, [AV-INVAR:tilt-servo-tracking])*
`Q_TILT_RATE_UP = 120 °/s` in the param file is an estimate. It is a *dependent variable* — it must match the physical servo speed, not a design preference. Wrong value means copter-mode motor mixing (cos_tilt, roll authority, rear motor) and throttle scaling are computed against an inaccurate physical model during transitions.

Calibration procedure:
1. Command the tilt servo from 0° to 90° (wings vertical → horizontal) via RC override
2. Time the travel with a stopwatch or flight log
3. Compute: `Q_TILT_RATE_UP = 90 / measured_seconds` (°/s)
4. Update `params/avatar_t1ranger_micoair.param` and `params/avatar_t1ranger_micoair_sitl.param`

Note: in plane mode, setting `Q_TILT_RATE_UP` at or below the real servo speed guarantees math accuracy by construction (the command never races ahead of the servo). `Q_TILT_RATE_DN = 30 °/s` is independent of servo speed and does not need calibration.

**Enable weathervaning in QLOITER** *(Needs Aircraft)*
QLOITER is now validated. Next step: enable nose-into-wind weathervaning. Two things needed:
1. Set `custom_weathervane = true` in the Avatar config in `libraries/AP_CustomConfig/AP_CustomConfig.cpp` (currently `false`). The custom weathervane code is in `ArduCopter/mode_loiter.cpp`.
2. Set the WVANE params (starting values from `Avatar_Design.md § 5.2`):
```
WVANE_DIRECTION = 1      # nose into wind
WVANE_GAIN      = 1.0    # increase for more aggressive response
WVANE_ANG_MIN   = 1.0    # deadzone in degrees to prevent hunting
```
For ArduPlane QLOITER the stock `AC_WeatherVane` path may be sufficient with just the params — verify whether `custom_weathervane` also needs to be wired into the ArduPlane QLOITER path or if it's ArduCopter-only.

**Plane mode stall-prevention validation**
The stall-prevention loop (elevator saturates → wings tilt upward via TVC pitch compensation) is theoretically sound and bench-verified, but the transition boundary behavior is untested. Tilt slew rate limiting is now implemented and unit-tested ([AV-INVAR:plane-tilt-slew]): releasing the pitch stick takes 3 seconds to reach full forward tilt. This is the highest-uncertainty element of the Avatar design in real flight.

**KFF_RDDRMIX — aileron-rudder coupling on rear motors**
In plane mode, `k_rudder` is computed as: turn coordinator + `KFF_RDDRMIX * k_aileron` + pilot rudder stick. All three terms flow into the rear motor yaw differential (scaled by `cos_tilt_b`). This means rolling the aircraft also drives differential rear motor thrust via the aileron-rudder mix. At cruise (tilt near horizontal) this is already zeroed out by `cos_tilt_b ≈ 0`. At hover-like tilt (near vertical) it is active. If this coupling proves undesirable in flight — e.g. roll inputs causing unwanted heading changes in slow flight — set `KFF_RDDRMIX = 0` in the Avatar param file. This removes the aileron→yaw coupling from the rear motors while leaving the turn coordinator and pilot rudder stick paths untouched.

**Yaw PID gain tuning — oscillation, needs D term**
Current flight-tested values (criss-cross thrust geometry, June 2026): `Q_A_ANG_YAW_P=2.0`, `Q_A_RAT_YAW_P=0.03`, `Q_A_RAT_YAW_I=0.01`, `Q_A_RAT_YAW_FF=0.5`, `Q_A_RAT_YAW_D=0`.

There is still residual oscillation from the differential rear motor thrust. `Q_A_RAT_YAW_D` is currently zero and is the next lever to try — add D in small increments (start at 0.001) to damp the oscillation without reintroducing instability. Do not increase P or ANG_YAW_P until D is explored; the oscillation is likely underdamped rather than undergained.

Note: when the yaw mechanism is rebuilt with outward-pushing geometry (replacing current criss-cross), swap the `+`/`-` yaw_delta assignment back in `AvatarMixer::mix()` and re-tune from scratch — the gains will not transfer.

**Param hygiene / restore golden params from aircraft**
Current parameter files include bench-testing values. Before first flight: audit `Q_A_RAT_*` gains, `SERVO_BLH_*` DShot masks, and arming check flags.

`ARMING_CHECK` is currently set to `0` on the aircraft (disabled for indoor bench testing without GPS). It must be restored to `50` before any flight. Do **not** rely on the param files for this — pull a fresh dump from the aircraft once bench testing is done and commit it as the new golden config:
```bash
python3 tools/mavlink/param_dump.py --elrs -v -o params/avatar_t1ranger_micoair.param
```

**Custom runtime parameters** *(CustomParameters.md)*
Several tuning constants in `CustomConfig` and `TVC_Core.cpp` require a recompile to change. Plan to migrate them to a proper `AP_CustomParams` subgroup in `ParametersG2`, making them adjustable from any GCS. Full implementation plan, param names, defaults, and call-site migration guide are in `CustomParameters.md`.

Priority params to unentangle from standard ArduPilot params:
- `AV_TILT_SPD` — replaces `Q_TILT_RATE_UP` for copter-mode servo tracking (dependent variable, calibrated)
- `AV_TRANS_RATE` — replaces `Q_TILT_RATE_DN` for plane-mode tilt-down slew (independent design choice, currently 30 °/s)

---

## Blimp — Needs Aircraft / Helium

**Plane mode flight test**
Blimp plane mode has been bench-validated through logic review only. The split-range "vectoring as virtual elevator" architecture (`elevator_tilt_split`, `handoff_point = 0.5`) has never been flight-tested. Helium cost makes iteration expensive — Avatar flight validation provides indirect confidence in shared subsystems (TVC brain, TECS mods, elevator-tilt split function).

**`elevator_tilt_handoff_point` tuning**
Currently `0.5f` in `blimpConfig`. This sets where elevator authority ends and motor tilt begins. The correct value depends on the actual elevator authority at cruise speed and needs to be tuned in flight.

**`surface_speed_scaler` ceiling**
At near-zero airspeed the `surface_speed_scaler` grows without bound, amplifying control surface commands to dangerous levels. A cap of `BLIMP_MAX_SPEED_SCALER ≈ 4.0x` is needed in `ArduPlane/Attitude.cpp` (near the `surface_speed_scaler` computation). Not yet implemented — low risk on the bench since surfaces have limited authority at zero speed, but must be addressed before autonomous plane-mode flight.

**Navigation yaw**
Current approach (phantom bank via `KFF_RDDRMIX = 1.0`) is a workaround. The proper solution is to override `calc_nav_yaw_coordinated()` in `ArduPlane/Attitude.cpp` to compute yaw rate from lateral acceleration directly, bypassing the bank angle check. The workaround is sufficient for initial testing.

**`PTCH_RATE_I` hover equilibrium value**
The pitch I-term must wind up to hold the nose level against the nose-heavy CG. Starting value unknown — needs in-flight tuning from the conservative starting point in `Blimp_Design.md § 6`.

---

## SITL

**Stable hover in Gazebo not yet achieved** *(SITL_Guide.md — Current Status)*
The Gazebo SITL infrastructure is complete but the aircraft flips shortly after throttle-up. Suspected causes and next steps are documented in `SITL_Guide.md`. Priority order:
1. Measure or estimate real Iyy/Ixx more accurately (bifilar pendulum or CAD export)
2. Try `Q_A_RAT_PIT_D = 0` and `Q_A_RAT_RLL_D = 0` as SITL-specific param overrides
3. Validate in QSTABILIZE before attempting FBWA

---

## Code Cleanup

**VTOL blending dead code in `TVC_Core.cpp`** *(lines 267–286, `#if VTOL_MODE == true` block)*
This block blends the TVC hover output with a full-forward command based on `transition_progress`. It is never exercised: both `BlimpMixer` and `AvatarMixer` only call `tvc_run_main_logic` in copter mode, where `transition_progress` is always `0.0`. A comment marks the block. Consider removing if a gradual mid-transition TVC path is never implemented.

**`AVATAR_DEBUG_LOG = 1` in `AP_Motors6DOF_AvatarMixer.cpp`**
Logs to GCS every 1–3 seconds. Disable before production flights to reduce MAVLink bandwidth. Set `#define AVATAR_DEBUG_LOG 0`.

**Shared `tvc_config` gain schedule**
Both `BlimpMixer` and `AvatarMixer` call `tvc_run_main_logic` with the same `tvc_config` instance defined in `TVC_Core.cpp`. If the two aircraft require different PID tuning, a per-aircraft `TVC_Config` branch will need to be added to the mixer dispatch. Not currently a problem — both aircraft are tuned with the same gains — but worth noting if tuning diverges.

**`avatarConfig.reverse_flight_physical_angle_deg = 0.0f`**
Currently relies on a `std::max(..., 0.1f)` guard in `TVC_Core.cpp` to avoid division by zero. Should be set to the real backward physical limit once the servo range extension (above) is calibrated.
