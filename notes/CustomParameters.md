# Custom Parameters — Design Plan

## Goal

Replace hard-coded tuning constants in `CustomConfig` and `TVC_Core` with proper ArduPilot parameters that persist to EEPROM and are adjustable at runtime from any GCS (Mission Planner, QGroundControl, MAVProxy `param set`). This eliminates the recompile-reflash cycle for values that are calibration-dependent or need in-flight iteration.

---

## Approach: `AP_CustomParams` subgroup in `ParametersG2`

This is "Approach D" from the parameter system investigation. The pattern exactly mirrors how other ArduPlane param groups work (see `ParametersG2::var_info[]` in `ArduPlane/Parameters.cpp`).

**Architecture summary:**
- Create a new class `AP_CustomParams` in `libraries/AP_CustomConfig/`
- Register it as a subgroup inside `ParametersG2` using `AP_SUBGROUPINFO`
- Access params anywhere via `plane.g2.custom_params.<field>.get()`
- Fields that are topology/compile-time (vehicle type, boolean feature flags) stay as `const` in `CustomConfig` — no change needed there

---

## Values That Become Parameters

### Geometry / Calibration (Avatar)

| Param name | `CustomConfig` field | Default | Notes |
|---|---|---|---|
| `AV_FWD_ANG` | `forward_flight_physical_angle_deg` | `90.0` | Physical servo angle for fully-forward (horizontal) wing position. Varies with servo arm length and linkage. Will change when past-horizontal tilt is implemented (see Avatar_Design.md § 4.4.3). |
| `AV_REV_ANG` | `reverse_flight_physical_angle_deg` | `0.0` | Physical servo angle for fully-rearward wing position. Currently a guard value — set to the real backward limit once servo range is calibrated (see TODO.md — Backward servo range). |
| `AV_MAX_ANG` | `platform_max_angle_deg` | `90.0` | Maximum platform angle used to normalize TVC output. Calibration-dependent. |
| `AV_CRZ_ANG` | *(future field)* | `90.0` | Cruise angle for past-horizontal tilt feature. Not yet a `CustomConfig` field — add this param at the same time the past-horizontal tilt feature is implemented. |

### Blimp Tuning

| Param name | `CustomConfig` field | Default | Notes |
|---|---|---|---|
| `AV_ELEV_HO` | `elevator_tilt_handoff_point` | `0.5` | Fraction of pitch demand (0.0–1.0) at which elevator authority saturates and motor tilt begins. Requires in-flight tuning against actual elevator authority at cruise speed. |

### TVC Gains (`tvc_config` in `TVC_Core.cpp`)

These are separate from `CustomConfig` — they live in the `TVC_Config` struct passed to `tvc_run_main_logic`. They need params most urgently since PID tuning is the primary iteration loop during flight testing.

| Param name | `TVC_Config` field | Default | Notes |
|---|---|---|---|
| `AV_TC_RLL_P` | roll angle P gain | *(current hardcoded value)* | Outer loop — angle to rate |
| `AV_TC_PCH_P` | pitch angle P gain | *(current hardcoded value)* | Outer loop — angle to rate |
| `AV_TC_RP_P` | roll rate P | *(current hardcoded value)* | Inner loop |
| `AV_TC_RP_I` | roll rate I | *(current hardcoded value)* | Inner loop |
| `AV_TC_RP_D` | roll rate D | *(current hardcoded value)* | Inner loop |
| `AV_TC_PP_P` | pitch rate P | *(current hardcoded value)* | Inner loop |
| `AV_TC_PP_I` | pitch rate I | *(current hardcoded value)* | Inner loop |
| `AV_TC_PP_D` | pitch rate D | *(current hardcoded value)* | Inner loop |

> **Note:** Fill in the actual default values from `TVC_Core.cpp` when implementing. The param system requires a compile-time default in `AP_GROUPINFO` — these defaults should match whatever the current hardcoded values are.

### Deferred — Fine as Compile-Time Constants

These fields could become params eventually but have no immediate tuning need:

- `tricopter_is_blimp` — vehicle selection; changes require a different firmware build anyway
- `diff_yaw_enabled` — topology flag
- `mot_spin_neutral`, `mot_spin_min` — could move to params, but these are currently stable and setting them correctly is a one-time calibration in `SERVO_BLH_*` territory
- `emergency_blimp_manual_mode` — safety toggle, not a tuning value
- `caterpillar_h_frame_6dof` — dormant

---

## Implementation Steps

### 1. Create `AP_CustomParams` class

New files: `libraries/AP_CustomConfig/AP_CustomParams.h` and `AP_CustomParams.cpp`.

**`AP_CustomParams.h`:**
```cpp
#pragma once
#include <AP_Param/AP_Param.h>

class AP_CustomParams {
public:
    AP_CustomParams();
    static const AP_Param::GroupInfo var_info[];

    // Avatar geometry
    AP_Float fwd_angle;
    AP_Float rev_angle;
    AP_Float max_angle;
    AP_Float crz_angle;

    // Blimp tuning
    AP_Float elev_handoff;

    // TVC rate/angle gains
    AP_Float tc_rll_p;
    AP_Float tc_pch_p;
    AP_Float tc_rp_p;
    AP_Float tc_rp_i;
    AP_Float tc_rp_d;
    AP_Float tc_pp_p;
    AP_Float tc_pp_i;
    AP_Float tc_pp_d;
};
```

