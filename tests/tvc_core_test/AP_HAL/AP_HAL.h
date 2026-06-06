#pragma once
// Minimal stub satisfying the AP_HAL include used by TVC_Filters::dumpParams().
// That method checks for nullptr before use, so returning nullptr from get_serial_by_id
// makes the entire dumpParams() body a no-op during testing.
#include <stdint.h>
#include <stdarg.h>

namespace AP_HAL {
    class UARTDriver {
    public:
        virtual void printf(const char*, ...) {}
    };
}

namespace AP {
    class SerialManager {
    public:
        AP_HAL::UARTDriver* get_serial_by_id(int) { return nullptr; }
    };
    inline SerialManager& serialmanager() {
        static SerialManager sm;
        return sm;
    }
}
