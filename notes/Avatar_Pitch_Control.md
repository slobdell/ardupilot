# Avatar Plane-Mode Pitch Control

How the Avatar stabilises pitch in plane modes (STABILIZE, CRUISE, AUTO). This is the
conceptual companion to the terse invariant specs in `Avatar_Design.md § 9`
(`[AV-INVAR:plane-pitch-couple]`, `[AV-INVAR:pitch-before-throttle]`,
`[AV-INVAR:rear-earth-frame-fade]`) — it records the mental models and *why the design is
what it is*, including the alternatives that were considered and rejected.

The Avatar keeps a **level fuselage at all times**; "pitching" the aircraft is done by tilting
the wings, and the pitch loop's job is to hold the fuselage level against disturbances. All motor
mixing below happens *after* the servo tilt angle is finalised by the pilot and the dampeners —
the pitch loop never moves the servo.

---

## 1. Pitch is a thrust couple, not a servo motion

Each wing motor has two degrees of freedom: the **servo** sets its angle (shared across both
wings, rate-limited, slow) and the **ESC** sets its thrust magnitude (per-motor, fast). A pitch
moment requires a *front-vs-rear differential*, which a single shared servo physically cannot
produce — and a symmetric re-vector of both wings produces no pitch moment at all. So pitch is an
**ESC differential at whatever tilt angle the servo currently holds**:

```
front (wing) pair:  + inputs.pitch  (nose-up demand raises the front)
rear pair:          − inputs.pitch  (and lowers the rear)
```

Front-up + rear-down (or the reverse) is a **couple** — a pure moment. Because the two halves move
in opposite directions, total lift is roughly preserved, so the aircraft pitches *without* the
altitude excursion a one-sided actuator would force.

The servo stays locked for pitch, but the **dampeners still move it** — they are collective and
slow (altitude/velocity trim), which is the servo's proper job. Keeping the fast pitch loop on the
ESCs and the slow trim on the servo is the whole point.

**Why this matters:** the earlier plane design gave pitch a *single* actuator — the rear pair,
`(throttle − pitch)·cos_tilt`, which pushes the nose down by *adding* thrust. Near hover at high
throttle the rear sits near its 1.0 rail with no room to add, so a nose-up disturbance exhausted
the only nose-down actuator and the aircraft departed (STABILIZE flight test). The front pair
supplies the missing half of the couple using its own magnitude range. Copter mode never had this
failure because its mixer always ran the couple.

---

## 2. Think in vertical components

Decompose each motor's thrust at tilt `θ` (measured from vertical): vertical `V = T·cosθ`, forward
`F = T·sinθ`. **Pitch is produced by the differential of the *vertical* components** — the forward
component is a side effect.

You control the **magnitude** `T` (the ESC command) at a fixed servo angle, not `V` directly.
Changing `T` moves `V` and `F` together in lockstep (their ratio, i.e. the tilt, is unchanged).
You cannot change `V` in isolation without re-tilting the servo — which we refuse to do for pitch.

This settles how the pitch term enters the command — **add, don't multiply, and never divide:**

- **Add** `inputs.pitch` to the command → `ΔV = inputs.pitch·cosθ`. The pitch authority depends
  only on tilt, *not* on throttle. This is what we do.
- **Multiply** the command by a factor → authority scales with the current throttle `T`, giving a
  throttle-dependent plant gain. Worse for the PID.
- **Divide** by `cosθ` (to force a *constant* vertical authority `ΔV = inputs.pitch`) → blows up at
  horizontal (`cosθ → 0`). And constant authority is not even wanted: pitch authority *should* fade
  as the wings go horizontal, handing off to the elevator.

"Take the vertical component, add pitch, then rescale the whole vector to keep the angle" is
algebraically identical to `T + pitch/cosθ` — the divide — so it carries the same singularity.

---

## 3. The front term is gated by cos_tilt (Option A)

The front pitch term is `inputs.pitch · cos_tilt_b`, where `cos_tilt_b = fmaxf(0, cos(tilt))` — the
same guard the rear already uses. The gate is **mandatory**, not cosmetic:

A wing motor's vertical component is `T·cosθ`, which is zero at horizontal (90°) and **negative past
it** — the servo travels to 95° on full pitch-down (past-horizontal descent). An *ungated* front
term (`throttle + inputs.pitch`) would add pure forward thrust at 90° (an airspeed kick, no pitch)
and **invert past 90°**: adding thrust to a forward-and-down-pointing motor pitches the nose the
*wrong* way — positive feedback. Gating fades the front pitch contribution smoothly to zero by
horizontal and holds it at zero past it.

