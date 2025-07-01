// Stub providing QuadPlane::_singleton for non-ArduPlane builds.
// AP_Motors6DOF.cpp calls QuadPlane::get_singleton() to read a tilt rate
// limit, gracefully handling nullptr by falling back to a default of 40 dps.
// This stub satisfies the linker without pulling in ArduPlane's quadplane.cpp.

#include <AP_Vehicle/AP_Vehicle_Type.h>

#if !APM_BUILD_TYPE(APM_BUILD_ArduPlane)
#include <../ArduPlane/quadplane.h>
QuadPlane *QuadPlane::_singleton = nullptr;
#endif
