---
layout: parameter
name: TERRAIN_CACHE_SZ
display_name: Terrain Cache Size
description: The number of terrain data blocks to keep in the flight controller's RAM.
default_value: 0
range: 0 128
units: blocks
group: TERRAIN
visual_asset_id: terrain_diagram
investigation_status: complete
source_code_urls:
  - https://github.com/ArduPilot/ardupilot/blob/master/libraries/AP_Terrain/AP_Terrain.cpp#L86
---

# Terrain Cache Size (TERRAIN_CACHE_SZ)

## Description
`TERRAIN_CACHE_SZ` allocates memory for the terrain map.

The autopilot cannot hold the entire world's map in memory. Instead, it reads small "blocks" (tiles) from the SD card as needed. This parameter determines how many of these blocks can be kept in RAM at once for fast access.

*   **0 (Default):** Use the board-specific default (usually scaled to available RAM).
*   **Value:** Number of blocks (each block is approx. 2KB).

## Tuning & Behavior
*   **Default:** 0.
*   **Recommendation:** Leave at **0**.
*   **Significance:** If you fly very fast over varied terrain, a larger cache might prevent "Data Starvation" where the autopilot is waiting for the SD card to load the next hill.