# Response to Bug Report: Speed-Hold Tilt Jump & Throttle Step-Change Transients

## What was implemented

The angle latch — Concept #3 from the report — was implemented as a slew rather than a
single-frame snap, and without the additional machinery (freeze-target tracking, fade factor on
vel-damp, `_last_stick_active` state). The changes are:

**`libraries/AP_Motors/AP_Motors6DOF.h`** — added `set_pilot_tilt_deg(float deg)` setter.

**`ArduPlane/quadplane.h`** — added `bool _last_throttle_active`, `float _latch_tilt_start`,
`float _latch_tilt_target`.

**`ArduPlane/quadplane.cpp`** — in the vel-damp block, immediately before the existing
`any_stick_active` target-tracking guard: on the first frame of throttle activity with neutral
pitch, snapshot `_latch_tilt_start` (current `pilot_tilt_deg`) and `_latch_tilt_target`
(current `current_tilt_deg`). Every subsequent throttle-active frame, advance `pilot_tilt_deg`
toward `_latch_tilt_target` at `Q_TILT_RATE_UP × dt` degrees per frame via `set_pilot_tilt_deg`.
All other vel-damp logic (continuous target tracking, no fade factor, error cap) is unchanged.

The slew runs only while `throttle_active && !pitch_active` and stops (leaving `pilot_tilt_deg`
wherever it reached) when the pilot releases or applies pitch.

---

## Agreement with the report

**Bug A (tilt retraction) is real and the angle latch is the right fix.**

When the dampener holds the rotors at 15° to counter wind, `pilot_tilt_deg` is still 0° (the
pilot never moved their tilt stick). The moment any stick becomes active, the vel-damp correction
drops to zero via continuous target tracking (`_vel_hold_target = vel_bf.x` → error = 0).
`tilt_target_deg` then becomes `atan2(T×sin(0°), T×cos(0°)) = 0°`. The servo starts slewing
back at `Q_TILT_RATE_UP`. This is the retraction.

The conceptual argument is correct: from the pilot's perspective, the system derived 15° as the
correct operating angle. Touching the throttle should apply more force in the 15° direction — not
silently revert to a different angle. The angle latch makes `pilot_tilt_deg = current_tilt_deg`
at the instant of throttle contact, so the target stays at 15° even with the dampener zeroed.

**Bug B (vertical sag) is also real, but for a different reason than stated.**

The report frames the sag as the mixer's throttle boost dropping while the rotors are still
tilted. The force-vector decomposition math actually preserves vertical lift regardless of how
`damp_horiz_thrust` changes — `new_throttle × cos(new_tilt) = thrust_vert` exactly, and
`thrust_vert` does not contain `damp_horiz_thrust`.

The sag is real, but it comes from the servo slew lag combined with a reduced throttle command.
Before stick engagement, total throttle magnitude = `T/cos(15°)` (boosted). After stick
engagement (no latch), throttle = `T`, tilt command = `0°` but servo still physically at 15°.
Actual vertical lift = `T × cos(15°) ≈ 0.966T` during the slew — a ~3.4% sag that recovers
as the servo returns to vertical.

The slew eliminates both the servo retraction and the decomposition-basis step change. As
`pilot_tilt_deg` rises from 0° toward 15° over ~170ms, the atan2 decomposition sees
`(T×sin(pilot_tilt) + damp_horiz_fading)` remaining approximately constant — the servo barely
moves. `thrust_vert` transitions from `T×cos(0°)` to `T×cos(15°)` gradually rather than
stepping, and the lag-induced sag never occurs because the servo never retracts.

---

## Disagreement with the proposed implementation

Three elements of the proposed solution were rejected:

### 1. Freezing `_vel_hold_target` during stick activity (only-at-release snapshot)

The current continuous tracking (`_vel_hold_target = vel_bf.x` every frame while stick is
active) is load-bearing. It ensures the dampener never fights intentional speed changes: when the
pilot adjusts throttle and the aircraft accelerates, the hold target tracks that new speed so the
error stays at zero throughout. The proposed change freezes the target when the stick goes active,
meaning the dampener generates a growing error (up to the 1.5 m/s cap) during the entire
stick-active period, suppressed only by the fade factor. This is the wrong direction — the
dampener is fighting the pilot's commanded speed change during the 100 ms fade window.

With the angle latch in place, continuous tracking still achieves zero output during stick
activity (error = 0 → correction = 0), and the latch handles the tilt retraction independently.
The two mechanisms are orthogonal; there is no need to change the tracking semantics.

### 2. Applying `_damp_long_fade_factor` to vel-damp output

The report adds `* _damp_long_fade_factor` to `avatar_vel_damp_thrust`. With the angle latch and
continuous tracking, the vel-damp output is already zero during stick activity (because the error
is zero). The fade factor adds no benefit and introduces an asymmetry: vel-damp re-engages
instantly on stick release (error jumps from 0 to the held-speed error), while the fade is still
recovering over 500 ms — meaning the fade would SUPPRESS re-engagement for up to 500 ms after
the pilot releases. That is the opposite of what we want.

### 3. Complexity cost vs. benefit

The full proposal adds two new state variables (`_last_throttle_active`, `_last_stick_active`),
changes the target-tracking semantics, adds a fade path to vel-damp, and changes the release
snapshot to a single-frame edge trigger. The implemented slew latch adds three new state
variables (`_last_throttle_active`, `_latch_tilt_start`, `_latch_tilt_target`) and a small
per-frame slew block, leaving all other invariants intact. The vel-damp target-tracking semantics
and the error-cap guard are untouched.

---

## Edge case: simultaneous pitch + throttle input

The latch fires when `throttle_active && !pitch_active_vd`. When both sticks are active, the
latch does not fire and the retraction still occurs.

This is correct behaviour. In STABILIZE rate-control mode, the pitch stick directly commands
`pilot_tilt_deg`. If the pilot is moving the pitch stick, they own the tilt servo — the latch
staying off is the right call because the pilot is actively overriding the dampener's corrective
angle with deliberate intent. No protection is needed when the pilot is already in control of the
thing that would otherwise need protecting.
