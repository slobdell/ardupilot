#pragma once
// Minimal stub for AP_HAL — provides only what the mixer .cpp files call:
//   AP_HAL::micros()  — used in copter mode to timestamp TVC_Inputs
//   AP_HAL::millis()  — used inside AVATAR_DEBUG_LOG blocks (disabled in tests)
#include <stdint.h>

namespace AP_HAL {
    inline uint64_t micros() { return 1000000ULL; } // fixed 1s — deterministic tests
    inline uint32_t millis() { return 1000U; }
}
