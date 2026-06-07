---
layout: parameter
title: TERRAIN_ENABLE
name: Terrain data enable
group: TERRAIN
---

# TERRAIN_ENABLE: Terrain data enable

## Description
Enable terrain data.

## Values
| Value | Meaning |
| :--- | :--- |
| 0 | Disabled |
| 1 | Enabled |

- **Default:** 1

## Description
This parameter enables the autopilot to download, store, and use digital elevation maps (DEM) for Terrain Following.

- **Function:** When enabled, the drone will request terrain data tiles from the Ground Control Station (Mission Planner or QGroundControl) or download them from the internet if the companion computer has access. These tiles are stored on the SD card.
- **Usage:** Essential for safe low-altitude flight over hills and mountains. Without this data, the drone assumes the world is flat at Home altitude (unless using a rangefinder).

