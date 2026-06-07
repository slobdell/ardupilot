# Leak Detector Configuration (LEAK)

## Overview
The **LEAK** parameter group configures the **Leak Detection** system for **ArduSub** (ROVs).

Water ingress is the primary failure mode for underwater vehicles. This system monitors up to 3 physical leak sensors and triggers a failsafe alert (and optionally an autonomous surfacing maneuver) if water is detected.

## Key Concepts

### 1. Sensor Logic
*   **`LEAKn_TYPE`**: 1=Digital (Pin high/low).
*   **`LEAKn_LOGIC`**: Defines if "Wet" is High (3.3V) or Low (0V).
*   **`LEAKn_PIN`**: The GPIO pin on the flight controller connected to the sensor.

## Integration Guide
1.  **Hardware:** Place leak probes at the lowest point of the electronics enclosure.
2.  **Config:** Set the pin and logic based on your sensor (e.g., BlueRobotics SOS probe).
3.  **Failsafe:** Configure the GCS to alert the pilot immediately on a leak trigger.

## Developer Notes
*   **Library:** `libraries/AP_LeakDetector`.
*   **Context:** Only relevant for **ArduSub**.