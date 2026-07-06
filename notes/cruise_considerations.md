# CRUISE Considerations — Avatar Flight Mode Manual (and the path to AUTO)

**Updated:** 2026-07-05
**Flight-validated:** QSTABILIZE, QLOITER, STABILIZE. **CRUISE: not yet flown.**
**Code status:** all fixes below implemented; mixer unit tests 198/198; firmware build passing (verified 2026-07-05). **Nothing new is flight-verified** — see § 9.
**Verified against:** `quadplane.cpp`, `mode_cruise.cpp`, `navigation.cpp`, `Attitude.cpp`, `AP_TECS.cpp`, `AP_Motors6DOF_AvatarMixer.cpp`, `params/avatar_t1ranger_micoair.param`.

---

## 1. Mode decisions (settled)

| Mode | Role |
|---|---|
| STABILIZE | Manual workhorse: takeoff, landing, transition, headwind hover. Throttle = altitude, pitch = speed. |
| QLOITER | Autonomous station-keeping hover (position hold + active weathervane). |
| **CRUISE** | Autonomous-ish transit; validation gateway for AUTO. **The mode this doc is about.** |
| AUTO | Waypoint-only missions, after CRUISE validates. No NAV_TAKEOFF/NAV_LAND items until separately analyzed. |

- **FBWA: skip.** STABILIZE minus every value-add (no dampeners, no weathervane, tilt requires holding a stick fraction — neutral stick commands a cruise transition). Never runs TECS, so it gains nothing back. Pure regression.
- **FBWB: skip.** Strict subset of CRUISE — CRUISE with heading unlocked runs literally the FBWB code.

**AUTO inheritance:** AUTO uses the identical control stack as CRUISE — TECS for pitch/throttle, L1 for roll — plus a mission sequencer. Every fix in this doc lives in TECS, the mixer, or the quadplane non-STABILIZE branch, so all of it propagates to AUTO (and RTL/LOITER) automatically. Nothing lives in a `mode_*.cpp` file.

---

## 2. How CRUISE flies the Avatar

