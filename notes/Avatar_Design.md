# Design Document: Avatar Tilt-Rotor Fixed-Wing Aircraft

**Status:** Design finalized, AvatarMixer implementation pending
**Test Airframe:** Hee-wing T1 Ranger

---

## 1. Concept & Mission

The Avatar is a zero-stall-speed fixed-wing aircraft. The core idea is that the aircraft's wings themselves rotate on a servo-driven axis, carrying the motors with them. At low speeds or during stall conditions, the wings tilt upward toward vertical, converting the motors into a hover-capable lift system. At cruise speed, the wings are horizontal and the motors provide forward thrust in the conventional sense.

The design goal is that this transition happens **automatically and continuously** — it is not a discrete mode switch. The aircraft should always be trying to fly as a plane, and the motor tilt naturally adjusts to whatever the aerodynamics require.

---

## 2. Hardware Layout

### 2.1 Motors
- **Motor 1 (Left Wing):** Fixed to the left wing, tilts with the wing. Provides lift and/or forward thrust depending on wing angle.
- **Motor 2 (Right Wing):** Fixed to the right wing, tilts with the wing. Always commanded identical thrust to Motor 1.
- **Motor 3 (Rear, Optional):** Rear-mounted motor. Provides yaw authority at low speeds, and progressively contributes lift as the wings tilt upward. Not present on the initial T1 Ranger test airframe.

### 2.2 Servos
- **Single Tilt Servo:** Drives both wings simultaneously via a shared mechanical linkage. Controls the pitch axis of the thrust vector only. **Roll axis tilt is mechanically impossible** and is not implemented.

### 2.3 Yaw (Production Design)
In the full production design, the two rear motors are mounted on spring-controlled levers. Increasing yaw thrust on one side causes that motor to swing outward and deliver side thrust, providing yaw authority at low speeds and in copter mode. This mechanism is **not present on the T1 Ranger test airframe**; yaw is uncontrolled during testing and accepted as a limitation.

### 2.4 Roll Control
Roll is achieved via differential thrust between the two wing motors. Effectiveness scales with `cos(wing_tilt_angle)`:

- **Wings vertical (hover, 0°):** `cos(0°) = 1.0` — full roll authority
- **Wings horizontal (forward flight, 90°):** `cos(90°) = 0.0` — no roll authority
- **Intermediate angles:** proportional authority (e.g., 45° → 0.7)

This is physically motivated: motors pointing upward produce roll when thrust is differential; motors pointing forward produce yaw instead. The yaw side effect from prop torque imbalance is accepted as a known limitation. Roll authority smoothly fades to zero as the aircraft transitions to forward flight, at which point aerodynamic surfaces take over.

---

## 3. Relationship to the Blimp

The Avatar and the Blimp share the same fundamental control philosophy and the same TVC brain (`tvc_run_main_logic`). The pattern match is direct:

| Concept | Blimp | Avatar |
|---------|-------|--------|
| Thrust-vectored motors | 2 on a tilting gondola | 2 on tilting wings |
| Tilt servo | 1 (pitch only) | 1 (pitch only) |
| Default position | Motors face forward | Wings horizontal |
| Elevator saturation response | Gondola tilts upward | Wings tilt upward |
| Emergency downward thrust | Yes (fly-away recovery) | No |
| Yaw motor | 1 tail motor | 1 rear motor (optional) |
| Roll control | None | Differential thrust, scaled by `cos(tilt_angle)` |
| TVC core | `tvc_run_main_logic` | `tvc_run_main_logic` (reused) |

The key difference is geometry: the blimp's tilt range spans past vertical (up to 180° for downward emergency thrust), while the Avatar's range is 0° (wings vertical = hover) to 90° (wings horizontal = forward flight). This is reflected in `avatarConfig`:

```cpp
.forward_flight_physical_angle_deg = 90.0f,   // Wings horizontal
.reverse_flight_physical_angle_deg = 0.0f,    // No downward thrust
```

---

## 4. Control Architecture

### 4.1 The 6DOF Motor Mixer Philosophy

This is a critical distinction from a conventional fixed-wing. The Avatar uses the ArduPilot 6DOF motor mixer, which means:

- **Forward stick** → forward thrust vector (wings tilt slightly forward) — **not** a pitch command
- **Throttle** → vertical thrust component
- **ArduPilot's attitude controller** maintains level flight by adjusting throttle, not by pitching the nose

This means the aircraft can fly forward while remaining aerodynamically level. The intended base test case is: arm in copter mode, apply forward stick, aircraft moves forward slowly via motors tilting slightly forward, ArduPilot increases throttle to compensate for the reduced vertical component.

### 4.2 Wing Tilt Logic (The TVC Brain)

Wing tilt is computed by `tvc_run_main_logic` and is identical to the blimp. The key formula:

```cpp
float target_pitch_deg = atan2(forward_cmd, thrust_cmd);
target_pitch_deg += current_pitch_deg;  // Pitch compensation
```

The `atan2` converts the pilot's 2D thrust intent (forward + vertical) into a target wing angle. The pitch compensation offsets this by the aircraft's actual pitch, ensuring the absolute thrust vector stays in the intended direction regardless of aircraft orientation.

**This is also the stall-prevention mechanism** (see section 4.3).

The output `pitch_angle_norm` drives the single tilt servo via `outputs.tilt_angle` in the mixer.

The code runs in `OPEN_LOOP_SERVO_MODE = true`, meaning stick position maps directly to servo angle with no PID. This is simpler and appropriate for initial testing.

### 4.3 Automatic Stall Prevention

