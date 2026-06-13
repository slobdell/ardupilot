# SBUS Reference

---

## 1. Signal Scaling

Linear mapping between raw 11-bit SBUS values (0–2047) and ArduPilot PWM microseconds (1000–2000 µs). Empirically validated on MicoAir H743 with custom ArduPilot firmware.

### Input (Raw SBUS → PWM)
```
PWM = (RAW_SBUS × 0.625) + 875
```

### Output (PWM → Raw SBUS)
```
RAW_SBUS = (PWM − 875) × 1.6
```

### Validation Data

**Input (SBUS generator → FC):**

| Raw SBUS | Expected PWM (µs) | Actual PWM (µs) |
|:--------:|:-----------------:|:---------------:|
| 368 | 1105 | 1105 |
| 1024 | 1515 | 1515 |
| 1680 | 1925 | 1925 |

**Output (FC → SBUS parser):**

| PWM (µs) | Expected Raw | Actual Raw |
|:--------:|:------------:|:----------:|
| 1000 | 200 | 201 |
| 1500 | 1000 | 1001 |
| 1600 | 1160 | 1161 |
| 2000 | 1800 | 1801 |

Off-by-one differences are expected — integer math rounding.

**Note on indexing:** ArduPilot `rcin` and `sbus` arrays are 0-indexed. SBUS Channel 1 = array index 0.

---

## 2. Bus A: PFC → TVC & SFCs ("State Bus")

Broadcast from the PFC, read by both the TVC and all SFCs. Communicates QuadPlane state machine outputs and hover stabilization commands.

*Channel count varies by airframe. The table below reflects the full 6-pod (24-motor) system. For the tricopter, see `VTOL_Tricopter_Architecture.md`. For Avatar, channels 1–5 are used.*

| Ch | Index | Signal | Type | Description |
|:---|:------|:-------|:-----|:------------|
| 1–6 | 0–5 | `base_throttle[0–5]` | float 0–1 | Per-pod stabilization thrust from 6DOF hover controller |
| 7 | 6 | `hover_thrust_cmd` | float 0–1 | Raw pilot vertical thrust command |
| 8 | 7 | `hover_forward_cmd` | float ±1 | Raw pilot forward/backward command |
| 9 | 8 | `hover_lateral_cmd` | float ±1 | Raw pilot lateral command |
| 10 | 9 | *(reserved)* | — | — |
| 11 | 10 | `transition_progress` | float 0–1 | VTOL transition state: 0 = hover, 1 = forward flight |
| 12 | 11 | `plane_throttle_cmd` | float 0–1 | Fixed-wing controller throttle command |
| 13 | 12 | `TUNING_SELECTOR` | 3-pos switch | *(proposed)* RC switch for PID gain selection (P/I/D) |
| 14 | 13 | `TUNING_VALUE` | float 0–1 | *(proposed)* RC knob value for selected PID gain |
| 15–16 | 14–15 | *(reserved)* | — | — |

---

## 3. Bus B: TVC → SFCs ("Blended Control Signal Bus")

Broadcast from the TVC to all SFCs. Carries final blended control signals for execution. Channel meanings are consistent across all flight modes.

| Ch | Index | Signal | Type | Description |
|:---|:------|:-------|:-----|:------------|
| 1–12 | 0–11 | `blended_vectors[0–11]` | float ±1 | Final blended per-pod vector commands (pitch/roll for each of 6 pods) |
| 13 | 12 | `hover_thrust_factor` | float 1–2+ | Unblended thrust compensation (`1/cos(angle)`) for hover model |
| 14–15 | 13–14 | *(reserved)* | — | — |
| 16 | 15 | `tvc_health` | bool | TVC AHRS health: low = unhealthy, high = healthy. Used by SFCs for pre-flight check |
