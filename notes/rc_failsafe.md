# RC Failsafe — Avatar Policy, History, and Ground-Safety Analysis

*Curated July 2026. Owns everything RC-linkloss for the Avatar. Other docs should link here, not duplicate.*

## 1. History: the blimp kill switch

The original blimp autopilot added a custom RC failsafe: link loss → immediate `arming.disarm(RADIOFAILSAFE)` — correct for a buoyant vehicle. Implemented as a `g_config.failsafe_kill_motors` check at the **top** of both `failsafe_short_on_event` and `failsafe_long_on_event` (`ArduPlane/events.cpp:25,119`, commented "SBL check for balloon kill switch"). While true, it bypasses ALL stock failsafe machinery — `FS_SHORT_ACTN` / `FS_LONG_ACTN` / `Q_OPTIONS` are irrelevant.

It was inherited unchanged by `avatarConfig` — meaning until July 2026, RC loss on the Avatar in ANY mode meant motors killed ~1.5 s later (`FS_SHORT_TIMEOUT`) and the aircraft falling.

## 2. Current policy (DECIDED + IMPLEMENTED July 2026)

**`avatarConfig.failsafe_kill_motors = false`** (`AP_CustomConfig.cpp`; blimp config must keep `true`). Compile-time field, not a runtime param — changing it requires rebuild + reflash.

Stock machinery now governs, which with current params gives:

| Situation at link loss | Short FS (1.5 s) | Long FS (5 s) |
|---|---|---|
| Q modes (QSTABILIZE/QLOITER/…) | QLAND | (already QLAND) |
| Plane modes (STABILIZE/CRUISE/…) | CIRCLE | RTL |
| AUTO | continue mission | RTL |

Detection chain: `THR_FAILSAFE=1`, `THR_FS_VALUE=950` — the RX must drop the throttle channel below 950 µs on link loss. **Open verification item: confirm the ELRS RX failsafe mode is "no pulses" or a failsafe position with throttle < 950, NOT hold-last-position — otherwise no failsafe ever triggers.**

Note: failsafe-initiated mode changes pass through the `[AV-INVAR:mode-transition-blend]` like any other mode edge (accepted behavior).

## 3. Ground-safety analysis (radio off while armed on the ground)

Historical workflow: land, don't disarm, turn radio off → kill switch guaranteed disarm. With the new policy this splits by mode:

**Landed in a Q mode → still a guaranteed disarm.** FS → QLAND → on the ground the land detector confirms → `arming.disarm(Method::LANDED)` (`quadplane.cpp:3933`) within seconds. Possibly a brief prop spin while QLAND initializes. (QLAND's land detector is unflown on Avatar — verify once.)

**Landed in a plane mode → motors silent but NEVER disarms.** FS → CIRCLE; every mode entry re-latches `throttle_suppressed = true` for auto-throttle modes (`mode.cpp:114`); on a stationary landed aircraft no release condition fires, the suppressed (zero) throttle flows through to the quad-motor mixer, and the `[AV-INVAR:min-thr-tilt]` floor is `is_flying()`-gated so it stays off. **However**, two suppression-release tripwires stay live indefinitely (`servos.cpp:135-160`):
- |baro altitude − home| ≥ 10 m (either direction — baro drift over a long session can cross this)
- GPS ground-speed spike ≥ 5 m/s (bad reception)

Either one → TECS throttles to ~`TRIM_THROTTLE` on the ground with no timeout ever disarming.

**Operational rule: after landing, either disarm deliberately, or switch to a Q mode before turning the radio off.** Never leave the aircraft armed in a plane mode with the radio off.

## 4. Ground disarm on link loss — ✅ IMPLEMENTED (`[AV-INVAR:fs-ground-disarm]`, July 2026)

Radio-off is once again a guaranteed disarm in **every** mode, without the blimp kill switch's crash-on-linkloss-in-flight behavior:

> On RC link loss (short or long), disarm immediately iff `!is_flying()` **AND** the mixer's commanded trim thrust has been < 5% for > 3 s. Otherwise fall through to stock recovery (§ 2 table).

Why both conditions: a bare `!is_flying()` gate has one crash-grade false-negative window — near-stationary flight in a TECS mode (CRUISE deep-headwind / mid-tilt regime) with the pilot stick at bottom, where `is_flying()` can decay false at altitude (§ 5). The thrust-quiet condition closes it: every airborne regime commands substantial thrust (STABILIZE hover: pilot stick high; CRUISE: TECS ≥ ~TRIM even with stick at bottom); a landed aircraft commands ~0 in every mode.

Implementation: `g_config.failsafe_disarm_when_landed` (Avatar true, blimp false); quiet clock `MixerState::thrust_quiet_s` in the AvatarMixer (both branches, spool-aware); gate `Plane::failsafe_landed_disarm_check()` at the top of both failsafe handlers in `events.cpp`. Unit tests: `tests/mixer_test` Group Q (clock semantics in both branches, reset-on-thrust, unspooled-counts-as-quiet). Full invariant write-up: `Avatar_Design.md` § 9.

**Consequence for the § 3 operational rule:** once this build is flashed, the after-landing rule relaxes back to the old workflow — land (any mode), throttle at zero ≥ 3 s, radio off → disarm. The § 3 analysis still describes what happens if the gate ever declines (e.g. radio off < 3 s after touchdown): stock behavior, which for plane modes means armed-but-suppressed. Flight verification: confirm disarm fires on the bench (armed, spooled, throttle zero > 3 s, radio off) before relying on it.

## 5. `is_flying()` behavior on Avatar (analysis, July 2026)

`Plane::update_is_flying_5Hz()` (`is_flying.cpp:40`) consults `QuadPlane::is_flying()` **first, in all modes** — which returns true when `motors->get_throttle() > 1%` (`quadplane.cpp:1254`). On Avatar, the custom plane-mode branch calls `attitude_control->set_throttle_out(get_pilot_throttle(), ...)` (`quadplane.cpp:2174`), so `motors->get_throttle()` reads the **pilot throttle stick** in plane modes:

- **Plane STABILIZE stationary hover (primary mission): SAFE.** Hovering requires a high throttle stick → `get_throttle()` high → reads as flying regardless of ground speed.
- **CRUISE / TECS modes: stick is normally at bottom** (TECS flies the throttle; the stick is only a nudge) → `get_throttle()` ≈ 0 → falls through to fixed-wing heuristics: GPS ground speed ≥ 1.5 m/s or airspeed estimate ≥ 1.5 m/s. In normal forward flight these hold easily. **The gap:** deep-headwind near-stationary CRUISE (ground speed < 1.5 m/s, no-sensor airspeed estimate unreliable) can decay `is_flying()` to false at altitude.
- **On the ground after landing** (any mode, throttle stick down): `get_throttle()` ≈ 0, no GPS movement → decays to false within seconds. This is the state the § 4 disarm wants to catch.
