---
layout: parameter
name: BUZZER_VOLUME
display_name: "Buzzer volume"
description: "Control the volume of the buzzer"
default_value: 100
range: 0 100
units: "%"
group: BUZZER
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/Tools/AP_Periph/Parameters.cpp#L224
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# Buzzer volume (BUZZER_VOLUME)

## Description
The **Buzzer Volume** parameter adjusts the loudness of the onboard piezoelectric buzzer. This is particularly useful for reducing noise during bench testing or indoor operations ("stealth mode"), while allowing for full volume during field operations to ensure audible status alerts and lost-model location.

## The Mathematics
The volume is controlled by varying the duty cycle or hardware gain of the buzzer driver, proportional to the percentage set.

$$ \text{Output Power} \propto \text{BUZZER\_VOLUME} \% $$

## The Engineer's View
This parameter is part of the `AP_Periph` (DroneCAN Peripheral) firmware, defined in `Tools/AP_Periph/Parameters.cpp`. It is read by the `AP_Notify` library. The value is clamped between 0 and 100. On supported hardware, this adjusts the PWM duty cycle driving the buzzer; on simpler hardware (on/off only), values $< 50\%$ might silence it or have no effect, while values $\ge 50\%$ enable it.

## Tuning & Behavior
*   **Default Value:** 100%
*   **Range:** 0 - 100
*   **0:** Silent.
*   **20-50:** Good for indoor bench testing.
*   **100:** Maximum volume for outdoor use.