- **Pitch stick** moves a target *altitude* (±`FBWB_CLIMB_RATE` = 2 m/s); release = lock current altitude. TECS turns altitude error into `nav_pitch_cd`, which drives **tilt angle** (position mode, slewed 225°/s toward vertical / 30°/s toward horizontal).
- **The stick does NOT set tilt directly.** Full stick = "climb at 2 m/s"; TECS picks the tilt: **initial tilt-up ≈ `FBWB_CLIMB_RATE`/`AIRSPEED_CRUISE` rad = 2/3 ≈ 38°**, +~4°/m of accumulated altitude error, plus integrator (escalates to 90° in ~4–6 s if the climb isn't achieved). 90° is reachable (`TECS_PITCH_MAX = PTCH_LIM_MAX_DEG = 90`, keep both) but only via evidence of need — minimum tilt that climbs = the efficient point. Stick-feel knob = the ratio (`FBWB_CLIMB_RATE`=5 ⇒ full stick ≈ immediate vertical). Full chain: Avatar_Design.md § 4.4.4.
- **Throttle follows tilt automatically** since `[AV-INVAR:tecs-synth-pitch]` (§ 3): ~45% at horizontal, ~72% at 45° tilt, → `THR_MAX` at vertical (HPF term immediate, LPF term sustains, τ ≈ 5 s).
- **The height loop closes on EKF/baro height rate — never on actual fuselage pitch.** Signs match Avatar physics (tilt-up ⇒ climb + decelerate). No airspeed sensor ⇒ `SKE_weighting = 0` ⇒ pitch demand is pure height control.
- **Roll stick** = bank command. Sticks centered ≥ 0.5 s at ≥ 3 m/s ground speed → **heading lock**: L1 holds the captured GPS ground track (built-in, nothing to enable). Any roll/rudder input unlocks instantly; below 3 m/s the lock never engages.
- **Throttle stick**: TECS owns the throttle servo; the stick is a positive-only bias. Upper half = `THROTTLE_NUDGE` (up to +55%); lower half = deliberately nothing (stock convention: idle stick must never starve the autopilot). Descent = pitch stick forward. **Pilot briefing: semantics invert vs STABILIZE** (STABILIZE: throttle=altitude, pitch=speed; CRUISE: pitch=altitude, throttle=bias-up only). Permanent — no airspeed sensor, § 5.7.
- **Yaw = STABILIZE yaw** since 2026-07-05 (`[AV-INVAR:stabilize-yaw-pid]` extended to all nav plane modes): copter yaw rate PID on rudder + rear-motor differential, pilot-stick target, weathervane I-reset when stick centered (which also keeps the PID P/D-only in hands-off banked turns, bounding any coordinated-turn fighting — the same behavior already flight-validated in STABILIZE forward flight). Manual-family modes keep raw rudder. Contingency if CRUISE logs show skidding turns degrading L1: add a coordinated-turn feedforward (g·tan(roll)/ground_speed) to the yaw rate target — do not revert to open loop.
- **Elevator + rear motor** hold the fuselage level via the copter attitude PID in all plane modes — same as STABILIZE.
- **The STABILIZE dampeners (vel/sink/long) do not run in CRUISE.** TECS's height loop is the sink-damp substitute.

---

## 3. TECS throttle blindness — ✅ FIXED (`[AV-INVAR:tecs-synth-pitch]`; flight verification pending)

**The problem:** `_update_throttle_without_airspeed()` sets sustained throttle from **low-passed measured fuselage pitch**. Conventional plane: climb = nose-up = throttle. Avatar holds the fuselage level by design ⇒ signal permanently ~0 ⇒ throttle pinned at `TRIM_THROTTLE` (45%) no matter how vertical the rotors — while all stock backstops are inert (underspeed can't fire with `AIRSPEED_MIN=0`; badDescent needs 90% throttle demand). Failure: pull up → tilt rails at 90° seeking a climb → aircraft mushes down at 45%, and the plant is non-monotonic at fixed throttle so TECS digs deeper.

**The fix:** feed the law the **earth-frame thrust elevation = fuselage pitch + (90° − tilt_deg)** — the sum, not tilt alone, so real sustained nose excursions (stall-prevention nose-up) still raise throttle exactly as stock would. Avatar only; blimp keeps stock path (different tilt geometry, buoyancy makes the failure impossible).

| State | Real pitch | Synthetic pitch | Throttle |
|---|---|---|---|
| Rotors horizontal (cruise) | ~0° | 0° | 45% |
| Rotors 45° | ~0° | 45° | ~72% |
| Rotors vertical (max climb) | ~0° | 90° | 100% |
| Rotors 95° (descent) | ~0° | −5° | <45% |

**Verification remaining:** bench (tilt up on ground in a TECS mode → throttle demand rises) + climb-log evidence of throttle tracking tilt (`TECS.th` vs tilt demand).

---

## 4. CRUISE→STABILIZE tilt slam — ✅ FIXED (unit-tested; flight verification pending)

`pilot_tilt_deg` (STABILIZE rate-mode target) was synced to the physical tilt only by the copter branch — flying CRUISE at 90° then flipping to STABILIZE slewed the rotors toward a stale near-vertical target at `Q_TILT_RATE_UP` = 225°/s at cruise speed. **Fix:** the position branch now pins `pilot_tilt_deg = current_tilt_deg` every frame (mirror of the flight-validated copter-branch sync), and `_vel_hold_target` snapshots on STABILIZE entry so the vel-damp never acts on a stale hold speed. Unit test `position_mode_syncs_pilot_tilt_for_rate_mode_entry` proves 0.5 s at 225°/s holds position where it previously went fully vertical. The vel-hold snapshot is quadplane-side (not unit-testable): verify in the first CRUISE→STABILIZE log (`AVSD.VxHld` = `VxBf` at entry). Note the servo never *steps* in any switch — the hazard was the stale target + fast slew direction.

---

## 5. Known behaviors & hazards (accept or brief the pilot)

1. **Entering CRUISE from a hover starts a full transition** (TECS resets → tilt target horizontal at 30°/s). With the § 3 fix, throttle now enters *high* (synthetic pitch ≈ 90° at vertical rotors) and decays with tilt — expect a **mild initial climb** rather than the pre-fix sag; verify in logs. Still: **enter CRUISE from established forward flight** until the from-hover behavior is characterized.
2. **`FLTMODE5 = 0` (MANUAL) is a motor-cut switch** — MANUAL/ACRO/TRAINING force quad motor spool SHUT_DOWN instantly; no blend can help. Replace with CRUISE (mode 7), which also puts CRUISE on the radio. **Param change still pending.**
3. **Bank capped at 25° when slow** (`STALL_PREVENTION=1` + `AIRSPEED_MIN=0`, estimated airspeed < ~1 m/s). Harmless; explains "won't bank when slow."
4. **Extreme wind (≈ airspeed):** crab angle blows up, L1 demands big banks (capped per #3), upwind progress → 0 under any strategy. Operational, not code. With `AIRSPEED_MAX=10` and design winds 5–10 m/s, expect to fly near this edge — watch L1 bank demands.
5. **RC failsafe from CRUISE: CIRCLE (1.5 s) → RTL (5 s)** — stock machinery, since `avatarConfig.failsafe_kill_motors = false` (July 2026). Full policy, history, and ground-safety analysis: `notes/rc_failsafe.md`. (Failsafe-initiated mode changes pass through the § 6 blend — accepted behavior.)
6. **CRUISE cannot land vertically — by construction.** Full pitch-up is a climb command (tilt vertical + throttle up); the only descent is pitch-down, executed airplane-style (tilt flat/95°, forward speed). "90° tilt + low throttle + descending" is unreachable in CRUISE on purpose. **Every flight bookends in STABILIZE** — which § 4 exists to make safe.
7. **Airspeed sensor: DECIDED — never used for flight control.** `ARSPD_USE` stays 0; all analysis assumes no-airspeed TECS paths. A sensor may later exist as a separate abstraction strictly for scheduling wing angle relative to motor angle (Avatar_Design.md § 8.4) — it must not feed `ARSPD_USE`/TECS.

---

## 6. Mode-transition blend — ✅ IMPLEMENTED (`[AV-INVAR:mode-transition-blend]`; flight verification pending)

One mechanism covers every in-flight mode change (Q↔Q, plane↔Q, plane↔plane): the mixer edge-detects the flight-mode id, freezes the previous frame's commanded **trim thrust vector** (post-dampeners), and blends to the new mode's live command **in force space** over `Q_TRANSITION_MS` (= **1500** in golden config). Properties:

- **Stabilisation is never blended** — attitude PIDs run at full authority throughout; only the trim point transitions.
- **Anti-windup** via motor limit flags while the blend suppresses a demand (upstream Z-controller integrators freeze instead of winding).
- **No blending on the ground** — mode tracking resets unless spooled up in flight.
- **Supersedes the old 0.5 s throttle-only `copter_to_plane_blend`** (removed).
- **Tilt vs throttle split in plane modes:** the blend owns throttle magnitude; tilt is owned by the slew machinery (30°/s toward horizontal) and the § 4 sync. In copter entry the blend owns the servo command too (prevents the instant-vertical snap at STAB→QSTABILIZE).
- **Q→Q is a grace window, not a semantics fix:** ~1.5 s for the pilot's hand to re-center after the switch; afterward the stick means what the new mode says. Centering throttle at the switch remains procedure.
- `Q_TRANSITION_MS` repurposing is Avatar-safe (Avatar never runs the stock transition machine; blimp never executes AvatarMixer).

**Transition walkthroughs into CRUISE:**
- **QLOITER→CRUISE:** tilt slews vertical→horizontal at 30°/s (~3 s); throttle blends from hover trim toward TECS's demand, which starts near `THR_MAX` (synthetic pitch ≈ 90°) and decays to ~45% as tilt flattens. Emergent, physically-correct transition throttle profile; **expect a mild initial climb — verify in first logs.**
- **STABILIZE→CRUISE:** snapshot includes the dampeners' last contribution, so vel/sink-damp fade out through the blend instead of stepping off. Tilt slews from current to horizontal; `pilot_tilt_deg` stays pinned so flipping back mid-transition is safe. Stick semantics flip at t=0 (blend = hands-grace only).

**QSTABILIZE→QLOITER climb — not a bug, no code change.** Entry is jerk-free in code (Z accel-PID integrator inits to current−hover, output adds hover back — cancels exactly). The climb is *commanded*: QLOITER reads the throttle stick as climb rate about mid (`(stick−50%) × 2 × Q_PILOT_SPD_UP`), and on an underpowered airframe the hand is parked at hover (~70%) ⇒ ~+1 m/s. Sign test confirms (hover below mid would descend). Response: pilot procedure (center throttle at the switch); optionally lower `Q_PILOT_SPD_UP`; the thrust upgrade shrinks it naturally. Loose end (low priority): verify hover-learn converges in the 6DOF backend (`MOTB.ThO` in hover vs `Q_M_THST_HOVER`=0.35) — affects altitude-loop FF quality only.

---

## 7. Parameters that look wrong but aren't

- **`AIRSPEED_CRUISE` (= 3): never set to 0.** Not a speed target (airspeed demand is inert without a sensor) — it is the airspeed TECS *assumes* when converting climb demands to tilt (`γ ≈ v_z/AIRSPEED_CRUISE`), i.e. the pitch-loop gain denominator. Our backend patch removed the stock 3 m/s floor, so 0 ⇒ divide-by-zero ⇒ bang-bang tilt. Tuning knob: lower = twitchier, higher = gentler; keep ≥ 1. `[AV-INVAR:airspeed-cruise-gain]`.
- **`PTCH_LIM_MAX_DEG` = 90 is a REQUIREMENT, not happenstance** — it appears in three separate places, and 90 is the unique value that makes them mutually consistent, turning "TECS pitch demand in degrees" into a literal 1:1 identity with "thrust elevation in degrees":
  1. **Demand → tilt mapping** (`quadplane.cpp:2036`, mixer line 217): `pitch_tilt_demand = nav_pitch_cd / (PTCH_LIM_MAX×100)`, and the mixer maps demand 1.0 → rotors fully vertical. With the physical cruise angle at 90° from vertical, a demanded pitch of X° produces thrust elevation of exactly X°.
  2. **Feedback**: `[AV-INVAR:tecs-synth-pitch]` reports `90° − tilt` = thrust elevation back to TECS as measured pitch — so at steady state, measured equals demanded. The loop is dimensionally closed only because of (1).
  3. **Throttle-law denominator** (`AP_TECS.cpp:936`): `throttle = TRIM + (THR_MAX−TRIM) × pitch/PTCH_LIM_MAX`. With PTCH_LIM_MAX=90 and synth pitch spanning [0°, 90°], throttle reaches exactly THR_MAX at exactly full tilt-up — full vertical-thrust authority precisely when hanging on the rotors. TECS does **no trigonometry**; this linear ramp is only a monotonic feed-forward (the height-loop integrator trims out the error), but its endpoints must land where the physics needs them, and PTCH_LIM_MAX=90 is what pins the top endpoint to "vertical rotors = max thrust."
  Changing this value desynchronizes all three at once: e.g. 45 would command full vertical tilt at only 45° of TECS demand, break the measured=demanded identity, and saturate the throttle ramp at half the tilt range. **Do not change.** (`PTCH_LIM_MIN_DEG` = −25 has no such identity — descent is throttle-cut-dominated and the tilt-forward range is deliberately small.) `[AV-INVAR:pitch-90-identity]` — full write-up in `Avatar_Design.md` § 9.
- **`Q_TRANSITION_MS` = 1500** — repurposed as the mode-transition blend duration (§ 6).
- **`FBWB_CLIMB_RATE` (= 2)** — full-stick climb demand; with `AIRSPEED_CRUISE` sets CRUISE stick feel (§ 2). Raise toward `TECS_CLMB_MAX` (5) for aggressive tilt response.
- **`AIRSPEED_MAX` (= 10) is effectively inert** in this config: its only stock uses are in the speed-control machinery we run with `SKE_weighting=0` (inert speed demand bounds). Nothing measures speed against it — **there is no overspeed protection in either direction**; the aircraft will exceed 10 m/s if thrust/aero allow. Treat as documentation. If a structural Vne ever matters, the guard must be custom (vel-damp-style ceiling). One genuinely live use of the MIN/MAX *pair*: `ahrs.writeDefaultAirSpeed((MIN+MAX)/2, (MAX−MIN)/2)` (`ArduPlane.cpp:345`) seeds the EKF's synthetic-airspeed assumption (5 ± 5 m/s) used during GPS-denied dead reckoning. Keep MAX=10 — the midpoint 5 is a plausible Avatar cruise speed; raising MAX shifts that assumption.
- **`AIRSPEED_MIN` (= 0) is deliberate and requires a fork patch to even arm.** Stock ArduPlane rejects arming with `AIRSPEED_MIN < MIN_AIRSPEED_MIN` (=5 upstream); our commit `b31849b3da` ("add airspeed 0") set `MIN_AIRSPEED_MIN 0` in `ArduPlane/defines.h` — that patch and this param are a matched pair; don't change one without the other. Consequences of 0, all benign or desirable: (a) TECS underspeed/TASmin already neutralized by the backend patch — consistent; (b) `STALL_PREVENTION` (=1) is effectively neutered: `max_load_factor = smoothed_airspeed / MAX(AIRSPEED_MIN,1)` (`Attitude.cpp:677`) almost never binds, which is correct — we don't want bank limits driven by the near-garbage no-sensor airspeed estimate on an aircraft that can't stall; a residual 25° roll clamp survives when estimated airspeed < 1 m/s (harmless, arguably helpful near hover in a plane mode); (c) speed-scaler low-airspeed branch and coordination-yaw floors degrade gracefully (flight-validated in STABILIZE as-is); (d) `is_flying` airspeed threshold floors at 1.5 m/s via the stock `MAX(min,2)` guard. Everything else reading AIRSPEED_MIN (auto-takeoff, airspeed calibration, Q-assist, AUTO speed targets, DO_CHANGE_SPEED bounds) is inert in our config (no sensor, no speed loop, `Q_ASSIST_SPEED=-1`, flights bookend in STABILIZE).
- **`TRIM_THROTTLE` (= 45) is the cruise-speed knob — and it is NOT a throttle floor.** The no-airspeed throttle law (`AP_TECS.cpp` `_update_throttle_without_airspeed`) anchors at `nomThr = TRIM_THROTTLE + nudge`, then interpolates **up** toward `THR_MAX` proportionally to blended pitch (synth pitch = tilt elevation) over `PTCH_LIM_MAX` (90°), and **down** toward `THR_MIN` (0) for negative blended pitch over `PTCH_LIM_MIN` (−25°). So: level wing-borne cruise sits at exactly TRIM; descents go *below* TRIM; full tilt-up reaches THR_MAX. Since there is no speed loop, TRIM directly sets the level-flight thrust and therefore the emergent cruise speed. Too-high TRIM = faster than optimal cruise; too-low TRIM = the aircraft can't stay wing-borne and settles into a **mid-tilt equilibrium** (Osprey-style, see below) — stable and legitimate but less efficient than proper forward flight. Tune from flight data: note the level-flight speed at TRIM 45, walk down toward the wing-borne minimum. `THROTTLE_NUDGE` (upper half stick) only *adds* to TRIM — the pilot can push faster but never slower, so TRIM should be at or slightly above the desired unattended cruise. Caveat: TRIM sets a throttle %, not a speed — equilibrium speed drifts with wind and battery sag.
- **`THR_MAX` (= 100) must stay 100 — it is NOT a cruise-speed limiter.** In the no-airspeed law THR_MAX is only approached at high blended pitch, i.e. high tilt elevation — it is the ceiling for **vertical-thrust recovery** (sink arrest, integrator-wound deep tilt, § 3's whole point). Level cruise never touches it (level flight sits at TRIM regardless of THR_MAX). Lowering THR_MAX to cap speed would only starve thrust exactly where full authority is needed, while doing nothing to cruise speed. The speed knob is TRIM_THROTTLE.
- **Mid-tilt equilibrium (Osprey regime) is a natural TECS fixed point.** If wing lift at the current speed can't carry the weight, the height-loop integrator winds tilt up until vertical thrust makes up the deficit, and `[AV-INVAR:tecs-synth-pitch]` raises throttle in step. The system settles at whatever tilt balances forces — 45° tilt with the wing carrying partial weight is dramatically cheaper than hover (part of weight on the wing, props partially unloaded, prop power ∝ thrust^1.5). No special handling exists or is needed; it is simply where the loop converges when TRIM/wind put the aircraft below wing-borne speed. Guidance caveat: L1 degrades below ~3 m/s ground speed — don't *station-keep* in this regime in CRUISE; that's STABILIZE/QLOITER's job.
- **`TECS_SYNAIRSPEED` must stay 0.** Without a sensor TECS falls back to the `AIRSPEED_CRUISE` *constant* — deliberately NOT the AHRS airspeed estimate (EKF wind−GPS), which is near-garbage for a hovering vehicle (wind observability assumes coordinated fixed-wing flight). Setting 1 would both feed TECS that estimate AND reactivate `SKE_weighting` speed↔height trading, undoing the clean pure-height-control regime. (The AHRS estimate *is* legitimately used elsewhere: surface-PID speed scaler and the 25° low-speed bank cap.)
- No tuning required before first CRUISE flights — current values are the right (gentle) starting character. Log symptoms → knobs: oscillation with ~5–15 s period ⇒ raise `AIRSPEED_CRUISE` or `TECS_TIME_CONST`; sluggish altitude response ⇒ lower `AIRSPEED_CRUISE` or raise `FBWB_CLIMB_RATE`.
- **`TECS_CLMB_MAX` (= 5, stock default) — irrelevant to CRUISE stick flying, decide before AUTO.** Live uses: the height-demand slew limiter (`AP_TECS.cpp:538`) and the energy-rate demand clamp (line 1029) — i.e. the max climb rate TECS will *demand* during AUTO altitude legs and large altitude-error recovery. Never binds on CRUISE stick input (already capped at `FBWB_CLIMB_RATE`=2). The conventional-plane danger (demand > capability → airspeed decay → stall) is void on Avatar — over-demand just saturates at full tilt + THR_MAX. The real consideration: with `AIRSPEED_CRUISE`=3, sustained climb demand > ~3 m/s rails the pitch feed-forward past 90° ⇒ **AUTO altitude changes at CLMB_MAX=5 execute as full-tilt hover-climbs at max throttle** (battery-expensive). Lower to ~2 (matching FBWB_CLIMB_RATE) before AUTO missions if wing-borne climbs are preferred. (`TECS_SINK_MAX`=5 is the descent-side demand cap; actual descents are throttle-cut-dominated and further bounded by `PTCH_LIM_MIN_DEG`=−25.)
- **`TECS_TIME_CONST` (= 5) is the height-loop time horizon and a good candidate to lower after first flights.** Its dominant role (`AP_TECS.cpp:1027`): tilt-demand contribution ≈ `height_error / (TIME_CONST × AIRSPEED_CRUISE)` — at 5×3, a 1 m altitude error adds only ~3.8° of tilt. The 5 s default exists because conventional planes exchange energy through pitch/AoA with slow aerodynamic lag; Avatar's vertical thrust acts directly (copter-like plant, no aero lag chain), so a shorter horizon is physically justified. Its second role — the complementary-filter cutoff in the no-airspeed throttle law (`fc = 1/(2π·TC)`, line 1199) — barely matters here: blended pitch = HPF(demanded) + LPF(measured), and per `[AV-INVAR:pitch-90-identity]` measured tracks demanded within tilt-servo slew time, so throttle already responds essentially immediately. Tuning path: fly first sorties at 5, then step to 3 (bottom of the documented 3–10 range); 2–2.5 is plausible eventually — stock uses `TECS_LAND_TCONST=2` for the landing flare, the most delicate phase of a conventional flight. Watch for altitude/tilt oscillation, and change only one of `TECS_TIME_CONST` / `AIRSPEED_CRUISE` at a time — they multiply into the same gain. `TECS_VERT_ACC` (= 7) independently caps demand aggressiveness.

---

## 8. Wind and crabbing (why CRUISE needs no help)

- Steady wind is **invisible** to an aircraft in forward flight (no sideslip develops). A steady crosswind will not yaw the nose — weathervaning only exists when ground velocity is constrained (hover modes).
- Making good a course in crosswind requires pointing partially into the wind — the **crab** — and L1's steady state on a locked track is exactly that, automatically.
- Energy: power depends on airspeed (same in any strategy); energy = power × time; the straight crabbed track is time-optimal in uniform wind (Zermelo). Drift-then-home pursuit paths are strictly slower and more expensive.
- "Upwind is efficient" is a **station-keeping** fact (STABILIZE/QLOITER). For **transit**, tailwind is favorable. Plan loiter phases into wind, transit legs downwind.

---

## 9. Remaining work & flight verification checklist

**Before first CRUISE flight:**
1. **Param: `FLTMODE5` 0 → 7** (CRUISE on the switch, MANUAL motor-cut off it). *Only unimplemented code/param item.*
2. **RC failsafe: decided + implemented (`failsafe_kill_motors=false`)** — see `notes/rc_failsafe.md` for policy, operational rule after landing, and the open ELRS RX verification item. Requires rebuild + reflash.
3. **`FLTMODE2` = 11 = RTL is already on the switch** — flag, not necessarily a change. Plane RTL runs the same TECS+L1 machinery as CRUISE/AUTO (with `Q_RTL_MODE=0` it stays fixed-wing, climbs to `RTL_ALTITUDE`=100 m, orbits home). Until CRUISE is flight-validated, hitting switch position 2 invokes untested autonomy; after CRUISE validation it inherits that validation. Know it's there.
4. **Consider `ROLL_LIMIT_DEG` 45 → 30 for first locked-track/AUTO flights.** This is the only bank-angle guard left (the stall-prevention clamp is neutered by `AIRSPEED_MIN=0`, § 7), and CRUISE-with-lock / AUTO is the first time the autopilot commands bank autonomously; 45° at 3–5 m/s is aggressive. Pilot's call.
5. Bench check: armed in a TECS mode with `is_flying`, tilt rotors up → throttle demand rises (§ 3 sanity).
6. Confirmed correct as-is: `THROTTLE_NUDGE=1` (pilot's only speed-up authority), `FBWB_ELEV_REV=0` (stick back = climb). `NAVL1_PERIOD=17` — leave for now; tune from logs after lock engages (weaving ⇒ raise, lazy S-turns ⇒ lower).

**Flight re-verification (everything below is implemented + unit-tested but unflown):**
7. Copter→plane handoff — validated path, but now a 1.5 s vector blend instead of the old 0.5 s throttle blend.
8. STAB→QSTABILIZE: tilt no longer snaps vertical on entry (blend owns the servo command).
9. QSTAB→QLOITER with deliberately late stick centering (grace window works; no I-discharge surge at blend end).
10. CRUISE→STABILIZE: tilt holds (§ 4); `AVSD.VxHld = VxBf` at entry (vel-hold snapshot).
11. First CRUISE sorties from established forward flight: small roll inputs first (heading unlocked), then center sticks ≥ 0.5 s to engage the L1 lock. Watch `TECS`/`TEC2` (throttle tracking tilt, height loop damping) and L1 bank demands in wind.
12. QLOITER→CRUISE from hover (later): characterize the emergent high-throttle transition profile / mild climb (§ 6).
13. CRUISE climbs: confirm yaw PID cancels front-motor imbalance yaw (log-72 mechanism) and turns don't skid enough to degrade L1 — if they do, add the coordinated-turn feedforward (§ 2 yaw bullet).

**Then:** AUTO with a simple waypoint-only mission at altitude.

**Optional hardening (backlog):** small `_TAS_state` floor (~1 m/s) for hard-deceleration transients; hover-learn convergence check (§ 6); analyze AUTO NAV_TAKEOFF/NAV_LAND and VTOL mission items before use.
