# Avatar STABILIZE Mode — Pilot-Scheduled Tilt Control

## Concept

Production flight mode for the Avatar. The pilot directly controls the tilt angle via the pitch stick with no TECS or autonomous energy management involved. The autopilot's only job is to keep the airframe stable at whatever tilt the pilot commands.

This is the mode the aircraft should be flown in from takeoff through forward flight. Copter (Q) modes exist for bench testing and controls validation only.

## Why Not FBWA

FBWA has TECS running, which feeds `nav_pitch_cd` and autonomously influences tilt angle for energy management. This means the autopilot is making tilt decisions, not the pilot. For a novel tiltrotor aircraft on its first flight tests, that is premature — the pilot needs to own the transition schedule.

## Why STABILIZE

- No TECS — pilot owns tilt entirely
- Attitude stabilization still runs — autopilot holds the airframe level
- Pitch stick → tilt angle directly
- Elevator and rear motor cooperate to hold fuselage level (same architecture as FBWA)
- Roll via ailerons and motor differential still works

## Flight Profile

1. Arm in STABILIZE, pitch stick full back → wings vertical
2. Throttle up → lift off
3. Gradually push pitch forward → tilt moves toward horizontal → airspeed builds → wing lift develops
4. Fly as a plane — autopilot holds fuselage stable, pilot holds tilt
5. To land: pull pitch back → tilt returns toward vertical → slow down → set down

## Control Architecture

Pitch stick drives `pitch_tilt_demand` directly (raw stick, not `nav_pitch_cd`). The elevator and rear motor are driven by the copter attitude controller targeting level fuselage — identical to what we already do in FBWA. The tilt angle is the pilot's domain; attitude stability is the autopilot's domain. These are orthogonal.

## Implementation Approach (not yet implemented)

In `quadplane.cpp`, in the STABILIZE plane-mode block:

```cpp
plane_inputs.pitch_tilt_demand = -channel_pitch->norm_input_dz();
```

Rather than `nav_pitch_cd / pitch_limit_max`. Everything downstream in `AvatarMixer` (tilt slew, cos_tilt scaling, rear motor, roll differential) is unchanged.

The `[AV-INVAR:tilt-follows-nav-pitch]` invariant applies only to FBWA. STABILIZE gets raw stick.

## Open Questions

- **Rate vs position**: Does releasing the pitch stick hold tilt (rate control, integrator) or return to a neutral position (position mapping)? Rate control is more natural for manual transition scheduling. To be resolved in flight testing.
- **Slew rate limiting**: `[AV-INVAR:plane-tilt-slew]` still applies — fast toward vertical (stall recovery), slow toward horizontal (airspeed must build). Same rates as FBWA.
- **Transition to FBWA**: Once the pilot is comfortable with manual scheduling, FBWA can be enabled for autonomous tilt management. The two modes share the same mixer so the transition is seamless.
