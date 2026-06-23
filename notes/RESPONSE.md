# Response to Bug Report: Speed-Hold Tilt Jump & Throttle Step-Change Transients

## What was implemented (revised after review)

The full proposal from the report was implemented. An earlier revision used a slew rather than
an instant snap and was found to be incorrect (see "Correction" section below). Final changes:

**`libraries/AP_Motors/AP_Motors6DOF.h`** — added `set_pilot_tilt_deg(float deg)` setter.

**`ArduPlane/quadplane.h`** — added `bool _last_throttle_active`, `bool _last_stick_active`.

**`ArduPlane/quadplane.cpp`** — three coordinated changes in the vel-damp block:
1. **Instant snap latch**: on the first frame of throttle-only activity, `pilot_tilt_deg` is
   snapped (not slewed) to `current_tilt_deg`.
2. **Target freeze + release snapshot**: hold target is frozen during stick activity; snapshotted
   at the exact frame of release (with saturation guard).
3. **Fade factor on vel-damp**: `avatar_vel_damp_thrust *= _damp_long_fade_factor`.
   An else-branch on the outer condition resets both flags when not in STABILIZE/flying.

## Correction: why the slew failed

The first implementation slewed `pilot_tilt_deg` from 0° toward 15° at `Q_TILT_RATE_UP` per
frame instead of snapping. The mixer sets `tilt_target_deg = pilot_tilt_deg` when
`damp_horiz = 0` (the force block is bypassed when `fabsf(damp_horiz) < 1e-4`). With
continuous target tracking, `damp_horiz` drops to 0 on frame 1. So `tilt_target_deg` equals
the slowly-slewing `pilot_tilt_deg` (≈ 0.1° on frame 1), and `current_tilt_deg` chases it
downward at the same rate — converging at the midpoint (7.5° for a 15° correction) before
recovering. The retraction lurch was not prevented, only halved in magnitude.

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

## Revised position: agreement with the full proposal

After the other agent's review identified the failure of the slew approach, the three previously
rejected elements were reconsidered and found to be correct:

**Freeze + fade are co-dependent, not independent.** The freeze is necessary to give the fade
something to act on: with continuous tracking, `vel_error = 0` always during stick activity, so
multiplying by the fade factor produces zero regardless. The freeze lets the error grow (as the
aircraft begins to drift) so the decaying fade can smoothly wash out the correction over 100 ms.

**Re-engagement is gradual, not suppressed.** The 500 ms fade recovery after stick release means
the dampener re-engages gradually rather than instantly. The release snapshot ensures `vel_error`
starts at 0, so the dampener builds from zero — no grab lurch. This is better behaviour than the
previous instant re-engagement.

**The "dampener fights pilot" concern was overstated.** During the 100 ms fade window the error
grows only if the aircraft drifts (wind pushing it). The corrective force is diminishing and
capped at ±1.5 m/s error. The duration is 100 ms maximum. This is an acceptable trade-off.

---

## Edge case: simultaneous pitch + throttle input

The latch fires when `throttle_active && !pitch_active_vd`. When both sticks are active, the
latch does not fire and the retraction still occurs.

This is correct behaviour. In STABILIZE rate-control mode, the pitch stick directly commands
`pilot_tilt_deg`. If the pilot is moving the pitch stick, they own the tilt servo — the latch
staying off is the right call because the pilot is actively overriding the dampener's corrective
angle with deliberate intent. No protection is needed when the pilot is already in control of the
thing that would otherwise need protecting.
