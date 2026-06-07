---
layout: parameter
title: TURBO_MODE
name: Enable turbo mode
group: TURBO
---

# TURBO_MODE: Enable turbo mode

## Description
Enables double speed on high offset.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 0

## Description
This parameter is specific to the **Blimp** vehicle type when using flapping fin propulsion.

- **Function:** When enabled, if the fin offset is high (meaning a large steering or pitch command is applied) and the oscillation amplitude is low, the flapping frequency is doubled.
- **Effect:** This provides a burst of extra control authority ("Turbo") during aggressive maneuvers.

