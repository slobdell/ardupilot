---
layout: parameter
name: ATC_PIRO_COMP
display_name: Pirouette Compensation Enable
description: Specifically for Helicopters. Controls whether the attitude controller compensates for the cross-coupling of roll and pitch during rapid yaw rotations (pirouettes).
default_value: 0
range: 0 1
units: 
group: ATC
visual_asset_id: atc_piro_comp_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AC_AttitudeControl/AC_AttitudeControl_Heli.cpp#L304
---

# Pirouette Compensation Enable (ATC_PIRO_COMP)

## Description
`ATC_PIRO_COMP` is a specialized feature for **Traditional Helicopters**. In physics, a helicopter spinning rapidly around its vertical axis (a pirouette) experiences intense cross-coupling between its roll and pitch axes.

Without compensation, if a helicopter is tilted forward and starts to spin, the tilt will appear to "wobble" or "cone" as the helicopter rotates, potentially leading to a crash. `ATC_PIRO_COMP` enables advanced math that keeps the tilt direction fixed relative to the earth, even while the airframe is spinning at extreme rates.

*   **Enabled (1):** The helicopter stays perfectly tilted in the desired direction regardless of its rotation speed. Essential for advanced 3D aerobatics.
*   **Disabled (0):** Standard flight mode. The pilot must manually correct for coning during spins.

**Note:** For Multirotors (Quads, Octos), this compensation is handled inherently by the Body-Frame controller architecture and this specific parameter is usually not present or needed.

## The Mathematics
The compensation logic involves rotating the roll and pitch targets into the moving frame of the helicopter:

$$ \begin{bmatrix} \text{Roll}_{comp} \\ \text{Pitch}_{comp} \end{bmatrix} = \mathbf{R}_z(\psi) \cdot \begin{bmatrix} \text{Roll}_{target} \\ \text{Pitch}_{target} \end{bmatrix} $$

Where $\mathbf{R}_z(\psi)$ is the rotation matrix around the yaw axis ($\psi$). This ensures that the cyclic commands (the "tilt" instructions) stay aligned with the earth's horizon rather than spinning with the heli's nose.

## The Engineer's View
This parameter is the `_piro_comp_enabled` member in `AC_AttitudeControl_Heli`.

It affects how the attitude error is calculated in `AC_AttitudeControl_Heli::update_ang_vel_target_from_att_error()`:

```cpp
// AC_AttitudeControl_Heli.cpp
if (_piro_comp_enabled) {
    // Perform frame rotation for cyclic commands
    // ...
}
```

This is particularly important for helicopters equipped with a **Mechanical Flybar**, as the physical flybar has its own gyroscopic inertia that must be accounted for by the software.

## Tuning & Behavior
*   **Default Value:** 0 (Disabled)
*   **Range:** 0 (Off) or 1 (On)
*   **Effect of Enabling:** Much more stable heading-independent flight. The heli feels more like a multirotor during fast spins.
*   **Effect of Disabling:** "Classical" helicopter flight feel.

### Use Case Recommendations
*   **3D Aerobatics (Smack flight):** **Always Enable (1).** Instant heading-locked attitude is required for maneuvers like "Piro-flips."
*   **Scale / Precision Helicopter:** **Enable (1).** Makes the helicopter much more predictable in wind during turns.
*   **Legacy Flybar Helicopters:** **Keep at 0.** These rely on the physical stability of the mechanical flybar; software piro-comp can sometimes fight the mechanical stabilization.

### Troubleshooting
*   **Scenario:** During a fast yaw spin, the helicopter starts to wobble in a circular motion (coning), eventually tilting further and further.
    *   **Diagnosis:** Pirouette coupling. The controller isn't keeping up with the rotation.
    *   **Fix:** Set `ATC_PIRO_COMP` to 1.