The stall-prevention behavior is a natural consequence of the pitch compensation — it is not a separate feature or mode switch.

**Sequence at low-speed/stall:**
1. Aircraft starts to pitch up (nose rises) due to lack of airspeed or aerodynamic instability
2. Elevator is already saturated — conventional pitch control is exhausted
3. `current_pitch_deg` increases (aircraft is pitched up)
4. `target_pitch_deg += current_pitch_deg` causes the TVC to command a larger tilt angle
5. Wings tilt upward toward vertical
6. More of the motor thrust is directed upward → lift increases → aircraft is stabilized

**Sequence during normal cruise:**
1. Aircraft has airspeed, elevator is effective, ArduPilot maintains level attitude
2. `current_pitch_deg ≈ 0°`
3. Compensation adds ~0° to the target
4. Wings stay near horizontal → normal forward flight

This is a continuous, proportional response. There is no threshold or mode switch. The wings tilt as much as the pitch deviation demands.

### 4.4 Rear Motor Activation (Production Design, Not Required for T1 Ranger Test)

The rear motor has two components:

1. **Base thrust**: Proportional to `sin(wing_angle_rad)`. At 0° (wings horizontal), rear motor contributes nothing to lift. At 90° (wings vertical), rear motor is at full base lift.
2. **Pitch delta**: The ArduPilot yaw command is mixed in for directional authority at low speeds.

```
rear_motor_thrust = base_lift * sin(wing_angle) ± pitch_input
```

The `sin` scaling is physically motivated: as the wing motors tilt away from vertical, the rear motor progressively compensates for the reduced vertical component.

---

## 5. Configuration System

### 5.1 Switching to Avatar

Change one line in `libraries/AP_CustomConfig/AP_CustomConfig.h`:

```cpp
#define ACTIVE_CONFIG CONFIG_TYPE_AVATAR  // was CONFIG_TYPE_BLIMP
```

This switches `g_config` to `avatarConfig`, selects `AvatarMixer` in `AP_Motors6DOF::init()`, and changes the preprocessor defines (`EMERGENCY_BLIMP_MANUAL_MODE = false`, etc.).

### 5.2 Avatar Config Values (`AP_CustomConfig.cpp`)

| Field | Value | Rationale |
|-------|-------|-----------|
| `tricopter_is_blimp` | false | Selects AvatarMixer |
| `forward_flight_physical_angle_deg` | 90.0° | Wings horizontal = max forward |
| `reverse_flight_physical_angle_deg` | 0.0° | No downward thrust needed |
| `platform_max_angle_deg` | 90.0° | Full tilt range |
| `mot_spin_neutral` | 1000 | Non-reversible motors |
| `diff_yaw_enabled` | 1 | Differential yaw (for rear motor) |
| `lifting_motors_reversible` | false | Wing motors are unidirectional |
| `emergency_blimp_manual_mode` | false | Blimp-specific feature, not needed |
| `optical_flow_stabilized_roll/pitch` | false | Not applicable |

---

## 6. Implementation Status

### 6.1 Already Working (Reused from Blimp)
- `tvc_run_main_logic` — full TVC brain with pitch compensation, gain scheduling, VTOL blending
- `AP_CustomConfig` selector pattern — flip one `#define` to switch vehicles
- `AP_Motors6DOF` backend — mixer dispatch, output routing, spool state handling
- `MixerInputs` / `MixerOutputs` / `MixerState` data contracts

### 6.2 Needs Implementation
- **`AvatarMixer::setup_motors()`** — currently a 3-motor blimp placeholder. Needs: left wing motor (throttle only), right wing motor (throttle only), optional rear motor (yaw factor, zero throttle).
- **`AvatarMixer::mix()`** — currently zeros all outputs. Needs to implement the same copter/plane/manual-override state machine as `BlimpMixer::mix()`, with Avatar-specific motor mapping (same wing thrust, `sin(wing_angle)` rear motor).
- **Motor count fix** — `init()` expects 5 motors for Avatar, but only 3 are registered. Fix: update `wantMotors` for Avatar to 3 (or 2 if rear motor is optional at build time).

### 6.3 Not Required for T1 Ranger Test
- Rear motor `sin(wing_angle)` formula — rear motor absent on test airframe
- Spring-lever yaw mechanism — not present on T1 Ranger

---

## 7. Test Plan (T1 Ranger)

### 7.1 ArduPilot Configuration
Configure the T1 Ranger as a **QuadPlane**. This is primarily to access copter (Q) modes for testing the mixer logic. The production intent is that plane mode works at all times, but copter mode provides a controlled environment to validate motor mixing before full-plane testing.

### 7.2 Base Test Case: Copter Mode Forward Flight
1. Arm in a Q-mode (e.g., QHOVER or QSTABILIZE)
2. Apply throttle to hover near ground
3. Apply forward stick — observe wings tilt slightly forward
4. Aircraft should move forward slowly while ArduPilot maintains altitude
5. Release forward stick — wings return to vertical, aircraft decelerates

This validates the core 6DOF thrust-vector concept without relying on aerodynamics.

### 7.3 Stall Prevention Validation (Later)
1. Transition to plane mode
2. Fly at progressively lower airspeeds
3. Observe that as elevator saturates, wings tilt upward automatically
4. Confirm aircraft recovers rather than stalling

**Known limitations for T1 Ranger test:**
- No yaw control in copter mode
- No roll control in copter mode
- Plane-mode stall-prevention loop stability is theoretically sound but untested — behavior at the transition boundary is the highest-uncertainty element of the design