**`AP_CustomParams.cpp`:**
```cpp
#include "AP_CustomParams.h"

const AP_Param::GroupInfo AP_CustomParams::var_info[] = {
    AP_GROUPINFO("FWD_ANG",  1, AP_CustomParams, fwd_angle,   90.0f),
    AP_GROUPINFO("REV_ANG",  2, AP_CustomParams, rev_angle,    0.0f),
    AP_GROUPINFO("MAX_ANG",  3, AP_CustomParams, max_angle,   90.0f),
    AP_GROUPINFO("CRZ_ANG",  4, AP_CustomParams, crz_angle,   90.0f),
    AP_GROUPINFO("ELEV_HO",  5, AP_CustomParams, elev_handoff, 0.5f),
    AP_GROUPINFO("TC_RLL_P", 6, AP_CustomParams, tc_rll_p,  <default>),
    AP_GROUPINFO("TC_PCH_P", 7, AP_CustomParams, tc_pch_p,  <default>),
    AP_GROUPINFO("TC_RP_P",  8, AP_CustomParams, tc_rp_p,   <default>),
    AP_GROUPINFO("TC_RP_I",  9, AP_CustomParams, tc_rp_i,   <default>),
    AP_GROUPINFO("TC_RP_D", 10, AP_CustomParams, tc_rp_d,   <default>),
    AP_GROUPINFO("TC_PP_P", 11, AP_CustomParams, tc_pp_p,   <default>),
    AP_GROUPINFO("TC_PP_I", 12, AP_CustomParams, tc_pp_i,   <default>),
    AP_GROUPINFO("TC_PP_D", 13, AP_CustomParams, tc_pp_d,   <default>),
    AP_GROUPEND
};

AP_CustomParams::AP_CustomParams() {
    AP_Param::setup_object_defaults(this, var_info);
}
```

### 2. Register the subgroup in `ParametersG2`

**`ArduPlane/Parameters.h`** — add to `ParametersG2` class body:
```cpp
#include <AP_CustomConfig/AP_CustomParams.h>
AP_CustomParams custom_params;
```

**`ArduPlane/Parameters.cpp`** — add one entry to `ParametersG2::var_info[]`. The index `37` is the next free slot after the last registered entry (`RNGFND_LND_ORNT` = 36):
```cpp
AP_SUBGROUPINFO(custom_params, "AV_", 37, ParametersG2, AP_CustomParams),
```

The `"AV_"` prefix means every param appears in the GCS as `AV_FWD_ANG`, `AV_TC_RP_P`, etc.

### 3. Replace `g_config` reads at call sites

For each field that becomes a param, replace:
```cpp
g_config.forward_flight_physical_angle_deg
```
with:
```cpp
plane.g2.custom_params.fwd_angle.get()
```

The primary call sites are in `TVC_Core.cpp` (geometry params) and `AvatarMixer` / `BlimpMixer` (elevator handoff, angle limits). TVC gain params replace the corresponding fields in the `tvc_config` struct initialization in `TVC_Core.cpp`.

**Do not remove `g_config` fields** until all call sites are migrated and bench-tested — the const fields can stay as-is, and the tunable fields can be removed from the struct once the param versions are validated.

### 4. Add `AP_CustomParams.cpp` to the build

In `libraries/AP_CustomConfig/CMakeLists.txt` (or the equivalent `wscript`), add `AP_CustomParams.cpp` to the source list. The library is already linked into ArduPlane via the existing `AP_CustomConfig` dependency.

---

## What Does NOT Change

- `CustomConfig` struct — keep all existing fields; eventually prune the ones that move to params, but not until validated
- `g_config` reference — still valid for boolean/topology fields
- `ACTIVE_CONFIG` / preprocessor compatibility layer — unchanged
- `ENABLE_TRICOPTER_VTOL_BACKEND` guards — unchanged

---

## Notes on Index Numbers and EEPROM Encoding

**Hard limit: indices must be 0–63.** ArduPilot's EEPROM layout encodes each parameter's address as an 18-bit `group_element` field split into three 6-bit levels (`_group_level_shift = 6` in `AP_Param.h`). An `idx` value above 63 overflows the 6-bit slot and silently aliases to another entry — this causes silent EEPROM corruption, not a compile error. There is no way to use a "safe high" number like 99 to future-proof against upstream conflicts.

**Collision risk is lower than it looks.** Only one index needs to not collide with upstream `ParametersG2` entries: the single `AP_SUBGROUPINFO` line. The 13+ internal indices inside `AP_CustomParams::var_info[]` are in their own isolated namespace — upstream changes to `ParametersG2` can never affect them.

**Stability rules once assigned:**
1. Never reuse or renumber an index — changing an idx changes the EEPROM address, causing the field to read garbage after a firmware update
2. Retired entries should be commented out with `// retired: <name>` to document the reserved slot, not deleted
3. The `k_param_*` enum in `Parameters.h` has the same constraint; new entries go at the end

**Checking for upstream conflicts:** Before assigning index 37 to the `AP_SUBGROUPINFO`, grep `ParametersG2::var_info[]` in `ArduPlane/Parameters.cpp` and confirm 37 is not already used. The last upstream entry at time of writing is `RNGFND_LND_ORNT` = 36.

---

## Testing Checklist (When Airframe Is Available)

- [ ] Flash firmware with `AP_CustomParams` integrated
- [ ] Connect GCS and confirm `AV_*` params appear in the parameter list
- [ ] Verify defaults match previous hardcoded values exactly
- [ ] Change `AV_FWD_ANG` in GCS, power-cycle, confirm value survives reboot (EEPROM persistence check)
- [ ] Fly with `AV_TC_RP_P` / `AV_TC_PP_P` — adjust in flight via MAVProxy `param set AV_TC_RP_P 1.5` and observe response
- [ ] After tuning, save a `.param` file as the golden-master baseline
