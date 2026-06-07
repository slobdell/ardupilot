# Battery Cell Count (NUM)

## Overview
The **NUM** parameter group (specifically `NUM_CELLS` or `BATT_BAL_NUM_CELLS`) configures the cell count for high-precision **Battery Balance** monitoring.

## Key Concepts

### 1. Cell Count
When using a smart battery or a power module that monitors individual cell voltages (via a balance lead), the autopilot needs to know how many cells are in series.
*   **`NUM_CELLS`**: The integer number of cells (e.g., 4 for a 4S LiPo).

## Developer Notes
*   **Library:** `libraries/AP_BattMonitor`.
*   **Context:** Only relevant if your power module supports per-cell monitoring.