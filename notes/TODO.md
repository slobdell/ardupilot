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

**Plane mode stall-prevention validation**
The stall-prevention loop (elevator saturates → wings tilt upward via TVC pitch compensation) is theoretically sound and bench-verified, but the transition boundary behavior is untested. This is the highest-uncertainty element of the Avatar design.

**Param hygiene**
Current parameter files include bench-testing values. Before first flight: audit `Q_A_RAT_*` gains, `SERVO_BLH_*` DShot masks, and arming check flags. Ensure `ARMING_CHECK` is not globally disabled.

**Custom runtime parameters** *(CustomParameters.md)*
Several tuning constants in `CustomConfig` and `TVC_Core.cpp` require a recompile to change. Plan to migrate them to a proper `AP_CustomParams` subgroup in `ParametersG2`, making them adjustable from any GCS. Full implementation plan, param names, defaults, and call-site migration guide are in `CustomParameters.md`. Do this before first flight so TVC gains can be tuned without reflashing.

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
