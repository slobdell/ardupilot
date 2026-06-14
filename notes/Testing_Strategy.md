# Motor Mixer Unit Testing Strategy

## Why

The Avatar flew in QSTABILIZE on 2026-06-13. That flight validated the current `AvatarMixer` behavior as correct. The unit tests in `tests/mixer_test/` document that behavior as executable specifications so:

- A new contributor can ask "does rolling right in QSTABILIZE deflect ailerons?" and get an authoritative yes-or-no from the test suite rather than reading source code.
- Future mixer changes automatically regress against every validated behavior.
- An LLM agent can answer questions like "does pitch compensation work past 90 degrees?" by running the tests, not guessing.

Tests are written at the behavior level (what a pilot observes or what the physics demands), not at the implementation level. This keeps them stable across refactors.

---

## Architecture: How Tests Compile Without ArduPilot

Production mixer files (`AP_Motors6DOF_AvatarMixer.cpp`, `AP_Motors6DOF_BlimpMixer.cpp`, and friends) normally depend on the full ArduPilot library chain: `AP_Math`, `AP_Motors_Class`, `SRV_Channel`, `AP_AHRS`, `GCS_MAVLink`.

The test build compiles these files directly with plain `g++` using two flags:

| Flag | Effect |
|------|--------|
| `MIXER_STANDALONE_BUILD` | In `AP_Motors6DOF_Mixer.h`, replaces ArduPilot headers with a minimal inline stub: `Vector3f`, `constrain_float`, `radians`, `degrees`, `AP_Motors::SpoolState`, `AP_MOTORS_MAX_NUM_MOTORS`. |
| `TVC_STANDALONE_BUILD` | Same pattern for `TVC_Core.h` (already existed before the mixer tests). |

Both flags use `#ifdef` / `#ifndef` guards that are **never defined in any `waf` board build**. In production, the preprocessor sees exactly the same source as before these guards were added — they are invisible at the ArduPilot build system level.

### Production Safety Guarantee

`git diff HEAD -- libraries/` shows every uncommitted change to library source. The changes are:

1. `AP_Motors6DOF_Mixer.h` — Added an `#ifdef MIXER_STANDALONE_BUILD` block before the existing `#else` branch that still includes `AP_Motors_Class.h` and `AP_Math/AP_Math.h`. In production (flag absent) the preprocessor takes the `#else` — identical to before.

2. `AP_Motors6DOF_AvatarMixer.cpp` — Three additions:
   - `#ifndef MIXER_STANDALONE_BUILD` guard around `#include "AP_Motors6DOF.h"` — in production this evaluates true, include fires as before.
   - `#ifndef AVATAR_DEBUG_LOG` guard around `#define AVATAR_DEBUG_LOG 1` — if the build system never defines it (production default), the define still fires and the value is still 1.
   - `#ifndef MIXER_STANDALONE_BUILD` guard around `setup_motors()` body — in production the body is fully included and runs identically.

3. `AP_Motors6DOF_BlimpMixer.cpp` — Same pattern. The `quadplane.h` guard changed from `#if ENABLE_TRICOPTER_VTOL_BACKEND` to `#if ENABLE_TRICOPTER_VTOL_BACKEND && !defined(MIXER_STANDALONE_BUILD)` — in production `MIXER_STANDALONE_BUILD` is not defined so `!defined(...)` is true and the condition is equivalent to the original.

**Net effect on production: zero.** Every production code path is identical to before.

---

## Running Tests

```bash
cd tests/mixer_test
make run
```

Expected output: `=== Results: N checks, 0 failed ===`

To rebuild from scratch: `make clean && make run`

The build compiles production `.cpp` files directly from `libraries/` — there are no copies, no stubs that could drift from the real implementation.

---

## What Is Tested

### Avatar Mixer — Copter Mode (QSTABILIZE)

**Layer 3 — Core hover behavior**
- Neutral throttle at hover gives equal motor thrust across all wing motors
- Positive roll demand tilts the left motor higher than the right
- Roll effectiveness reaches zero at 90° tilt (wings horizontal, no differential authority)
- Disarmed spool state clears tilt angle immediately and returns zero thrust

**Group A — Pitch compensation / stall prevention**
The TVC brain adds aircraft pitch attitude to the servo pitch target so thrust stays world-vertical regardless of aircraft orientation. At 30° nose-up the wings tilt 30° from vertical; at 50° they sit at 40° from horizontal; at 80° they are nearly vertical again. Past 90° the servo saturates and `pitch_saturated` flag is set.

**Group B — Pitch compensation + forward stick**
With a 30° nose-up attitude AND forward stick, the commanded angles add. With a 30° nose-up attitude AND nose-down stick, they partially cancel.

**Group C — Rear motor math**
`rear = (throttle − pitch) × cos(tilt_deg)`. Rear motor equals throttle-minus-pitch at hover; it fades with cos at 45°; it surges on pitch-down demand and drops on pitch-up; it clamps to zero when pitch demand exceeds throttle.

