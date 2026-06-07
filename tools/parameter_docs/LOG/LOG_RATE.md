---
layout: parameter
name: LOG_RATE
display_name: "External AHRS Logging Rate"
description: "The frequency (in Hz) at which data from an external AHRS device is recorded to the onboard log."
default_value: 10
range: 1 100
units: "Hz"
group: LOG
visual_asset_id: 
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_ExternalAHRS/AP_ExternalAHRS.cpp#L91
---

<!-- 
  NOTE: This file was automatically scaffolded. 
  Do not edit the frontmatter above unless necessary.
-->

# External AHRS Logging Rate (LOG_RATE)

## Description
This parameter controls the data recording frequency for "External AHRS" (Attitude and Heading Reference System) devices. When you use a specialized external sensor suite (like a VectorNav or a companion-computer based estimator) to provide attitude data to ArduPilot, this parameter determines how often that external data is saved to your SD card.

Setting an appropriate rate is important for post-flight analysis and digital twin simulations, ensuring you have enough resolution to see fast movements without bloating your log file size.

## The Mathematics
The logging interval ($T_{interval}$) is derived directly from the frequency:

$$ T_{interval} = \frac{1000}{LOG\_RATE} \text{ milliseconds} $$

The system checks the time elapsed since the last log write ($t_{now} - t_{last}$) and only writes a new entry if the elapsed time is greater than or equal to $T_{interval}$.

## The Engineer's View
In `AP_ExternalAHRS.cpp`, this maps to the `log_rate` member.
*   **Update Logic:** Inside the `AP_ExternalAHRS::update()` function, the code enforces the timing constraint:
    `if (log_rate.get() > 0 && now_ms - last_log_ms >= uint32_t(1000U/log_rate.get())) { ... }`
*   **Data Quality:** Note that this logging rate is independent of the *internal processing rate* of the EKF. Even if you log at 10Hz, the autopilot may still be using the external data at a much higher frequency (e.g., 50Hz or 100Hz) for stabilization.

## Tuning & Behavior
*   **Default Value:** 10 Hz.
*   **Range:** 1 to 100 Hz.
*   **General Use:** **10Hz** is sufficient for general navigation and flight path review.
*   **Acrobatics/Research:** Increase to **50Hz** if you are performing aggressive maneuvers and need to precisely compare the external AHRS performance against ArduPilot's internal EKF.
*   **0:** Disables logging for the external AHRS device.