**Accepted cost — a slightly unbalanced couple.** With the gate, the front's vertical pitch
authority is `pitch·cos²θ` while the rear's is `pitch·cosθ`. So a pitch demand leaks up to
~`0.25·pitch` of net vertical force into altitude in mid-transition (peaks ~60°, absorbed by the
sink dampener). This is negligible near hover (`cos² ≈ cos`), which is the regime that matters most.
The whole couple's plant gain is `pitch·cosθ·(1+cosθ)` — a smooth, monotonic, never-negative fade
from 2 (both actuators, hover) to 0 (cruise), matched to the copter I-term handoff.

**Alternatives rejected:**
- *Unscaled front* (`+inputs.pitch`) — gives a perfectly balanced couple, but only below horizontal;
  it inverts past 90°.
- *Divide-by-cos* (constant vertical authority) — balanced *and* uniform, but singular at horizontal.
- *Smoothstep gate* — preserves balance in the operational band and is safe, but adds a knee
  parameter. Not worth the tuning surface for a gain that fades into the elevator anyway.

The forward-component side effect (`pitch·cosθ·sinθ = pitch·½sin2θ`) is bounded, zero at both hover
and horizontal, and fades at cruise for free as a bonus of the gate.

---

## 4. Headroom has three distinct levers — don't conflate them

"Headroom for pitch" comes from three separate places, and only two are used:

1. **Motor magnitude range** — the couple pushes one pair up and the other down within `[0,1]`. This
   is the primary source of authority; it is what lets a nose-down couple work even when the rear is
   railed (the front still has downward room). The forward-thrust wiggle is a *by-product* of using
   this range, not the source of the headroom.
2. **Throttle / vertical lift** — the cross-pair transfer (`[AV-INVAR:pitch-before-throttle]`) spends
   this: when one pair rails, the undeliverable pitch is pulled from the *other* pair's common mode.
   It spends **lift**, not forward thrust. Lift is recoverable; a pitch departure is not.
3. **Forward thrust, traded for vertical by re-vectoring** — the only lever that literally sacrifices
   forward thrust, but it works by *moving the tilt servo*. That is the sink dampener's mechanism, for
   *altitude*. It is deliberately **not** used for pitch (it moves the pilot-owned servo and a
   symmetric re-vector makes no moment).

Allocation priority is **pitch > roll/yaw > throttle**: keep the aircraft attitude-controllable
first, spend lift/heading to get there, and only then honour the throttle/forward demand.

---

## 5. The rear fade is scheduling — so it uses the earth frame

The rear motor is bolted to the fuselage; its **physical** pitch moment is constant (`thrust × arm`),
independent of wing tilt or attitude. So — unlike the front couple and the roll differential, whose
`cos_tilt` is a genuine *body-frame moment projection* — the rear's `cos_tilt` is a **scheduling
fade** that turns the hover actuator off "in forward flight."

"Are we in forward flight?" is an **earth-frame** question. Body-frame wing tilt mis-reads it when
the fuselage is pitched: nose-high with the wings at mid-tilt is a *hover-like* state (the thrust
vector still points near earth-vertical), yet `cos(body_tilt)` would throttle the rear right when it
is needed. Offsetting the servo angle by the AHRS pitch converts body → earth frame:
`earth_angle = tilt − aircraft_pitch`.

But `cos` is **even**, so `cos(tilt − pitch)` alone cannot tell "wings tilted forward of vertical"
from "behind vertical" — it would wrongly fade a wings-vertical hover knocked nose-up by a gust
(`tilt=0, pitch=+45° → cos(−45°)=0.71`), exactly when that hover needs *maximum* rear authority. So
the schedule takes the **more hover-like of the two frames**:

```
cos_tilt_rear = max( cos_tilt_b, fmaxf(0, cos(tilt − aircraft_pitch)) )
```

`max(body, earth) ≥ body`, so this can only ever **add** rear authority in a disturbed attitude,
never remove it; it fades to zero only when *both* frames are horizontal (genuine level forward
flight). Nose-down needs no special case — the rear's nose-up correction reduces it toward 0 and the
front couple supplies the rest.

This body→earth conversion is the exact compensation the copter TVC brain already applies
(`target_pitch += current_pitch`), so it is flight-validated in QSTABILIZE/QLOITER. It is correct
for the Avatar specifically because the airframe **always commands a level fuselage** — a nonzero
AHRS pitch is by construction a disturbance, which is precisely when the rear should stay available.
(Scope: only the rear common mode uses the earth frame; the front couple, roll, cross-pair transfer,
and yaw stay body-frame.)

---

## 6. It all propagates to CRUISE and AUTO

The couple, the cross-pair transfer, and the earth-frame rear fade live in the **shared plane-branch
motor block**, so STABILIZE, CRUISE, and AUTO inherit them with no per-mode code. One interaction to
respect: in TECS modes the cross-pair transfer spends throttle that TECS manages, so its saturation
limit flags must reach TECS (not only the copter pitch PID) — otherwise a pitch-preserving throttle
cut would be fought by the TECS integrator instead of freezing it.