**Group D — Roll headroom**
Roll authority is bounded by `min(1 − base, base)` so motors never saturate. At half throttle full roll fits within the margin; at full throttle roll headroom collapses to zero and roll is clipped. A pitch correction that shifts base_thrust also narrows the available roll window symmetrically.

**Group F — Disarmed / failsafe**
Spool-down immediately resets tilt to zero regardless of stick input.

**Group G — Elevator trim**
`elevator_out = −cos(tilt_deg)` (passive feedforward). At 45° tilt the output equals `−cos(45°)` = −0.707.

**Group H — QSTABILIZE surface controls**
In QSTABILIZE, pilot stick commands two independent paths:

| Input | Path | Output |
|-------|------|--------|
| `surface_roll` | Direct pass-through | `aileron_out = −surface_roll` (sign inverted) |
| `surface_yaw` | Direct pass-through | `rudder_out = +surface_yaw` |
| `inputs.roll` (PID) | Motor differential | `motor_thrust[0] > motor_thrust[1]` |
| `inputs.yaw` (PID) | Not used in Avatar | No effect on any output |

Tests verify: aileron sign is correct (rolling right → port aileron up = negative output); full stick saturates; PID roll drives motor differential but not ailerons; PID yaw drives nothing (the closed-loop yaw integrator is intentionally ignored — yaw authority in hover is purely from pilot rudder surface); roll and yaw surfaces are independent.

**Group I — Aircraft pitch state → motor hierarchy**
From the pilot's perspective:
- Nose-up aircraft → attitude controller outputs `inputs.pitch < 0` → rear motor exceeds front motors (0.8 vs 0.2 at ±0.3 pitch demand)
- Nose-down aircraft → `inputs.pitch > 0` → front motors exceed rear (0.8 vs 0.2)

### Avatar Mixer — Plane Mode

**Layer 2 — Fixed-wing surface pass-through**
- Neutral tilt demand gives wings horizontal (tilt_angle = 1.0)
- Full pitch-up tilts wings to vertical (tilt_angle = 0.0); past vertical is clamped
- Elevator follows pitch PID output directly
- Rudder follows pilot yaw
- Throttle drives both wing motors equally; rear motor fades with cos_tilt

**Group E — Plane mode rear motor under pitch pressure**
When elevator saturates on nose-up demand in plane mode, the rear motor surges to contribute pitch authority. At full forward tilt (wings horizontal) the rear motor is zero regardless of pitch demand.

### BlimpMixer — Plane Mode (Layer 4)

With `forward_flight_physical_angle_deg = 90°`, val_neutral = 90/90 = 1.0. Neutral stick gives full forward tilt; full pitch-up tilts to reverse and saturates elevator; full pitch-down tilts to forward neutral; throttle drives both lift motors equally; rudder follows pilot yaw.

### BlimpMixer — Manual Override (Layer 5)

RC channel 2 (index 1) drives lift motors via dumb pass-through. RC channel 3 (index 2) drives the yaw motor and rudder. Only active when `emergency_blimp_manual_mode = true` in config AND `manual_override_pwm > 1200` — the avatarConfig has this disabled so the test verifies graceful fallback.

### Shared Utility — elevator_tilt_split() (Layer 1)

The handoff function that splits pitch input into elevator authority and tilt demand once elevator saturates. Tested at neutral, below threshold (elevator only), at threshold (elevator saturates, tilt still zero), above threshold (tilt ramps, elevator holds saturated), full positive (both saturate), and negative input (sign-symmetric).

---

## What Is NOT Tested (and Why)

| Excluded | Reason |
|----------|--------|
| PID gains and tuning | External to mixer. ArduPilot attitude controller produces `inputs.roll/pitch/yaw` — mixer is agnostic to how they were computed. |
| TVC_Core (pitch compensation math) | Already has its own test suite in `tests/tvc_core_test/`. |
| V-tail mixing (elevon left/right = elev ± rud) | Lives downstream in `AP_Motors6DOF::output_to_motors()`, not in the mixer. |
| Blimp copter mode TVC | TVC is tested in `tests/tvc_core_test/`. BlimpMixer copter-mode wiring is thin boilerplate over TVC. |
| Hardware servo output ranges | Physical calibration, not logic. |

---

## Adding New Tests

1. Write a `void my_test_name()` function. Use descriptive names that read as sentences.
2. Call `begin_test(__func__)` at the top and `end_test()` at the bottom.
3. Use `CHECK_NEAR(expected, actual, tolerance)`, `CHECK_TRUE(condition)`, or `CHECK_FALSE(condition)` for assertions.
4. Add a call to `main()` under the appropriate group header.
5. Run `make run` — new tests should appear and pass.

When a test documents behavior validated on a real aircraft, note this explicitly in a comment so future agents know the expected value is not guessed.
