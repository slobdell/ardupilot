---
layout: parameter
name: EK3_HGT_DELAY
display_name: EKF3 Height Measurement Delay
description: Defines the time lag (in milliseconds) between when a height sensor (Baro/Lidar) takes a reading and when the EKF3 receives it. 
default_value: 60
range: 0 250
units: ms
group: EKF
visual_asset_id: ek3_hgt_delay_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/a37665a24621058938f5573dd0acb970002417ab/libraries/AP_NavEKF3/AP_NavEKF3.cpp#L235
---

# EKF3 Height Measurement Delay (EK3_HGT_DELAY)

## Description
`EK3_HGT_DELAY` accounts for the "speed of sound" (and calculation) in your drone's height sensors. 

Accelerometers are instantaneous, but Barometers and Rangefinders take time to process their data. By the time the Barometer tells the EKF "I am at 10 meters," that measurement is actually 60 milliseconds old—the drone has already moved. If the EKF fuses that "old" data with "new" IMU data, the math becomes inconsistent, leading to vertical oscillations.

`EK3_HGT_DELAY` allows the EKF to reach back into its "memory buffer" and compare the Baro data against exactly what the drone was doing 60ms ago. This alignment is critical for a rock-solid, jitter-free altitude hold.

*   **Default (60ms):** Optimized for standard MS5611 barometers.
*   **Too Low:** The drone may oscillate vertically at high frequency (vibrate).
*   **Too High:** The drone will be slow to respond to altitude changes and may "bounce" when stopping a climb.

## The Mathematics
The EKF maintains a history of its internal states. When a height measurement ($z_{alt}$) arrives at time $t$, the EKF doesn't compare it to the current state $\hat{x}(t)$. Instead, it looks up the state from $t - \text{DELAY}$:

$$ y_{alt} = z_{alt}(t) - H \cdot \hat{x}(t - \text{EK3\_HGT\_DELAY}) $$

Where $y_{alt}$ is the Innovation (error) used to correct the filter. This ensures that the sensor data is always fused with the IMU state that produced it.

## The Engineer's View
This parameter is the `_hgtDelay_ms` member in `NavEKF3`.

It is particularly important when using **External Rangefinders** over I2C or Serial. These sensors have their own internal filtering and communication latency. If your Lidar has a 100ms latency, but `EK3_HGT_DELAY` is only 60ms, the EKF will experience vertical "ringing" because its corrections are based on incorrect time-alignments.

## Tuning & Behavior
*   **Default Value:** 60 ms
*   **Range:** 0 - 250 ms
*   **Effect of Increasing:** The drone trusts older data. Better for sensors with heavy internal filtering (slow Lidars).
*   **Effect of Decreasing:** The drone expects faster data. Better for high-speed SPI barometers.

### Use Case Recommendations
*   **Standard Pixhawk / Cube:** **Keep at 60.** The internal Baro drivers are well-matched to this value.
*   **Cheap Chinese Lidars (VL53L1X, etc.):** **Increase to 100.** These sensors have significant communication lag over I2C.
*   **High-Speed SPI Baro (BMP388/SPL06):** **Decrease to 20.** Faster communication allows for a tighter altitude control loop.

### Troubleshooting
*   **Scenario:** Drone bobs up and down rhythmically (about 2-3 times per second) specifically when using a new Rangefinder.
    *   **Diagnosis:** Height sensor delay mismatch. The EKF is comparing current height to past movements incorrectly.
    *   **Fix:** Increase `EK3_HGT_DELAY` by 20ms increments until the bobbing stops.